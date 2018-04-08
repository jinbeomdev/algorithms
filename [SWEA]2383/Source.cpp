#include <iostream>
#include <vector>

using namespace std;

const int kMaxValue = 10;
const int kMaxStairs = 2;
const int kMaxTime = kMaxValue * 2;

vector<pair<int, int>> person_locations; // locations
vector<pair<int, int>> stairs_locations;
vector<pair<int, int>> selected_stairs;

int GetDistance(int person_index) {
	int dx = abs(person_locations[person_index].first -
	             selected_stairs[person_index].first);
	int dy = abs(person_locations[person_index].second -
			         selected_stairs[person_index].second);
	return dx + dy;
}

void Dfs(const int person_index) {
	if (person_index == person_locations.size() - 1) {
		/* Calculate the time */
		return;
	}

	for (int i = 0; i < kMaxStairs; i++) {
		selected_stairs[person_index] = stairs_locations[i];
		Dfs(person_index + 1);
	}
}

int main() {
	int num_test_case;

	cin >> num_test_case;

	for (int test_case = 1; test_case <= num_test_case; test_case++) {
		int map_size;
		int map[kMaxValue][kMaxValue];

		cin >> map_size;

		/* Get information */
		for (int i = 0; i < map_size; i++) {
			for (int j = 0; j < map_size; j++) {
				cin >> map[i][j];

				if (map[i][j] == 1) {
					person_locations.push_back({ i, j });
				} else if(map[i][j] > 1) { 
					stairs_locations.push_back({ i, j });
				}
			}
		}

		selected_stairs.resize(person_locations.size());

		Dfs(0);
	}

	return 0;
}