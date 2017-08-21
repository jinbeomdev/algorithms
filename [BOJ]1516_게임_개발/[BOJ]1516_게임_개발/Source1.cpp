//1516번: 게임 개발
//dfs로 접근하니깐 종속이 없는 경우에 건물을 동시에 짓는다는 것을 처리하지 못해서
//이번에는 queue로 접근 해보려고 함

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int N;
	vector<int> buildTime;
	vector<vector<int>> adj;
	vector<int> indegree;
	queue<int> q;
	vector<int> order;
	int Answer = 0;
	bool flag = 0; //0이면 동시에 지을 수 있는 건물이 없는 경우
					//1이면 동시에 지을 수 있는 건물이 있는 경우

	cin >> N;

	buildTime = vector<int>(N + 1);
	adj = vector<vector<int>>(N + 1);
	indegree = vector<int>(N + 1);

	for (int i = 1; i < N + 1; i++) {
		int vertex;

		cin >> buildTime[i];

		while (true) {
			cin >> vertex;

			if (vertex == -1) break;

			adj[vertex].push_back(i);
			indegree[i]++;
		}
	}

	for (int i = 1; i < N + 1; i++) {
		if (!indegree[i]) q.push(i);
	}

	for (int i = 1; i < N; i++) {
		if (q.size() > 1) {
			flag = 1;
		}
		else {
			flag = 0;
		}

		int build = q.front();
		q.pop();

		for (int i = 0; i < adj[build].size(); i++) {
			indegree[adj[build][i]]--;
			
			if (!indegree[adj[build][i]]) q.push(adj[build][i]);
		}

		if(flag == 0)
			Answer += buildTime[build];
	}

	cout << Answer;
}