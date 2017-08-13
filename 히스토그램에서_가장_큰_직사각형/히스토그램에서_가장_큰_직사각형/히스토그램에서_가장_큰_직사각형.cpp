#include <iostream>
#include <vector>
using namespace std;

//#define max(a,b) (((a) > (b)) ? (a) : (b))
//#define min(a,b) (((a) < (b)) ? (a) : (b))

inline long long int max(long long int a, long long int b) { return (((a) > (b)) ? (a) : (b)); }
inline long long int min(long long int a, long long int b) { return (((a) < (b)) ? (a) : (b)); }

//������׷�
vector<long long int> histogram;
//��
vector<long long int> Answer;

int biggest_extent(int left, int right) {
	//base case : bottoms out �� ��쿡 �� ���̸� ��ȯ(�ʺ� 1�̱� ������ 1 * ���� = ����
	if (left == right) return histogram[left];

	//�߰� ��
	int mid = (left + right) / 2;
	//���� �ɰ���
	long long int ret = max(biggest_extent(left, mid), biggest_extent(mid + 1, right));
	int lo = mid;
	int hi = mid + 1;
	long long int height = min(histogram[lo], histogram[hi]);

	ret = max(ret, height * 2);

	while (left < lo || hi > right) {
		if (hi < right && (lo == left || histogram[lo - 1] <= histogram[hi + 1])) {
			hi++;
			height = min(height, histogram[hi]);
		}
		else {
			lo--;
			height = min(height, histogram[lo]);
		}
		ret = max(ret, height * (hi - lo + 1));
	}
	return ret;
}

int main() {
	//���簢���� ��
	int N = -1;
	int left, right;

	while (true) {
		cin >> N;

		if (N == 0) break;

		histogram = vector<long long int>(N, 0);

		for (int i = 0; i < N; i++) {
			cin >> histogram[i];
		}

		left = 0;
		right = N - 1;

		Answer.push_back(biggest_extent(0, N - 1));
	}

	for (vector<long long int>::iterator it = Answer.begin(); it != Answer.end(); it++) {
		cout << *it << endl;
	}
}