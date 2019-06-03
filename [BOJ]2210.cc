#include <stdio.h>
#include <vector>

using namespace std;

typedef pair<int ,int> pii;

bool hashing[1000000] = {false, };
int map[5][5];
vector<pii> comb;
int answer = 0;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

void dfs(int y, int x, int cnt) {
	if(cnt == 6) {
		int pos = 1;
		int sum = 0;
		for(int i = comb.size() - 1; i >= 0; i--) {
			sum += map[comb[i].first][comb[i].second] * pos;
			pos *= 10;
		}
		if(!hashing[sum]) {
//			printf("%d\n", sum);
			hashing[sum] = true;
			answer++;
		}
		return;
	}
	for(int i = 0; i < 4; i++) {
		int next_y = y + dy[i];
		int next_x = x + dx[i];

		if(next_y < 0 || next_y >= 5 || next_x < 0 || next_x >= 5) continue;

		comb.push_back(make_pair(next_y, next_x));
		dfs(next_y, next_x, cnt + 1);
		comb.pop_back();
	}
}
int main() {
	for(int i = 0; i < 5; i++) {
		for(int j = 0; j < 5; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	
	for(int i = 0; i < 5; i++) {
		for(int j = 0; j < 5; j++) {
			comb.push_back(make_pair(i, j));
			dfs(i, j, 1);
			comb.pop_back();
		}
	}

	printf("%d", answer);
}

