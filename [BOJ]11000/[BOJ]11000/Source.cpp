#include <stdio.h>

#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

pair<int, int> arr[200000];

int main() {
	int N;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int s, t;
		scanf("%d%d", &arr[i].first, &arr[i].second);
	}

	sort(arr, arr + N);

	priority_queue<pair<int ,int>> pq;
	pq.push(make_pair(-arr[0].second, arr[0].first));
	
	for (int i = 1; i < N; i++) {
		int t = -pq.top().first;
		int s = pq.top().second;

		if (t <= arr[i].first) {
			pq.pop();
		}
		
		pq.push(make_pair(-arr[i].second, arr[i].first));
	}

	printf("%d", pq.size());
}