//11003: 최소값 찾기
#include <cstdlib>
#include <algorithm>
#include <deque>

using namespace std;

int main() {
	int N, L, X;
	deque<pair<int, int>> dq;
	scanf("%d%d", &N, &L);
	for (int i = 0; i < N; i++) {
		while (dq.size() && dq.front().second < i - L + 1) dq.pop_front();
		scanf("%d", &X);
		while (dq.size() && dq.back().first > X) dq.pop_back();
		dq.push_back({ X, i });
		printf("%d ", dq.front().first);
	}
}