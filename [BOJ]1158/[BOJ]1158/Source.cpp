#include <cstdio>
#include <queue>

int N, M;
using namespace std;

int main() {
	scanf("%d%d", &N, &M);

	vector<int> answer;
	queue<int> q;
	for (int i = 1; i <= N; i++) {
		q.push(i);
	}

	while (!q.empty()) {
		for (int i = 0; i < M - 1; i++) {
			int hold = q.front();
			q.pop();
			q.push(hold);
		}
		answer.push_back(q.front());
		q.pop();
	}

	for (int i = 0; i < answer.size(); i++) {
		if (i == 0) putc('<', stdout);
		if (i == answer.size() - 1) {
			printf("%d>", answer[i]);
		} else {
			printf("%d, ", answer[i]);
		}
	}
}