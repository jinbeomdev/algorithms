#include <stdio.h>
#include <queue>

using namespace std;

struct Info {
	int y;
	int x;
	int cnt;

	Info(int y_, int x_, int cnt_) : y(y_), x(x_), cnt(cnt_) {}
};

int N;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };

int map[500][1000];
int parent[500][1000];

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < N * 2; j++) {
				scanf("%d", &map[i][j]);
			}
		}
		else {
			for (int j = 1; j < N * 2 - 1; j++) {
				scanf("%d", &map[i][j]);
			}
		}
	}

	queue<Info> q;
	q.push(Info(0, 0, 0));

	while (!q.empty()) {
		Info here = q.front();
		int here_y = here.y;
		int here_x = here.x;
		int here_cnt = here_cnt;

		for (int i = 0; i < N; i++) {
			
		}
	}

	return 0;
}