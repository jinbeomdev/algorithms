#include <cstdio>
#include <cmath>

int N;
int r, c;
int cnt = 0;

void divide(int start_y, int end_y, int start_x, int end_x) {

	if (start_y == end_y &&
			start_x == end_x) {
			//printf("%d %d\n", start_y, start_x);
		if (start_y == r &&
				start_x == c) {
			printf("%d", cnt);
		}
		cnt = cnt + 1;
		return;
	}

	int mid_y = (start_y + end_y) / 2;
	int mid_x = (start_x + end_x) / 2;
	int iter_start_y[] = { start_y, start_y, mid_y + 1, mid_y + 1 };
	int iter_end_y[] = { mid_y, mid_y, end_y, end_y };
	int iter_start_x[] = { start_x, mid_x + 1, start_x, mid_x + 1 };
	int iter_end_x[] = { mid_x, end_x, mid_x, end_x };

	for (int i = 0; i < 4; i++) {
		int next_start_y = iter_start_y[i];
		int next_end_y = iter_end_y[i];
		int next_start_x = iter_start_x[i];
		int next_end_x = iter_end_x[i];

		if (r < next_start_y || next_end_y < r ||
			c < next_start_x || next_end_x < c) {
			cnt = cnt + abs(next_end_y - next_start_y + 1) *
				          abs(next_end_x - next_start_x + 1);
			continue;
		}y

		divide(next_start_y, next_end_y, next_start_x, next_end_x);
	}
}

int main() {
	scanf("%d%d%d", &N, &r, &c);

	int size = pow(2, N);

	divide(0, size - 1, 0, size - 1);
}