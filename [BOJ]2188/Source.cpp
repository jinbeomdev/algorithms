//https://www.acmicpc.net/problem/2188

/*
문제
농부 John씨는 그의 소 축사를 갓 완성하였다. 축사 환경을 쾌적하게 유지하기 위해서, John씨는 축사를 N개의 칸으로 구분하여 두고, 한 칸에는 한 마리의 소만을 들어가도록 하였다.

첫 주에는 소들을 임의적으로 칸에 배정하여 축사를 운영하였으나, 곧 문제가 발생하게 되었다. 자신들이 희망하는 몇 개의 축사 외에는 들어가기를 거부하는 것이다.

농부 John씨를 도와 최대한 많은 수의 소가 축사에 들어갈 수 있도록 하는 프로그램을 작성하시오. 축사의 번호는 1부터 M까지 매겨져 있다고 한다.

입력
첫째 줄에 소의 마릿수 N과 축사의 개수 M이 주어진다. (1<=N<=200, 1<=M<=200)

둘째 줄부터 N개의 줄에는 N마리의 소들이 각자 들어가기 원하는 축사에 대한 정보가 주어진다. i번째 소가 들어가기 원하는 축사의 수 Si(0<=Si<=M)가 먼저 주어지고, 그 이후에 Si개의 축사 번호가 주어진다. 한 축사가 2번 이상 입력되는 경우는 없다.

출력
첫째 줄에 축사에 들어갈 수 있는 소 마릿수의 최대값을 출력한다.

예제 입력  복사
5 5
2 2 5
3 2 3 4
2 1 5
3 1 2 5
1 2
예제 출력  복사
4
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int N, M;

	cin >> N >> M;

	int arr_size = N + M + 2;

	vector<vector<int>> C = vector<vector<int>>(arr_size, vector<int>(arr_size, 0));
	vector<vector<int>> F = vector<vector<int>>(arr_size, vector<int>(arr_size, 0));
	vector<vector<int>> adj = vector<vector<int>>(arr_size);

	int S = arr_size - 2;
	int E = arr_size - 1;

	for (int i = 0; i < N; i++) {
		int j;

		cin >> j;

		for (int k = 0; k < j; k++) {
			int s;

			cin >> s;

			s = N + s - 1;
			C[i][s] = 1;
			adj[i].push_back(s);
			adj[s].push_back(i);
		}
		C[S][i] = 1;
		adj[S].push_back(i);
		adj[i].push_back(S);
	}

	for (int i = N; i < arr_size - 2; i++) {
		C[i][E] = 1;
		adj[i].push_back(E);
		adj[E].push_back(i);
	}

	int result = 0;
	while (1) {
		queue<int> q;
		vector<int> prev = vector<int>(arr_size, -1);
		q.push(S);

		while (!q.empty()) {
			int here = q.front();
			q.pop();

			for (int i = 0; i < adj[here].size(); i++) {
				int there = adj[here][i];

				if (C[here][there] - F[here][there] > 0 && prev[there] == -1) {
					prev[there] = here;
					q.push(there);

					if (there == E) break;
				}
			}
		}

		if (prev[E] == -1) break;

		for (int i = E; i != S; i = prev[i]) {
			F[prev[i]][i]++;
			F[i][prev[i]]--;
		}
		result++;
	}
	cout << result;
	system("pause");
}