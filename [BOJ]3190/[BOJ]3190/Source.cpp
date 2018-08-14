#include <cstdio>
#include <cstring>
#include <cstdlib>

int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };

struct CTRL_INFO {
	int time;
	char dir;
};

int N, K, L;
int map[101][101]; //0:ºóÄ­ 1:¹ì 2:»ç°ú

CTRL_INFO head_control[100];
CTRL_INFO tail_control[100];

bool move(int&y, int& x, const int dir, const int type, bool& apple) {
	int next_y = y + dy[dir];
	int next_x = x + dx[dir];

	if (type == 0) {
		if (next_y < 1 || next_y > N ||
			next_x < 1 || next_x > N) {
			return false;
		}
	}

	if (type == 0) { //¸Ó¸®
		if (map[next_y][next_x] == 1) return false;
		if (map[next_y][next_x] == 2) {
			apple = true;
			for (int i = 0; i < 100; i++) {
				tail_control[i].time++;
			}
		}

		map[next_y][next_x] = 1;
	}

	if (type == 1) map[next_y][next_x] = 0;

	y = next_y;
	x = next_x;

	return true;
}

void debug(const int time) {
	puts("");
	printf("%d\n", time);
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			printf("%d", map[i][j]);
		}
		puts("");
	}
}

int main() {
	memset(map, 0, sizeof(map));
	scanf("%d%d", &N, &K);
	
	map[1][1] = 1;
	for (int i = 0; i < K; i++) {
		int y, x;
		scanf("%d%d", &y, &x);
		map[y][x] = 2;
	}
	scanf("%d", &L);

	for (int i = 0; i < L; i++) {
		int time;
		char dir;
		scanf("%d %c", &time, &dir);
		head_control[i].time = time;
		tail_control[i].time = time + 1;
		tail_control[i].dir = head_control[i].dir = dir;
	}

	int time = 0;
	int head_dir = 1; //0:À§ 1:¿À¸¥ÂÊ 2:¾Æ·¡ 3:¿ÞÂÊ
	int head_ctrl = 0;
	int tail_dir = 1;
	int tail_ctrl = 0;
	int head_y = 1, head_x = 1;
	int tail_y = 1, tail_x = 0;
	while (true) {
		time++;

		//debug(time);
	
		bool apple = false;
		int is_moved = move(head_y, head_x, head_dir, 0, apple);
		if (!is_moved) break;
		
		if (!apple) move(tail_y, tail_x, tail_dir, 1, apple);
		if (time == head_control[head_ctrl].time) {
			switch (head_control[head_ctrl].dir) {
			case 'L':
				head_dir = (head_dir + 3) % 4;
				break;
			case 'D':
				head_dir = (head_dir + 1) % 4;
				break;
			}
			head_ctrl++;
		}
		if (time == tail_control[tail_ctrl].time) {
			switch (tail_control[tail_ctrl].dir) {
			case 'L':
				tail_dir = (tail_dir + 3) % 4;
				break;
			case 'D':
				tail_dir = (tail_dir + 1) % 4;
				break;
			}
			tail_ctrl++;
		}
	}
	printf("%d", time);
}