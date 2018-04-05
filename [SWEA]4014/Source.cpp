#include <iostream>

using namespace std;

const int MAX_V = 20;

int T, N, X;
int map[MAX_V][MAX_V];
int height[MAX_V];

bool IsFlattened(int s, int c) {
	for (int i = s; i < c; i++) {
		if (height[i] != height[i + 1]) {
			return false;
		}
	}

	return true;
}

void BuildRamp(bool ramp[], int s, int c) {
	for (int i = s; i <= c; i++) {
		ramp[i] = true;
	}
}

bool CanRunway() {
	bool up_ramp[MAX_V] = { false };
	bool down_ramp[MAX_V] = { false };

	for (int i = 0; i < N - 1; i++) {
		if (height[i] < height[i + 1]) {
			if (abs(height[i] - height[i + 1]) > 1) {
				return false;
			}

			int s = i - X + 1, c = i;

			if (s < 0 || c >= N) {
				return false;
			}

			if (IsFlattened(s, c)) {
				BuildRamp(up_ramp, s, c);
			}
			else {
				return false;
			}
		}
		else if(height[i] > height[i + 1]) {
			if (abs(height[i] - height[i + 1]) > 1) {
				return false;
			}

			int s = i + 1, c = i + X;

			if (s < 0 || c >= N) {
				return false;
			}

			if (IsFlattened(s, c)) {
				BuildRamp(down_ramp, s, c);
			}
			else {
				return false;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		if (up_ramp[i] && down_ramp[i]) {
			return false;
		}
	}

	return true;
}

int main() {


	cin >> T;

	for (int tc = 0; tc < T; tc++) {
		int result = 0;
		cin >> N >> X;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}

		for (int row = 0; row < N; row++) {
			for (int column = 0; column < N; column++) {
				height[column] = map[row][column];

			}
				if (CanRunway()) {
					result++;
				}
		}

		for (int column = 0; column < N; column++) {
			for (int row = 0; row < N; row++) {
				height[row] = map[row][column];
			}
			
				if (CanRunway()) {
					result++;
				}
		}

		cout << "#" << tc + 1<< " " << result << endl;
	}
}