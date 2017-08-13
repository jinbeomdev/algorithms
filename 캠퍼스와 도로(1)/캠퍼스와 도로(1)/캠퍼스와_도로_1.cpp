#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

vector<int> Answer;
int adj[1001][1001];

inline int min(int a, int b) { return (((a) < (b)) ? (a) : (b)); }

int main(int argc, char** argv)
{
	int T, test_case;
	
	cin >> T;

	for (test_case = 0; test_case < T; test_case++)
	{
		int Answer_cnt;
		int N, M;

		cin >> N >> M;

		Answer = vector<int>(N + 1, 0);
		Answer_cnt = N;

		for (int i = 1; i < N + 1; i++) {
			Answer[i] = i;
		}

		memset(adj, 1, sizeof(adj));

		for (int i = 0; i < M; i++) {
			int from, to, len;

			cin >> from >> to >> len;

			adj[from][to] = len;
			adj[to][from] = len;
		}

		for (int i = 1; i < N + 1; i++) {
			adj[i][i] = 0;
		}

		for (int k = 1; k < N + 1; k++) {
			for (int i = 1; i < N + 1; i++) {
				for (int j = 1; j < N + 1; j++) {
					if (adj[i][j] > adj[i][k] + adj[k][j]) {
						adj[i][j] = adj[i][k] + adj[k][j];

						if (Answer[k] != 0) {
							Answer[k] = 0;
							Answer_cnt = Answer_cnt - 1;
						}
					}
				}
			}
		}

		cout << "Case #" << test_case + 1 << endl;
		cout << Answer_cnt << " ";
		for (int i = 1; i < N+1; i++) {
			if(Answer[i] > 0)
				cout << Answer[i] << " ";
		} cout << endl;
	}

	return 0;
}