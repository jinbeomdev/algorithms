//3665번: 최종 순위
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	int T, test_case;

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int N, M;
		vector<int> teams;
		vector<vector<int>> adj;
		vector<int> indegree;
		vector<int> order;
		queue<int> q;
		//state : 0(정상) 1(?) 2(IMPOSSIBLE)
		int state = 0;

		cin >> N;

		teams = vector<int>(N + 1, 0);
		adj = vector<vector<int>>(N + 1, vector<int>(N + 1, 0));
		indegree = vector<int>(N + 1, 0);
		order = vector<int>(N + 1, 0);

		for (int i = 1; i <= N; i++) {
			cin >> teams[i];
		}

		for (int i = 1; i <= N; i++) {
			for (int j = i + 1; j <= N; j++) {
				adj[teams[j]][teams[i]] = 1;
				indegree[teams[i]]++;
			}
		}

		cin >> M;

		for (int i = 0; i < M; i++) {
			int from, to;

			cin >> to >> from;

			if (adj[to][from]) {
				indegree[from]--;
				indegree[to]++;
			}
			else {
				indegree[from]++;
				indegree[to]--;
			}

			swap(adj[to][from], adj[from][to]);
		}

		for (int i = 1; i <= N; i++) {
			if (!indegree[i]) q.push(i);
		}


		for (int i = 1; i <= N; i++) {
			if (q.empty()) {
				state = 2; //사이클이 생긴 경우. IMPOSSIBLE
				break;
			}

			if (q.size() > 1) {
				state = 1; //순서를 결정할 수 없는 경우. ?
			}

			int team;
			team = q.front();
			order[i] = team;
			q.pop();

			for (int i = 1; i <= N; i++) {
				if (adj[team][i]) {
					adj[team][i] = 0;
					indegree[i]--;
					
					if (!indegree[i]) {
						q.push(i);
					}
				}
			}
		}

		if (state == 0) {
			reverse(order.begin() + 1, order.end());

			for (int i = 1; i <= N; i++) {
				cout << order[i] << " ";
			} cout << endl;
		}
		else if (state == 1) {
			cout << "?" << endl;
		}
		else if (state == 2) {
			cout << "IMPOSSIBLE" << endl;
		}
	}//test_case for문 종료
}//main() 함수 종료