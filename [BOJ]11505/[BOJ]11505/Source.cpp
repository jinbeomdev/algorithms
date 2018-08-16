#include <cstdio>
#include <vector>

using namespace std;

const int MOD = 1000000007;

class ST { //segment tree
public:
	//�迭�� ũ��
	int n;
	//������ �� ���ϱ�
	vector<long long int> rangeMul;

	ST(const vector<int>& a) {
		n = a.size();
		rangeMul.resize(n * 4);
		init(a, 0, n - 1, 1);
	}

	long long int init(const vector<int>& a, int left, int right, int node) {
		if (left == right) return rangeMul[node] = a[left];
		int mid = (left + right) / 2;
		long long int leftMul = init(a, left, mid, node * 2);
		long long int rightMul = init(a, mid+1, right, node * 2 + 1);
		return rangeMul[node] = (leftMul * rightMul) % MOD;
	}

	long long int query(int left, int right, int node, int nodeLeft, int nodeRight) {
		//�� ������ ��ġ�� ������ 1�� ��ȯ�Ѵ�.
		if (right < nodeLeft || nodeRight < left) return 1;
		//node�� ǥ���ϴ� ������ array[left..right]�� ������ ���ԵǴ� ���
		if (left <= nodeLeft && nodeRight <= right) return rangeMul[node];
		//���� ������ ������ Ǭ �� ����� ��ģ��.
		int mid = (nodeLeft + nodeRight) / 2;
		return (query(left, right, node * 2, nodeLeft, mid) *
			query(left, right, node * 2 + 1, mid + 1, nodeRight)) % MOD;
	}

	int query(int left, int right) {
		return query(left, right, 1, 0, n - 1);
	}

	//array[index] = newValue�� �ٲ���� �� node�� ��Ʈ�� �ϴ�
	//���� Ʈ���� �����ϰ� ��尡 ǥ���ϴ� �ּ�ġ�� ��ȯ�Ѵ�.
	long long int update(int index, int newValue, int node, int nodeLeft, int nodeRight) {
		//index�� ��尡 ǥ���ϴ� ������ ������� ��� ����
		if (index < nodeLeft || nodeRight < index) return rangeMul[node];
		if (nodeLeft == nodeRight) return rangeMul[node] = newValue;
		int mid = (nodeLeft + nodeRight) / 2;
		return rangeMul[node] = (update(index, newValue, node * 2, nodeLeft, mid) *
			update(index, newValue, node * 2 + 1, mid + 1, nodeRight)) % MOD;
	}
};

int main() {
	int N, M, K;
	vector<int> arr;
	scanf("%d%d%d", &N, &M, &K);
	for (int i = 0; i < N; i++) {
		int input;
		scanf("%d", &input);
		arr.push_back(input);
	}

	ST st(arr);

	for (int i = 0; i < M + K; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		b--;
		if (a == 1) {
			st.update(b, c, 1, 0, arr.size() - 1);
		} else if (a == 2) {
			c--;
			printf("%d\n", st.query(b, c));
		}
	}
}