#include <iostream>
#include <queue>

using namespace std;

int main() {
	int meetings;
	int answer;
	//(끝나는 시간, 시작 시간)
	priority_queue<pair<int, int>> pq;

		cin >> meetings;

		answer = 0;
		pq = priority_queue<pair<int, int>>();
		
		for (int i = 0; i < meetings; i++) {
			int start, end;

			cin >> start >> end;
			pq.push(make_pair(-end, start));
		}

		int preEnd = -pq.top().first;
		int preStart = pq.top().second;
		answer++;

		for (int i = 1; i <= meetings; i++) {
			int endTime = -pq.top().first;
			int startTime = pq.top().second;
			pq.pop();

			if (startTime >= preEnd) {
				answer++;
				preEnd = endTime;
				preStart = startTime;
			}
		}

		cout << answer;
}