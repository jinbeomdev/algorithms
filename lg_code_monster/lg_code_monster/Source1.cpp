#include <string>
#include <vector>
#include <utility>
#include <limits>
#include <algorithm>

using namespace std;

int answer = -1;

int getDistance(pair<int, int> a, int x, int y) {
	return abs(a.second - x) * abs(a.second - x) + abs(a.first - y) * abs(a.first - y);
}

void dfs(int N, const vector<vector<int>>& house, vector<pair<int, int>>& constructed, vector<vector<bool>>& map) {
	if (constructed.size() == N) {
		int smallest = numeric_limits<int>::max();
		for (int i = 0; i < constructed.size(); i++) {
			for (int j = 0; j < house.size(); j++) {
				smallest = min(smallest, getDistance(constructed[i], house[j][0] + 100, house[j][1] + 100));
			}
		}
		answer = max(answer, smallest);
		return;
	}

	for (int i = 0; i < 201; i++) {
		for (int j = 0; j < 201; j++) {
			if (!map[i][j]) {
				map[i][j] = true;
				constructed.push_back(make_pair(i, j)	);
				dfs(N, house, constructed, map);
				constructed.pop_back();
				map[i][j] = false;
			}
		}
	}
}

int solution(int N, vector<vector<int>> house) {
	vector<vector<bool>> map = vector<vector<bool>>(201, vector<bool>(201, false));
	vector<pair<int, int>> constructed;

	for (int i = 0; i < house.size(); i++) {
		map[house[i][1] + 100][house[i][0] + 100] = true;
	}

	dfs(N, house, constructed, map);

	return answer;
}

int main() {
	vector<vector<int>> house;
	vector<int> coord;
	coord.push_back(0);
	coord.push_back(0);
	house.push_back(coord);
	solution(1, house);
}