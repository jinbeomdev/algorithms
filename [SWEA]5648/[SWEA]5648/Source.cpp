#include <stdio.h>
#include <string.h>

struct Atom {
	int x, y, d, e;
};

int T, N;
int map[4001][4001];
const int offset = 2000;
Atom atoms[1000];
bool colison[1000];
const int dx[] = { 0, 0, -1, 1 };
const int dy[] = { 1, -1, 0 , 0 };

int main() {
	scanf("%d", &T);

	for (int tc = 1; tc <= T; tc++) {
		memset(map, -1, sizeof(map));
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			scanf("%d%d%d%d", &atoms[i].x, &atoms[i].y, &atoms[i].d, &atoms[i].e);
			atoms[i].y *= 2;
			atoms[i].x *= 2;
			map[atoms[i].y + offset][atoms[i].x + offset] = i;
		}

		int answer = 0;
		int num_atoms = N;

		while (num_atoms > 0) {
			memset(colison, false, sizeof(colison));

			for (int i = 0; i < N; i++) {
				Atom &cur = atoms[i];
				Atom next = cur;
				
				if (cur.x == -2001 && cur.y == -2001) continue;
				
				next.y = cur.y + dy[cur.d];
				next.x = cur.x + dx[cur.d];


				if (next.y < -2000 || next.y > 2000 || next.x < -2000 || next.x > 2000) {
					num_atoms--;
					map[cur.y + offset][cur.x + offset] = -1;
					cur.y = -2001;
					cur.x = -2001;
					continue;
				}

				if (map[next.y + offset][next.x + offset] != -1) {
					if (map[next.y + offset][next.x + offset] > i) { //아직 안 움직임
						map[cur.y + offset][cur.x + offset] = -1;
						map[next.y + offset][next.x + offset] = i;
						cur.y = next.y;
						cur.x = next.x;
					} else { //충돌
						colison[map[next.y + offset][next.x + offset]] = true;
						answer += cur.e;
						num_atoms--;
						map[cur.y + offset][cur.x + offset] = -1;
						cur.y = -2001;
						cur.x = -2001;
					}
				} else {
					if(map[cur.y + offset][cur.x + offset] != -1) map[cur.y + offset][cur.x + offset] = -1;
					map[next.y + offset][next.x + offset] = i;
					cur.y = next.y;
					cur.x = next.x;
				}
			}
			for (int i = 0; i < N; i++) {
				if (colison[i]) {
					num_atoms--;
					answer += atoms[i].e;
					map[atoms[i].y + offset][atoms[i].x + offset] = -1;
					atoms[i].y = -2001;
					atoms[i].x = -2001;
				}
			}
		}

		printf("#%d %d\n", tc, answer);
	}
}