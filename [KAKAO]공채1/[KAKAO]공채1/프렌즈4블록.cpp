#include <string>
#include <vector>
#include <utility>

using namespace std;

int dy[] = {0, 0, 1, 1 };
int dx[] = {0, 1, 0, 1 };

bool CanRemove(const vector<string>& board, int i, int j) {
	if (board[i][j] == 'o') return false;

	for (int k = 1; k < 4; k++) {
		if (board[i + dy[k]][j + dx[k]] != board[i][j]) {
			return false;
		}
	}
	return true;
}

int solution(int m, int n, vector<string> board) {
	int answer = 0;
	bool is_removed = true;
	while (is_removed) {
		is_removed = false;
		vector<pair<int, int>> indices;
		for (int i = 0; i < board.size() - 1; i++) {
			for (int j = 0; j < board[i].size() - 1; j++) {
				if (CanRemove(board, i, j)) {
					is_removed = true;
					indices.push_back(make_pair(i, j));
				}
			}
		}

		for (int i = 0; i < indices.size(); i++) {
			for (int j = 0; j < 4; j++) {
				if (board[indices[i].first + dy[j]][indices[i].second + dx[j]] != 'o') {
					board[indices[i].first + dy[j]][indices[i].second + dx[j]] = 'o';
					answer++;
				}
			}
		}

		for (int j = 0; j < n; j++) {
			for (int i = m - 1; i >= 0; i--) {
				if (board[i][j] != 'o') continue;

				for (int k = i - 1; k >= 0; k--) {
					if (board[k][j] != 'o') {
						char hold = board[k][j];
						board[k][j] = board[i][j];
						board[i][j] = hold;
						break;
					}
				}
			}
		}
	}

	return answer;
}

int main() {
	vector<string> v;
	v.push_back("CCBDE");
	v.push_back("AAADE");
	v.push_back("AAABF");
	v.push_back("CCBBF");
	solution(4, 5, v);
}