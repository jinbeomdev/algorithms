#include <cstdio>
#include <queue>

using namespace std;

int iter_x[] = { 0, 1, 0, -1, 0 , 0 }; //앞, 오른쪽, 뒤, 왼쪽, 위, 아래
int iter_y[] = { -1, 0, 1, 0, 0 , 0 };
int iter_z[] = { 0 , 0, 0, 0, 1, -1 };

struct  BOX_POS {
	int high;
	int col;
	int row;

	BOX_POS(int high_, int col_, int row_) :
		high(high_), col(col_), row(row_) {
	};
};

int M, N, H;
int box[100][100][100];
int num_tomatos;
queue<BOX_POS> q; // <y, x>
int answer;

int main() {
	scanf("%d%d%d", &M, &N, &H);

	for (int high = 0; high < H; high++) {
		for (int col = 0; col < N; col++) {
			for (int row = 0; row < M; row++) {
				int &p_box = box[high][col][row];
				scanf("%d", &p_box);

				if (p_box == 0) {
					num_tomatos++;
				} else if (p_box == 1) {
					q.push(BOX_POS(high, col, row));
				}
			}
		}
	}

	if (num_tomatos == 0) {
		putchar('0');
		return 0;
	}
	
	answer = 0;
	while (!q.empty()) {
		int q_size = q.size();

		for (int i = 0; i < q_size; i++) {
			int cur_z = q.front().high;
			int cur_y = q.front().col;
			int cur_x = q.front().row;
			q.pop();

			for (int j = 0; j < 6; j++) {
				int next_z = cur_z + iter_z[j];
				int next_y = cur_y + iter_y[j];
				int next_x = cur_x + iter_x[j];

				if (next_z < 0 || next_z >= H ||
					  next_y < 0 || next_y >= N ||
					  next_x < 0 || next_x >= M
					) {
					continue;
				}
				int &next_box = box[next_z][next_y][next_x];

				if (next_box == 0) {
					num_tomatos--;
					next_box = 1;
					q.push(BOX_POS(next_z, next_y, next_x));

					//for (int high = 0; high < H; high++) {
					//	for (int col = 0; col < N; col++) {
					//		for (int row = 0; row < M; row++) {
					//			printf("%d ", box[high][col][row]);
					//		}
					//		putchar('\n');
					//	}
					//	putchar('\n');
					//}
				}
			}
		}

		answer++;
	}

	if (num_tomatos > 0) {
		printf("-1");
		return 0;
	}

	printf("%d", answer - 1);

	return 0;
}