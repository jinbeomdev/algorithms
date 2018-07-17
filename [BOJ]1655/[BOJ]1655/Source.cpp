#include <cstdio>
#include <queue>

using namespace std;

int N;
priority_queue<int> pq;
priority_queue<int> temp;

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int input;

		scanf("%d", &input);

		pq.push(-input);

		int pq_size = pq.size();
		
		if (pq_size % 2 == 0) {
			pq_size = pq_size / 2 - 1;
		} else {
			pq_size = pq_size / 2;
		}

		for (int j = 0; j < pq_size; j++) {
			temp.push(-pq.top());
			pq.pop();
		}

		printf("%d\n", -pq.top());

		while (!temp.empty()) {
			pq.push(-temp.top());
			temp.pop();
		}
	}
}

/*
	순회하는 heap 내가 만들어야 할듯?
*/