#include <cstdio>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

const int MAX = numeric_limits<int>::max();

class ST { //segment tree
public:
	ST(const vector<int>& a) {
		n_ = a.size();
		range_.resize(n_ * 4);
		init(a, 0, n_ - 1, 1);
	}

	int init(const vector<int>& a, int left, int right, int node) {
		if (left == right) return range_[node] = a[left];
		int mid = (left + right) / 2;
		int leftValue = init(a, left, mid, node * 2);
		int rightValue = init(a, mid + 1, right, node * 2 + 1);
		return range_[node] = min(leftValue, rightValue);
	}

	int query(int left, int right, int node, int nodeLeft, int nodeRight) {
		if (right < nodeLeft || nodeRight < left) return MAX;
		if (left <= nodeLeft && nodeRight <= right) return range_[node];
		int mid = (nodeLeft + nodeRight) / 2;
		return min(query(left, right, node * 2, nodeLeft, mid), query(left, right, node * 2 + 1, mid + 1, nodeRight));
	}

	int query(int left, int right) {
		return query(left, right, 1, 0, n_ - 1);
	}

private:
	int n_;
	vector<int> range_;
};

int main() {
	int N, M;
	vector<int> min_arr;
	vector<int> max_arr;

	scanf("%d%d", &N, &M);

	for (int i = 0; i < N; i++) {
		int input;
		scanf("%d", &input);

		min_arr.push_back(input);
		max_arr.push_back(-input);
	}

	ST min_st(min_arr);
	ST max_st(max_arr);

	for (int i = 0; i < M; i++) {
		int from, to;
		scanf("%d%d", &from, &to);
		int min_answer = min_st.query(from - 1, to - 1);
		int max_answer = -max_st.query(from - 1, to - 1);
		printf("%d %d\n", min_answer, max_answer);
	}

}