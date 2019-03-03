#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

struct Ap {
	int x, y, c, p;
};

struct Pos {
	int x, y;
};

int T, M, A;
Pos pos_a;
Pos pos_b;
int path_a[100];
int path_b[100];
Ap aps[8];
const int dx[] = { 0, 0, 1, 0, -1 };
const int dy[] = { 0, -1, 0, 1, 0 };
int answer;

int maxCharging() {
	int ret = 0;
	for (int i = 0; i < A; i++) {
		for (int j = 0; j < A; j++) {
			int sum = 0;
			bool a_is_charged = false;
			bool b_is_charged = false;
			if (abs(pos_a.x - aps[i].x) + abs(pos_a.y - aps[i].y) <= aps[i].c) {
				a_is_charged = true;
				sum += aps[i].p;
			}
			if (abs(pos_b.x - aps[j].x) + abs(pos_b.y - aps[j].y) <= aps[j].c) {
				b_is_charged = true;
				sum += aps[j].p;
			}
			if (a_is_charged && b_is_charged) {
				if (i == j) {
					sum /= 2;
				}
			}
			ret = max(ret, sum);
		}
	}
	return ret;
}

int main() {
	scanf("%d", &T);

	for (int tc = 1; tc <= T; tc++) {
		answer = 0;
		pos_a.x = 1;
		pos_a.y = 1;
		pos_b.x = 10;
		pos_b.y = 10;
		scanf("%d%d", &M, &A);
		for (int i = 0; i < M; i++) {
			scanf("%d", &path_a[i]);
		}
		for (int i = 0; i < M; i++) {
			scanf("%d", &path_b[i]);
		}
		for (int i = 0; i < A; i++) {
			scanf("%d%d%d%d", &aps[i].x, &aps[i].y, &aps[i].c, &aps[i].p);
		}

		
		for (int i = 0; i < M; i++) {
			if (i == 0) {
				answer += maxCharging();
			}
			pos_a.x = pos_a.x + dx[path_a[i]];
			pos_a.y = pos_a.y + dy[path_a[i]];
			pos_b.x = pos_b.x + dx[path_b[i]];
			pos_b.y = pos_b.y + dy[path_b[i]];
			answer += maxCharging();
		}

		printf("#%d %d\n", tc, answer);
	}
}