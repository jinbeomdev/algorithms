#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, pair<int, int> > piii;
typedef pair<int, int> pii;

int N, M;

int map[50][50];

int numBlank = 0;
vector<pii> posVirus;
vector<pii> selectedVirus;
int answer = -1;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

void dfs(int idx, int cnt) {
    if(cnt == M) {

        int tempNumBlank = numBlank;
        queue<piii> q;

        int tempMap[50][50];
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                tempMap[i][j] = map[i][j];
            }
        }

        for(int i = 0; i < selectedVirus.size(); i++) {
            tempMap[selectedVirus[i].first][selectedVirus[i].second] = 2;
            q.push(make_pair(0, selectedVirus[i]));
        }

        while(!q.empty()) {
            int here_t = q.front().first;
            int here_y = q.front().second.first;
            int here_x = q.front().second.second;
            q.pop();

            if(tempNumBlank == 0) {
                if(answer == -1) {
                    answer = q.back().first;
                } else {
                    if(answer > q.back().first) {
                        answer = q.back().first;
                    }
                }
                break;
            }

            for(int i = 0; i < 4; i++) {
                int next_y = here_y + dy[i];
                int next_x = here_x + dx[i];

                if(next_y < 0 || next_y >= N) continue;

                if(next_x < 0 || next_x >= N) continue;

                if(tempMap[next_y][next_x] == 1) continue;

                if(tempMap[next_y][next_x] == 2) continue;
                
                if(tempMap[next_y][next_x] == 0) tempNumBlank--;

                tempMap[next_y][next_x] = 2;
                q.push(make_pair(here_t + 1, make_pair(next_y, next_x)));
            }
        }

        return;
    }//end if cnt == M

    if(idx == posVirus.size()) {
        return;
    }//end if idx == posVirus.size()

    selectedVirus.push_back(make_pair(posVirus[idx].first, posVirus[idx].second));
    dfs(idx + 1, cnt + 1);
    selectedVirus.pop_back();

    dfs(idx + 1, cnt);
}

int main() {
    scanf("%d%d", &N, &M);
    for(int i = 0 ; i < N; i++) {
        for(int j = 0; j < N; j++) {
            scanf("%d", &map[i][j]);

            if(map[i][j] == 0) numBlank++;

            if(map[i][j] == 2) {
                posVirus.push_back(make_pair(i, j));
                map[i][j] = 3;
            }
        }
    }

    dfs(0, 0);

    printf("%d", answer);
}