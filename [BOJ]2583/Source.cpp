//https://www.acmicpc.net/problem/2583

/*
����
������ ������ 1�� M��N(M,N��100)ũ���� �����̰� �ִ�. �� ������ ���� ���ݿ� ���߾� K���� ���簢���� �׸� ��, �̵� K���� ���簢���� ���θ� ������ ������ �κ��� �� ���� �и��� �������� ����������.

���� ��� M=5, N=7 �� ������ ���� <�׸� 1>�� ���� ���簢�� 3���� �׷ȴٸ�, �� ������ ������ <�׸� 2>�� ���� 3���� �и��� �������� ���������� �ȴ�.



<�׸� 2>�� ���� �и��� �� ������ ���̴� ���� 1, 7, 13�� �ȴ�.

M, N�� K �׸��� K���� ���簢���� ��ǥ�� �־��� ��, K���� ���簢�� ���θ� ������ ������ �κ��� �� ���� �и��� �������� ������������, �׸��� �и��� �� ������ ���̰� �������� ���Ͽ� �̸� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� M�� N, �׸��� K�� ��ĭ�� ���̿� �ΰ� ���ʷ� �־�����. M, N, K�� ��� 100 ������ �ڿ����̴�. ��° �ٺ��� K���� �ٿ��� �� �ٿ� �ϳ��� ���簢���� ���� �Ʒ� �������� x, y��ǥ���� ������ �� �������� x, y��ǥ���� ��ĭ�� ���̿� �ΰ� ���ʷ� �־�����. �������� ���� �Ʒ� �������� ��ǥ�� (0,0)�̰�, ������ �� �������� ��ǥ��(N,M)�̴�. �ԷµǴ� K���� ���簢������ ������ ��ü�� ä��� ���� ����.

���
ù° �ٿ� �и��Ǿ� ���������� ������ ������ ����Ѵ�. ��° �ٿ��� �� ������ ���̸� ������������ �����Ͽ� ��ĭ�� ���̿� �ΰ� ����Ѵ�.

���� �Է�  ����
5 7 3
0 2 4 4
1 1 2 5
4 0 6 2
���� ���  ����
3
1 7 13
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int M, N, K;
bool adj[100][100];
bool visited[100][100];

const int iter_x[] = { 0, 1, 0, -1 };
const int iter_y[] = { -1, 0, 1, 0 };
const int iter_size = 4;

int dfs(int y, int x) {
	int area = 1;

	for (int i = 0; i < iter_size; i++) {
		int next_y = y + iter_y[i];
		int next_x = x + iter_x[i];

		if (next_y >= 0 && next_y < M &&
			next_x >= 0 && next_x < N) {
			if (!visited[next_y][next_x] && !adj[next_y][next_x]) {
				visited[next_y][next_x] = true;
				area += dfs(next_y, next_x);
			}
		}
	}

	return area;
}

int main() {
	int areas[100];
	int num_areas = 0;
	memset(adj, false, sizeof(adj));
	memset(visited, false, sizeof(visited));

	cin >> M >> N >> K;

	for (int i = 0; i < K; i++) {
		int x_1, x_2, y_1, y_2;

		cin >> x_1 >> y_1 >> x_2 >> y_2;

		for (int j = y_1; j < y_2; j++) {
			for (int k = x_1; k < x_2; k++) {
				adj[j][k] = true;
			}
		}
	}

	int result = 0;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j] && !adj[i][j]) {
				visited[i][j] = true;
				areas[num_areas++] = dfs(i, j);
				result++;
			}
		}
	}

	sort(areas, areas + num_areas);

	cout << result << endl;
	for (int i = 0; i < num_areas; i++) {
		cout << areas[i] << ' ';
	}
}