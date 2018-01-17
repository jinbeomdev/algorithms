//https://www.acmicpc.net/problem/1238

/*
문제
N개의 숫자로 구분된 각각의 마을에 한 명의 학생이 살고 있다.

어느 날 이 N명의 학생이 X (1 ≤ X ≤ N)번 마을에 모여서 파티를 벌이기로 했다. 이 마을 사이에는 총 M개의 단방향 도로들이 있고 i번째 길을 지나는데 Ti(1 ≤ Ti ≤ 100)의 시간을 소비한다.

각각의 학생들은 파티에 참석하기 위해 걸어가서 다시 그들의 마을로 돌아와야 한다. 하지만 이 학생들은 워낙 게을러서 최단 시간에 오고 가기를 원한다.

이 도로들은 단방향이기 때문에 아마 그들이 오고 가는 길이 다를지도 모른다. N명의 학생들 중 오고 가는데 가장 많은 시간을 소비하는 학생은 누구일지 구하여라.

입력
첫째 줄에 N(1 <= N <= 1,000), M(1 <= M <= 10,000), X가 공백으로 구분되어 입력된다. 두 번째 줄부터 M+1번째 줄까지 i번째 도로의 시작점, 끝점, 그리고 이 도로를 지나는데 필요한 소요시간 Ti가 들어온다.

모든 학생들은 집에서 X에 갈수 있고, X에서 집으로 돌아올 수 있는 데이터만 입력으로 주어진다.

출력
첫 번째 줄에 N명의 학생들 중 오고 가는데 가장 오래 걸리는 학생의 소요시간을 출력한다.

예제 입력  복사
4 8 2
1 2 4
1 3 2
1 4 7
2 1 1
2 3 5
3 1 2
3 4 4
4 2 3
예제 출력  복사
10
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 10e9;

int main() {
	int N, M, X;
	vector<vector<pair<int, long long int>>> adj;
	vector<vector<long long int>> dist;
	priority_queue<pair<int, long long int>> pq;

	cin >> N >> M >> X;

	adj = vector<vector<pair<int, long long int>>>(N + 1);
	dist = vector<vector<long long int>>(N + 1, vector<long long int>(N + 1, INF));

	for (int i = 0; i < M; i++) {
		int from, to, cost;

		cin >> from >> to >> cost;

		adj[from].push_back({ to, cost });
	}
	for (int i = 1; i <= N; i++) {		
		pq.push({ i, 0 });

		while(!pq.empty()) {
			int here = pq.top().first;
			long long int cost = -pq.top().second;
			pq.pop();

			if (dist[i][here] < cost) continue;

			for (int j = 0; j < adj[here].size(); j++) {
				int there = adj[here][j].first;
				long long int next_cost = cost + adj[here][j].second;

				if (dist[i][there] > next_cost) {
					dist[i][there] = next_cost;
					pq.push({ there, -next_cost });
				}
			}
		}
	}

	long long int answer = 0;
	for (int i = 1; i <= N; i++) {
		if (i == X) continue;
		if (answer < dist[i][X] + dist[X][i] &&
			dist[i][X] < INF && dist[X][i] < INF) {
			answer = dist[i][X] + dist[X][i];
		}
	}

	cout << answer;
}