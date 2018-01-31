//https://www.acmicpc.net/problem/2188

/*
����
��� John���� ���� �� ��縦 �� �ϼ��Ͽ���. ��� ȯ���� �����ϰ� �����ϱ� ���ؼ�, John���� ��縦 N���� ĭ���� �����Ͽ� �ΰ�, �� ĭ���� �� ������ �Ҹ��� ������ �Ͽ���.

ù �ֿ��� �ҵ��� ���������� ĭ�� �����Ͽ� ��縦 ��Ͽ�����, �� ������ �߻��ϰ� �Ǿ���. �ڽŵ��� ����ϴ� �� ���� ��� �ܿ��� ���⸦ �ź��ϴ� ���̴�.

��� John���� ���� �ִ��� ���� ���� �Ұ� ��翡 �� �� �ֵ��� �ϴ� ���α׷��� �ۼ��Ͻÿ�. ����� ��ȣ�� 1���� M���� �Ű��� �ִٰ� �Ѵ�.

�Է�
ù° �ٿ� ���� ������ N�� ����� ���� M�� �־�����. (1<=N<=200, 1<=M<=200)

��° �ٺ��� N���� �ٿ��� N������ �ҵ��� ���� ���� ���ϴ� ��翡 ���� ������ �־�����. i��° �Ұ� ���� ���ϴ� ����� �� Si(0<=Si<=M)�� ���� �־�����, �� ���Ŀ� Si���� ��� ��ȣ�� �־�����. �� ��簡 2�� �̻� �ԷµǴ� ���� ����.

���
ù° �ٿ� ��翡 �� �� �ִ� �� �������� �ִ밪�� ����Ѵ�.

���� �Է�  ����
5 5
2 2 5
3 2 3 4
2 1 5
3 1 2 5
1 2
���� ���  ����
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