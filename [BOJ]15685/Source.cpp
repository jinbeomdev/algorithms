/* https://www.acmicpc.net/problem/15685 */

//#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>

using namespace std;

const int map_size = 101;
const int iter_x[] = { 1, 0, -1, 0 };
const int iter_y[] = { 0, -1, 0, 1 };

int RotateDirection(int direction) {
	return (direction + 1) % 4;
}

int main() {
	bool map[map_size][map_size] = { false, };
	int n;
	
	scanf("%d", &n);

	while (n--) {
		int x, y, d, g;
	
		scanf("%d %d %d %d", &x, &y, &d, &g);

		vector<int> directions;
		directions.push_back(d);
		while (g--) {
			int directions_size = directions.size();
			
			for (int i = directions_size - 1; i >= 0; i--) {
				directions.push_back(RotateDirection(directions[i]));
			}
		}

		map[y][x] = true;
		for (int direction : directions) {
			x = x + iter_x[direction];
			y = y + iter_y[direction];
			map[y][x] = true;
		}
	}

	int result = 0;
	for (int i = 0; i < map_size - 1; i++) {
		for (int j = 0; j < map_size - 1; j++) {
			if (map[i][j] &&
				map[i][j + 1] &&
				map[i + 1][j] &&
				map[i + 1][j + 1]) {
				result++;
			}
		}
	}

	//for (int i = 0; i < 10; i++) {
	//	for (int j = 0; j < 10; j++) {
	//		printf("%d ", map[i][j]);
	//	}
	//	putchar('\n');
	//}
	//putchar('\n');

	printf("%d", result);

	//system("pause");
}