#include <string>
#include <vector>
#include <queue>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	priority_queue<string> participant_pq;
	priority_queue<string> completion_pq;

	vector<string>::iterator pi=  participant.begin();
	vector<string>::iterator ci = completion.begin();

	while (ci != completion.end()) {
		participant_pq.push(*pi++);
		completion_pq.push(*ci++);
	}

	participant_pq.push(*pi++);

	while (!completion_pq.empty()) {
		if (completion_pq.top() != participant_pq.top()) {
			return participant_pq.top();
		}

		completion_pq.pop();
		participant_pq.pop();
	}

	return participant_pq.top();
}