#include <cstdio>
#include <queue>
#include <vector>

#include <cassert>

using namespace std;

const int iter_x[] = { 0, 1, 0, -1 };
const int iter_y[] = { -1, 0, 1, 0 };

struct POSITION {
	int x, y;
	bool is_destroyed;

	POSITION(int x_, int y_, bool is_destroyed_) :
		x(x_), y(y_), is_destroyed(is_destroyed_) {
	}
};

int N, M;
vector<vector<int>> adj;
vector<vector<bool>> visited[2];
queue<POSITION> q;

int bool2int(bool b) {
	if (b) {
		return 1;
	} else {
		return 0;
	}
}

bool int2bool(int i) {
	if (i) {
		return true;
	} else {
		return false;
	}
}

int main() {
	scanf("%d%d", &N, &M);

	adj.resize(N, vector<int>(M, 0));
	visited[0].resize(N, vector<bool>(M, false));
	visited[1].resize(N, vector<bool>(M, false));

	for (int i = 0; i < adj.size(); i++) {
		for (int j = 0; j < adj[i].size(); j++) {
			scanf("%1d", &adj[i][j]);
		}
	}

	q.push(POSITION(0, 0, false));
	visited[0][0][0] = true;

	int depth = 1;
	bool is_arrived = false;
	while (!q.empty()) {
		int q_size = q.size();

		for (int i = 0; i < q_size; i++) {
			int here_x = q.front().x;
			int here_y = q.front().y;
			int here_is_destroyed = bool2int(q.front().is_destroyed);
			q.pop();

			if (here_x == M - 1 && here_y == N - 1) {
				is_arrived = true;
				break;
			}

			for (int j = 0; j < 4; j++) {
				int next_x = here_x + iter_x[j];
				int next_y = here_y + iter_y[j];

				if (next_x < 0 || next_x >= M ||
					next_y < 0 || next_y >= N) {
					continue;
				}


				if (!visited[here_is_destroyed][next_y][next_x]) {
					if (adj[next_y][next_x] == 0) {
						visited[here_is_destroyed][next_y][next_x] = true;
						q.push(POSITION(next_x, next_y, int2bool(here_is_destroyed)));
					} else if (int2bool(here_is_destroyed) == false) {
						visited[1][next_y][next_x] = true;
						q.push(POSITION(next_x, next_y, true));
					}
				}
			}
		}

		if (is_arrived) break;

		depth++;
	}

	if (is_arrived) {
		printf("%d", depth);
	} else {
		printf("-1");
	}
}

/*
	�� ������ Ʋ�ȴ� ������ ���� �μ��� ������ ��ΰ� ���� �μ��� ���� ��ο� ������ ��ģ��
	(�μ��� ������ ��ΰ� visited[i][j]�� true�� �ϱ� ������ ���� �μ��� ���� ��δ� �ش� ��θ� ������ �� ���� ��)
	�׷��� ������ visted �迭�� ���� �μ� ���� �μ��� ���� ���� ���̽��� ����� ������ �ؾ��ߴ�.

	�ٽ� ������ � ��η� x,y�� �����ϵ����� ��� ����. �� ������ ���� �ּ� ��θ� ã�� �ְ�
	x, y�� �������� ���� �ּ� ��η� ��������.
	������ x, y�� �������� �� ���� �μ� ���ΰ� ���� ��ο� ������ ��ġ�� ������ visited �迭�� ���� ���� �ؾ���.
	���� ������ ������ �����
*/