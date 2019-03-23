#include <stdio.h>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

int N, M, H;
int map[30][19];
vector<pii> lines;
int answer = 4;
int next(int row, int col) {
	if (col > 0) {
		if (map[row][col * 2 - 1]) return col - 1;
	}

	if (col < N - 1) {
		if (map[row][col * 2 + 1]) return col + 1;
	}

	return col;
}
void dfs(int idx, int cnt) {
	if (cnt >  3) {
		return;
	}

	if (idx == lines.size()) {
		for (int col = 0; col< N; col++) {
			int next_col = col;
			for (int row = 0; row < H; row++) {
				next_col = next(row, next_col);
			}
			if (next_col != col) return;
		}
		if (answer > cnt) answer = cnt;
		return;
	}

	int line_y = lines[idx].first;
	int line_x = lines[idx].second;

	map[line_y][line_x] = true;
	dfs(idx + 1, cnt + 1);
	map[line_y][line_x] = false;
	dfs(idx + 1, cnt);
}
int main() {
scanf("%d%d%d", &N, &M, &H);

for (int i = 0; i < H; i++) {
	for (int j = 0; j < N; j++) {
		map[i][j * 2] = true;
	}
}

for (int i = 0; i < M; i++) {
	int a, b;
	scanf("%d %d", &a, &b);
	a--;
	b--;
	b = (b * 2) + 1;
	map[a][b] = true;
}

for (int i = 0; i < H; i++) {
	for (int j = 0; j < N - 1; j++) {
		if(!map[i][j * 2 + 1]) lines.push_back(make_pair(i, j * 2 + 1));
	}
}

dfs(0, 0);

if (answer == 4) {
	printf("-1");
} else {
	printf("%d", answer);
}
}