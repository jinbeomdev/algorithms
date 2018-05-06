/* https://www.acmicpc.net/problem/15683 */

#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;

struct Camera {
	int y;
	int x;
	int camera_type;

	Camera(int _y, int _x, int _camera_type) : y(_y), x(_x), camera_type(_camera_type) {}
};

const int kMaxN = 10;	/* 세로크기 */
const int kMaxM = 10;	/* 가로크기 */
const int kInf = 10e8;

vector<vector<int> > map = vector<vector<int> >(kMaxN, vector<int>(kMaxM, 0));
vector<vector<int> > coverage = vector<vector<int> >(kMaxN, vector<int>(kMaxM, 0));
vector<Camera> camera_locations;
int n, m;
int min_result = kInf;



vector<vector<int> > SaveCoverage() {
	vector<vector<int> > temp = coverage;
	return temp;
}

void LoadCoverage(vector<vector<int> > temp) {
	coverage = temp;
}

void UnFillCoverage(int y, int x, int dir) {
	switch (dir)
	{
	case 0:
		while (y >= 0) {
			if (map[y][x] == 6) break;
			coverage[y][x]--;
			y--;
		}
		break;
	case 1:
		while (x <= m) {
			if (map[y][x] == 6) break;
			coverage[y][x]--;
			x++;
		}
		break;
	case 2:
		while (y <= n) {
			if (map[y][x] == 6) break;
			coverage[y][x]--;
			y++;
		}
		break;
	case 3:
		while (x >= 0) {
			if (map[y][x] == 6) break;
			coverage[y][x]--;
			x--;
		}
		break;
	default:
		assert(false);
	}
}

void FillCoverage(int y, int x, int dir) {
	switch (dir)
	{
	case 0:
		while (y >= 0) {
			if (map[y][x] == 6) break;
			coverage[y][x]++;
			y--;
		}
		break;
	case 1:
		while (x <= m) {
			if (map[y][x] == 6) break;
			coverage[y][x]++;
			x++;
		}
		break;
	case 2:
		while (y <= n) {
			if (map[y][x] == 6) break;
			coverage[y][x]++;
			y++;
		}
		break;
	case 3:
		while (x >= 0) {
			if (map[y][x] == 6) break;
			coverage[y][x]++;
			x--;
		}
		break;
	default:
		assert(false);
	}
}

void PrintCoverage() {
	cout << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << coverage[i][j] << " ";
		} cout << endl;
	}
}

void BackTracking(const int camera_idx) {
	if (camera_idx == camera_locations.size()) {
		int result = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (coverage[i][j] == 0) result++;
			}
		}
		
		//PrintCoverage();

		min_result = min(min_result, result);

		return;
	}
	//vector<vector<bool>> temp;
	Camera &camera_info = camera_locations[camera_idx];
	int y = camera_info.y;
	int x = camera_info.x;
	int camera_type = camera_info.camera_type;
	switch (camera_type)
	{
	case 1:
		for (int rotation = 0; rotation < 4; rotation++) {
			//temp = SaveCoverage();
			FillCoverage(y, x, 0 + rotation);
			BackTracking(camera_idx + 1);
			UnFillCoverage(y, x, 0 + rotation);
			//LoadCoverage(temp);
		}
			break;
	case 2:
		for (int rotation = 0; rotation < 2; rotation++) {
			//temp = SaveCoverage();
			FillCoverage(y, x, (1 + rotation) % 4);
			FillCoverage(y, x, (3 + rotation) % 4);
			BackTracking(camera_idx + 1);
			UnFillCoverage(y, x, (1 + rotation) % 4);
			UnFillCoverage(y, x, (3 + rotation) % 4);
			//LoadCoverage(temp);
		}
			break;
	case 3:
		for (int rotation = 0; rotation < 4; rotation++) {
			//temp = SaveCoverage();
			FillCoverage(y, x, (0 + rotation) % 4);
			FillCoverage(y, x, (1 + rotation) % 4);
			BackTracking(camera_idx + 1);
			UnFillCoverage(y, x, (0 + rotation) % 4);
			UnFillCoverage(y, x, (1 + rotation) % 4);
			//LoadCoverage(temp);
		}
			break;
	case 4:
		for (int rotation = 0; rotation < 4; rotation++) {
			//temp = SaveCoverage();
			FillCoverage(y, x, (0 + rotation) % 4);
			FillCoverage(y, x, (1 + rotation) % 4);
			FillCoverage(y, x, (3 + rotation) % 4);
			BackTracking(camera_idx + 1);
			UnFillCoverage(y, x, (0 + rotation) % 4);
			UnFillCoverage(y, x, (1 + rotation) % 4);
			UnFillCoverage(y, x, (3 + rotation) % 4);
			//LoadCoverage(temp);
		}
			break;
	case 5:
		//temp = SaveCoverage();
		FillCoverage(y, x, 0);
		FillCoverage(y, x, 1);
		FillCoverage(y, x, 2);
		FillCoverage(y, x, 3);
		BackTracking(camera_idx + 1);
		UnFillCoverage(y, x, 0);
		UnFillCoverage(y, x, 1);
		UnFillCoverage(y, x, 2);
		UnFillCoverage(y, x, 3);
		//LoadCoverage(temp);
		break;
	default:
		assert(false);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];

			if (map[i][j] != 0 && map[i][j] != 6) camera_locations.push_back(Camera(i, j, map[i][j]));
			if (map[i][j] == 6) coverage[i][j] = true;
		}
	}

	BackTracking(0);

	cout << min_result;

	//system("pause");
}