#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int Answer;
//�������� ��ġ�� ��Ÿ���� ���� M, N(1<= M, N <= 100)
//ö���� �ּҷ� �Ƿ�� �ϴ� �������� ���� K(0 <= K <= 10)
int M, N, K;
int dp[100][100][11];
int adj[100][100];
int X[] = { 0, 1 };
int Y[] = { 1, 0 };

int main(int argc, char** argv)
{
	int T, test_case;

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		Answer = 0;

		memset(dp, -1, sizeof(adj));


		//M�� ���ΰ� N�� ����
		cin >> M >> N >> K;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> adj[i][j];
			}
		}

		for (int i = 0; i < N - 1; i++) {
			for (int j = 0; j < M - 1; j++) {
				for (int k = 0; k <= 11; k++) {
					adj[i][j][k] = __min(adj[i - 1][j][k])
				}
			}
		}

		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;
}