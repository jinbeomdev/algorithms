#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

const int iter_size = 4;
const int iter_x[] = { 0, 1, 0, -1 };
const int iter_y[] = { -1, 0, 1, 0 };

int N, M;
int red_x, red_y, blue_x, blue_y, goal_y, goal_x;
char map[11][11];
bool visited[11][11][11][11];

void move(int& y, int& x, int dir) {
	int next_y = y;
	int next_x = x;

	while (map[next_y][next_x] != '#') {
		next_y = next_y + iter_y[dir];
		next_x = next_x + iter_x[dir];

		if (next_y == goal_y && next_x == goal_x) {
			y = next_y;
			x = next_x;
			return;
		}
	}

	y = next_y - iter_y[dir];
	x = next_x - iter_x[dir];
}

int main() {
	scanf("%d%d", &N, &M);

	for (int i = 0; i < N; i++) {
		scanf("%s", map[i]);
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 'R') {
				red_y = i;	red_x = j;
			} else if (map[i][j] == 'B') {
				blue_y = i; blue_x = j;
			} else if (map[i][j] == 'O') {
				goal_y = i; goal_x = j;
			}
		}
	}

	memset(visited, false, sizeof(visited));
	queue<pair<int, int>> q;
	q.push(make_pair(red_y * M + red_x, blue_y * M + blue_x));
	visited[red_y][red_x][blue_y][blue_x] = true;

	int cnt_move = 1;
	bool goal = false;
	while (!q.empty()) {
		if (cnt_move > 10) break;

		int size = q.size();

		for (int i = 0; i < size; i++) {
			int crx = q.front().first % M; //current red x
			int cry = q.front().first / M; //current red y
			int cbx = q.front().second % M; //currnet blue x
			int cby = q.front().second / M; //current blue y
			q.pop();

			for (int j = 0; j < iter_size; j++) {
				int nrx = crx, nry = cry, nbx = cbx, nby = cby; //next red x, next red y, next blue x, next blue y 
				move(nry, nrx, j); move(nby, nbx, j);

				//������ �Ķ����� ���ÿ� ���ۿ� �� ���
				if (goal_y == nry && goal_x == nrx &&
						goal_y == nby && goal_x == nbx) {
					continue;
				}

				//������ �Ķ����� ��ĥ ��� ��ǥ ������
				if (nry == nby && nrx == nbx) { //
					//0 ����, 1 ������, 2 �Ʒ���, 3 ����
					if (j == 0) {
						if (cry < cby) { //�������� �Ķ������� ���� ���� ���
							nby++;
						} else { //�������� �Ķ������� �ؿ� ���� ���
							nry++;
						}
					} else if (j == 1) {
						if (crx < cbx) { //�������� �Ķ������� ���ʿ� ���� ���
							nrx--;
						} else { //�������� �Ķ������� �����ʿ� ���� ���
							nbx--;
						}
					} else if (j == 2) {
						if (cry < cby) { //�������� �Ķ������� ���� ���� ���
							nry--;
						} else { //�������� �Ķ������� �Ʒ��� ���� ���
							nby--;
						}
					} else if (j == 3) {
						if (crx < cbx) { //�������� �Ķ������� ���ʿ� ���� ���
							nbx++;
						} else { //�������� �Ķ������� �����ʿ� ���� ���
							nrx++;
						}
					}
				}

				if (goal_y == nby && goal_x == nbx) continue;
				if (goal_y == nry && goal_x == nrx) {
					goal = true;
					break;
				}

				if (!visited[nry][nrx][nby][nbx]) {
					visited[nry][nrx][nby][nbx] = true;
					q.push(make_pair(nry * M + nrx, nby * M + nbx));
				}
			}

			if (goal) break;
		}

		if (goal) break;
		cnt_move++;
	}

	if (!goal) {
		printf("-1");
	} else {
		printf("%d", cnt_move);
	}
}