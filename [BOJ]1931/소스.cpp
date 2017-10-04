//1931: 회의실 배정

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N;
	vector<pair<int, int>> meetings;
	int answer = 1;

	cin >> N;

	meetings = vector<pair<int, int>>(N);

	for (int i = 0; i < N; i++) {
		int startTime, endTime;

		cin >> startTime >> endTime;

		meetings[i] = { endTime, startTime };
	}

	sort(meetings.begin(), meetings.end());

	int meetingStartTime = meetings[0].second;
	int meetingEndTime = meetings[0].first;

	for (int i = 1; i < N; i++) {
		if (meetingEndTime <= meetings[i].second) {
			meetingStartTime = meetings[i].second;
			meetingEndTime = meetings[i].first;
			answer++;
		}
	}

	cout << answer;

	return 0;
}