//https://www.acmicpc.net/problem/9576

/*
����
�����̴� �� û�Ҹ� �ϸ鼭 �ʿ� ���� ���� ������ ����鿡�� �����ַ��� �Ѵ�. ������ å�� ��ƺ��� �� N���̾���. å�� �ʹ� ���� ������ �����̴� å�� �����ϱ� ���� ���� 1���� N������ ���� ��ȣ�� �ߺ����� �ʰ� �Ű� �ξ���.

���縦 �� ���� å�� ���ϴ� �������б� �кλ��� �� M���̾���. �����̴� �� M���� ��û���� �� ���� a, b (1 �� a �� b �� N)�� ���� ����� �ߴ�. �׷��� �����̴� å ��ȣ�� a �̻� b ������ å �� �����ִ� å �� ���� ��� �� �л����� �ش�. ���� a������ b�������� ��� å�� �̹� �ٸ� �л����� �ְ� ���ٸ� �� �л����Դ� å�� ���� �ʴ´�.

�����̰� å�� �� �� �ִ� �ִ� �л� ���� ���Ͻÿ�.

�Է�
ù° �ٿ� �׽�Ʈ ���̽��� ���� �־�����.

�� ���̽��� ù �ٿ� ���� N(1 �� N �� 1,000)�� M(1 �� M �� 1,000)�� �־�����. ���� �ٺ��� M���� �ٿ��� ���� ���� ai, bi�� �־�����. (1 �� ai �� bi �� N)

���
�����̰� å�� �� �� �ִ� �ִ� �л� ���� ����Ѵ�.

���� �Է�  ����
1
2 3
1 2
1 2
1 2
���� ���  ����
2
*/

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int A[1001], B[1001];
int T, test_case;
int N, M;
vector<vector<int>> adj;
bool visited[1001];

int dfs(int a) {
	visited[a] = true;

	for (int b : adj[a]) {
		if (B[b] == -1 || !visited[B[b]] && dfs(B[b])) {
			A[a] = b;
			B[b] = a;
			return true;
		}
	}
	return false;
}

int main() {

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		adj = vector<vector<int>>(1001);

		cin >> N >> M;

		for (int i = 1; i <= M; i++) {
			int a, b;

			cin >> a >> b;

			for (int j = a; j <= b; j++) {
				adj[j].push_back(i);
			}
		}

		int match = 0;

		memset(A, -1, sizeof(A));
		memset(B, -1, sizeof(B));

		for (int i = 1; i <= N; i++) {
			if (A[i] == -1) {
				memset(visited, false, sizeof(visited));
				if (dfs(i)) match++;
			}
		}

		cout << match << "\n";
	}
	//system("pause");
}