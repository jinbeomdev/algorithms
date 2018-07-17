#include <cstdio>
#include <queue>
#include <functional>

using namespace std;

int N;
priority_queue<int, vector<int>, greater<int>> min_heap;
priority_queue<int, vector<int>, less<int>> max_heap;

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int input;
		
		scanf("%d", &input);

		if (max_heap.empty()) {
			max_heap.push(input);
		} else if (max_heap.size() == min_heap.size()) {
			max_heap.push(input);
		} else {
			min_heap.push(input);
		}

		if (!max_heap.empty() &&
				!min_heap.empty() &&
				!(max_heap.top() <= min_heap.top())) {
			int max = max_heap.top();
			int min = min_heap.top();
			max_heap.pop();
			min_heap.pop();
			max_heap.push(min);
			min_heap.push(max);
		}

		printf("%d\n", max_heap.top());
	}
}