#include <stdio.h>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

struct Ball {
	pii red;
	pii blue;
	int cnt;
	Ball(int blue_y, int blue_x, int red_y, int red_x, int cnt_) : cnt(cnt_) {
		blue.first = blue_y;
		blue.second = blue_x;
		red.first = red_y;
		red.second = red_x;
	}
};

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };

int N, M;
char map[11][11];
bool discoverd[10][10][10][10];
pii red;
pii blue;

int main() {
	scanf("%d%d", &N, &M);

	for (int i = 0; i < N; i++) {
		scanf("%s", map[i]);

		for (int j = 0; j < M; j++) {
			if (map[i][j] == 'R') {
				map[i][j] = '.';
				red.first = i; red.second = j;
			}

			if (map[i][j] == 'B') {
				map[i][j] = '.';
				blue.first = i; blue.second = j;
			}
		}
	}

	queue<Ball> q;
	q.push(Ball(blue.first, blue.second, red.first, red.second, 0));

	discoverd[blue.first][blue.second][red.first][red.second] = true;

	while (!q.empty()) {
		Ball here = q.front();
		q.pop();

		if (map[here.blue.first][here.blue.second] == 'O') continue;

		if (map[here.red.first][here.red.second] == 'O') {
			printf("%d", here.cnt);
			return 0;
		}

		for (int i = 0; i < 4; i++) {
			int blue_y = here.blue.first;
			int blue_x = here.blue.second;
			int red_y = here.red.first;
			int red_x = here.red.second;
			int cnt = here.cnt;

			while (blue_y > 0 && blue_y < N && blue_x > 0 && blue_x < M && map[blue_y][blue_x] != '#' && map[blue_y][blue_x] != 'O') {
				blue_y += dy[i];
				blue_x += dx[i];
			}
			if (map[blue_y][blue_x] == '#') {
				blue_y -= dy[i];
				blue_x -= dx[i];
			}

			while (red_y > 0 && red_y < N && red_x > 0 && red_x < M && map[red_y][red_x] != '#' && map[red_y][red_x] != 'O') {
				red_y += dy[i];
				red_x += dx[i];
			}
			if (map[red_y][red_x] == '#') {
				red_y -= dy[i];
				red_x -= dx[i];
			}

			if (blue_y == red_y && blue_x == red_x && map[red_y][red_x] != 'O') {
				if (i == 0) {
					if (here.blue.first < here.red.first) red_y++;
					else blue_y++;
				} else if (i == 1) {
					if (here.blue.second > here.red.second) red_x--;
					else blue_x--;
				} else if (i == 2) {
					if (here.blue.first > here.red.first) red_y--;
					else blue_y--;
				} else {
					if (here.blue.second < here.red.second) red_x++;
					else blue_x++;
				}
			}

			if (blue_y > 0 && blue_y < N && blue_x > 0 &&
				red_y > 0 && red_y < N && red_x > 0 && red_x < M &&
				!discoverd[blue_y][blue_x][red_y][red_x]) {
				discoverd[blue_y][blue_x][red_y][red_x] = true;
				q.push(Ball(blue_y, blue_x, red_y, red_x, cnt + 1));
			}
		}
	}
	printf("-1");
}