#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

class Comp {
public:
	bool operator() (pair<int, int> a, pair<int, int> b) {
		if (a.first == b.first) {
			return a.second > b.second;
		}

		return a.first > b.first;
	}
};

int main() {
	priority_queue<pair<int, int>, vector<pair<int, int>>, Comp> pq;
	int N;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int oper;

		scanf("%d", &oper);

		if (oper != 0) {
			pq.push(make_pair(abs(oper), oper));
		} else if (pq.empty()) {
			printf("%d\n", 0);
		} else {
			printf("%d\n", pq.top().second);
			pq.pop();
		}
	}
}