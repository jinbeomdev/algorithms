#include <iostream>
#include <cstring>

using namespace std;

void ShiftArray(int magnet[4][8], int i, int j) {
	if (j == 0) {
		return;
	}

	if (j == 1) {
		int temp = magnet[i][7];

		for (int k = 7; k > 0; k--) {
			magnet[i][k] = magnet[i][k - 1];
		}
		magnet[i][0] = temp;

		return;
	}


	if (j == -1) {
		int temp = magnet[i][0];
		for (int k = 0; k < 7; k++) {
			magnet[i][k] = magnet[i][k + 1];
		}
		magnet[i][7] = temp;

		return;
	}
}

int main() {
	int t;
	int K;
	int magnet[4][8];
	int result = 0;
	int index_magnet;
	int dir;
	int rotate_array[4] = { 0 };

	cin >> t;

	for (int tc = 1; tc <= t; tc++) {
		result = 0;

		cin >> K;

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 8; j++) {
				cin >> magnet[i][j];
			}
		}

		for (int i = 0; i < K; i++) {
			memset(rotate_array, 0, sizeof(rotate_array));

			cin >> index_magnet >> dir;
			index_magnet--;

			rotate_array[index_magnet] = (int)dir;

			for (int left_walker = index_magnet; left_walker > 0; left_walker--) {
				if (magnet[left_walker - 1][2] == magnet[left_walker][6]) {
					rotate_array[left_walker - 1] = (int)0;
					break;
				}
				else {
					rotate_array[left_walker - 1] = ((rotate_array[left_walker] == 1) ? (int)-1 : (int)1);

				}
			}

			for (int right_walker = index_magnet ; right_walker < 3; right_walker++) {
				if (magnet[right_walker][2] == magnet[right_walker + 1][6]) {
					rotate_array[right_walker + 1] = (int)0;
					break;
				}
				else {
					rotate_array[right_walker + 1] = ((rotate_array[right_walker] == 1) ? (int)-1 : (int)1);
				}
			}

			for (int walker = 0; walker < 4; walker++) {
				ShiftArray(magnet, walker, rotate_array[walker]);
			}
		}

		if (magnet[0][0] == 1) result += 1;
		if (magnet[1][0] == 1) result += 2;
		if (magnet[2][0] == 1) result += 4;
		if (magnet[3][0] == 1) result += 8;

		cout << "#" << tc << " " << result << endl;
	}
	return 0;
}
