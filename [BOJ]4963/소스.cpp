/*
https://www.acmicpc.net/problem/4963

����
���簢������ �̷���� �ִ� ���� �ٴ� ������ �־�����. ���� ������ ���� ���α׷��� �ۼ��Ͻÿ�.



�� ���簢���� ����, ���� �Ǵ� �밢������ ����Ǿ� �ִ� �簢���� �ɾ �� �ִ� �簢���̴�.

�� ���簢���� ���� ���� ��������, �� ���簢������ �ٸ� ���簢������ �ɾ �� �� �ִ� ��ΰ� �־�� �Ѵ�. ������ �ٴٷ� �ѷ��׿� ������, ���� ������ ���� �� ����.

�Է�
�Է��� ���� ���� �׽�Ʈ ���̽��� �̷���� �ִ�. �� �׽�Ʈ ���̽��� ù° �ٿ��� ������ �ʺ� w�� ���� h�� �־�����. w�� h�� 50���� �۰ų� ���� ���� �����̴�.

��° �ٺ��� h�� �ٿ��� ������ �־�����. 1�� ��, 0�� �ٴ��̴�.

�Է��� ������ �ٿ��� 0�� �� �� �־�����.

���
�� �׽�Ʈ ���̽��� ���ؼ�, ���� ������ ����Ѵ�.

���� �Է�  ����
1 1
0
2 2
0 1
1 0
3 2
1 1 1
1 1 1
5 4
1 0 1 0 0
1 0 0 0 0
1 0 1 0 1
1 0 0 1 0
5 4
1 1 1 0 1
1 0 1 0 1
1 0 1 0 1
1 0 1 1 1
5 5
1 0 1 0 1
0 0 0 0 0
1 0 1 0 1
0 0 0 0 0
1 0 1 0 1
0 0
���� ���  ����
0
1
1
3
1
9
*/
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> map;
vector<vector<bool>> visited;
int w, h;

const int DIR_RANGE = 8;
const int X_DIR[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
const int Y_DIR[] = { -1, -1, 0, 1, 1, 1, 0, -1 };

const bool is_out_of_range(int x, int y) {
	if (x >= 0 && x < w &&
		y >= 0 && y < h) {
		return true;
	}

	return false;
}

void dfs(int x, int y) {
	visited[y][x] = true;

	for(int i = 0; i < DIR_RANGE; i++) {
			int next_y = y + Y_DIR[i];
			int next_x = x + X_DIR[i];
			if (is_out_of_range(next_x, next_y) &&
				visited[next_y][next_x] == false &&
				map[next_y][next_x] == 1) { //land
				dfs(next_x, next_y);
			}
	}
}

int main() {

	while (true) {
		int land = 0;

		cin >> w >> h;

		if (w == 0 && h == 0) {
			return 0;
		}

		map = vector<vector<int>>(h, vector<int>(w));
		visited = vector<vector<bool>>(h, vector<bool>(w, false));

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];
			}
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (visited[i][j] == false &&
					map[i][j] == 1) {
					dfs(j, i);
					land++;
				}
			}
		}

		cout << land << endl;
	}

	return 0;
}