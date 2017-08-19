//1766번: 문제집
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int N, M;
	vector<vector<int>> adj;
	vector<int> indegree;
	priority_queue<int> pq;
	vector<int> order;
	
	cin >> N >> M;

	adj = vector<vector<int>>(N + 1);
	indegree = vector<int>(N + 1, 0);

	for (int i = 0; i < M; i++) {
		//A번 문제는 B번 문제보다 먼저 푸는 것이 좋다는 의미
		int A, B;

		cin >> A >> B;

		adj[A].push_back(B);
		indegree[B]++;
	}

	for (int i = 1; i < N + 1; i++) {
		if (!indegree[i]) pq.push(-i); //min heap
	}

	for (int i = 1; i < N + 1; i++) {
		int problem = -pq.top();
		pq.pop();

		for (int i = 0; i < adj[problem].size(); i++) {
			indegree[adj[problem][i]]--;

			if (!indegree[adj[problem][i]]) pq.push(-adj[problem][i]);
		}

		order.push_back(problem);
	}

	for (int i = 0; i < order.size(); i++) {
		cout << order[i] << " ";
	}
}