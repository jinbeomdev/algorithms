#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> _rotate(const vector<vector<int>> &key) {
    vector<vector<int>> rotated;

    for (int i = 0; i < key[0].size(); i++) {
        vector<int> row;

        for (int j = key.size() - 1; j > -1; j--) {
            row.push_back(key[j][i]);
        }

        rotated.push_back(row);
    }

    return rotated;
}

vector<vector<int>> rotate(const vector<vector<int>> &key, int degree) {
    vector<vector<int>> rotated = key;

    for (int i = 0; i < degree; i++) {
        rotated = _rotate(rotated);
    }

    return rotated;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    int cnt = 0;
    int keyCnt = 0;

    for (int jj = 0; jj < lock.size(); jj++) {
        for (int kk = 0; kk < lock[jj].size(); kk++) {
            if (lock[jj][kk] == 0) cnt++;
        }
    }

    for (int jj = 0; jj < key.size(); jj++) {
        for (int kk = 0; kk < key.size(); kk++) {
            if (key[jj][kk] == 1) keyCnt++;
        }
    }

    if (cnt > keyCnt) return false;

    for (int i = 0; i < 4; i++) {
        vector<vector<int>> rotated = rotate(key, i);

        for (int j = 0; j < lock.size(); j++) {
            for (int k = 0; k < lock[j].size(); k++) {
                int compareCnt = 0;
                bool b1 = false;

                for (int jj = j; jj < j + rotated.size(); jj++) {
                    for (int kk = k; kk < k + rotated[j].size(); kk++) {
                        if (jj >= lock.size() || kk >= lock.size()) continue;

                        if (lock[jj][kk] != rotated[jj - j][kk - k]) {
                            if(lock[jj][kk] == 0) compareCnt++;
                        } else {
                            b1 = true;
                            break;
                        }
                    }

                    if(b1) break;
                }

                if (!b1 && compareCnt == cnt) return true;
            }
        }
    }

    return false;
}