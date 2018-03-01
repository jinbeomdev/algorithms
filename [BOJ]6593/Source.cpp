//https://www.acmicpc.net/problem/6593

/*
����
����� ��� ������ ������ ���Ҵ�. ���⼭ Ż���ϴ� ���� ���� ���� �����ϱ�? ��� ������ �� ���� ���̰� 1�� ������ü(���� ������ü)�� �̷�����ִ�. �� ������ü�� ������ �̷���� �־� ������ �� ���ų�, ����־ ������ �� �ְ� �Ǿ��ִ�. ����� �� ĭ���� ������ 6���� ĭ(��,��,��,��,��,��)���� 1���� �ð��� �鿩 �̵��� �� �ִ�. ��, �밢������ �̵��ϴ� ���� �Ұ����ϴ�. �׸��� ��� ������ �ٱ��鵵 ��� ������ �����־� �ⱸ�� ���ؼ��� Ż���� �� �ִ�.

����� ��� ������ Ż���� �� ������? ���� �׷��ٸ� �󸶳� �ɸ���?

�Է�
�Է��� ���� ���� �׽�Ʈ ���̽��� �̷������, �� �׽�Ʈ ���̽��� �� ���� ���� L, R, C�� �����Ѵ�. L(1 �� L �� 30)�� ��� ������ �� ���̴�. R(1 �� R �� 30)�� C(1 �� C �� 30)�� ��� ������ �� ���� ��� ���� ������ ��Ÿ����.

�� ���� �� ���� C���� ���ڷ� �̷���� R���� ���� L�� �־�����. �� ���ڴ� ��� ������ �� ĭ�� ��Ÿ����. ������ �����־� ������ �� ���� ĭ�� '#'���� ǥ���ǰ�, ����ִ� ĭ�� '.'���� ǥ���ȴ�. ����� ���� ������ 'S'�� ǥ���ǰ�, Ż���� �� �ִ� �ⱸ�� 'E'�� ǥ���ȴ�. �� �� ���̿��� �� ���� ������, �Է��� ���� L, R, C�� ��� 0���� ǥ���ȴ�.

���
�� ������ ���� �� �پ� ���� ����Ѵ�. ���� ����� Ż���� �� �ִٸ� ������ ���� ����Ѵ�.

Escaped in x minute(s).
���⼭ x�� ��� ������ Ż���ϴ� ���� �ʿ��� �ִ� �ð��̴�.

���� Ż���� �Ұ����ϴٸ�, ������ ���� ����Ѵ�.

Trapped!
���� �Է�  ����
3 4 5
S....
.###.
.##..
###.#

#####
#####
##.##
##...

#####
#####
#.###
####E

1 3 3
S##
#E#
###

0 0 0
���� ���  ����
Escaped in 11 minute(s).
Trapped!
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int dfs(int l, int r, int c, int dist);
void bfs();

int iter_l[] = { 0, -1, 1 };
int iter_r[] = { 0, 1, 0, -1 };
int iter_c[] = { 1, 0, -1, 0 };

//!!-------------------------------------------------------------!!/
//!!-------------------------------------------------------------!!/
//variable for dfs
std::pair<int, std::pair<int, int>> start;
std::pair<int, std::pair<int, int>> end;

std::vector<std::vector<std::vector<char>>> adj;
std::vector<std::vector<std::vector<bool>>> visited;
//!!-------------------------------------------------------------!!/
//!!-------------------------------------------------------------!!/

//!!-------------------------------------------------------------!!/
//!!-------------------------------------------------------------!!/
//variable for bfs
std::vector<std::vector<std::vector<int>>> dist;
//!!-------------------------------------------------------------!!/
//!!-------------------------------------------------------------!!/


int L, R, C;

int main() {
	while (true) {
		scanf("%d %d %d", &L, &R, &C);
		
		adj = std::vector<std::vector<std::vector<char>>>(L, std::vector<std::vector<char>>(R, std::vector<char>(C)));
		//visited = std::vector<std::vector<std::vector<bool>>>(L, std::vector<std::vector<bool>>(R, std::vector<bool>(C, false)));
		dist = std::vector<std::vector<std::vector<int>>>(L, std::vector<std::vector<int>>(R, std::vector<int>(C, -1)));

		if (L == 0 && R == 0 && C == 0) {
			break;
		}

		for (int i = 0; i < L; i++) {
			for (int j = 0; j < R; j++) {
				for (int k = 0; k < C; k++) {
					std::cin >> adj[i][j][k];

					if (adj[i][j][k] == 'S') {
						start = { i, {j, k} };
					}

					if (adj[i][j][k] == 'E') {
						end = { i, {j, k} };
					}
				}
			}
		}
		
		//int ret = dfs(start.first, start.second.first, start.second.second, 0);
		bfs();

		/* dfs
		if(ret > 0)
			printf("Escaped in %d minute(s).", ret);
		else
			printf("Trapped!");
		*/

		/*bfs*/
		if (dist[end.first][end.second.first][end.second.second] > 0)
			printf("Escaped in %d minute(s).\n", dist[end.first][end.second.first][end.second.second]);
		else
			printf("Trapped!\n");
	}
}

//dfs is not suitable to this problem cause we need to find shortest path.
//so I recommend to use bfs
int dfs(int l, int r, int c, int dist)
{
	int ret = -1;

	if (adj[l][r][c] == 'E') {
		return dist;
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			int next_l;
			int next_r;
			int next_c;
			if (i == 0) {
				next_l = l;
				next_r = r + iter_r[j];
				next_c = c + iter_c[j];
			}
			else {
				next_l = l + iter_l[i];
				next_c = c;
				next_r = r;
			}

			if (next_l >= 0 && next_l < L &&
				next_r >= 0 && next_r < R &&
				next_c >= 0 && next_c < C &&
				!visited[next_l][next_r][next_c] &&
				adj[next_l][next_r][next_c] != '#') {
				visited[next_l][next_r][next_c] = true;

				ret = std::max(ret, dfs(next_l, next_r, next_c, dist + 1));
			}
		}
	}

	return ret;
}

void bfs()
{
	std::queue<std::pair<int, std::pair<int, int>>> q;

	q.push({ start.first, { start.second.first, start.second.second} });
	dist[start.first][start.second.first][start.second.second] = 0;

	while (!q.empty()) {
		int l = q.front().first;
		int r = q.front().second.first;
		int c = q.front().second.second;
		q.pop();
		
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 4; j++) {
				int next_l;
				int next_r;
				int next_c;
				if (i == 0) {
					next_l = l;
					next_r = r + iter_r[j];
					next_c = c + iter_c[j];
				}
				else {
					next_l = l + iter_l[i];
					next_c = c;
					next_r = r;
				}

				if (next_l >= 0 && next_l < L &&
					next_r >= 0 && next_r < R &&
					next_c >= 0 && next_c < C &&
					dist[next_l][next_r][next_c] < 0 && //there isn't visited not yet
					adj[next_l][next_r][next_c] != '#') {
					dist[next_l][next_r][next_c] = dist[l][r][c] + 1;

					//if find 'End' location, quit the function. 
					if (end.first == next_l &&
						end.second.first == next_r &&
						end.second.second == next_c) {
						return;
					}

					q.push({ next_l , { next_r, next_c} });
				}
			}
		}
	}
}