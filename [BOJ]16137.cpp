#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>

using namespace std;

struct Data {
    int y, x, t;

    Data() {}
    Data(int y, int x, int t) : y(y), x(x), t(t) {}
};

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int N, M;
int map[10][10];
int visited[10][10];

bool canBuildO (int y, int x) {
    bool h = false, v = false;
    if(y - 1 > -1 && map[y - 1][x] == 0) v = true;
    if(y + 1 < N && map[y + 1][x] == 0) v = true;
    if(x - 1 > -1 && map[y][x - 1] == 0) h = true;
    if(x + 1 < N && map[y][x + 1] == 0) h = true;
    return !(v && h);
}

int main() {
    scanf("%d%d", &N, &M);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    int answer = (int)1e8;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(!(map[i][j] == 0)) continue;
            if(!canBuildO(i, j)) continue;

            map[i][j] = M;

            bool discovered[10][10];
            memset(discovered, false, sizeof(discovered));
            discovered[0][0] = true;
            queue<Data> q;
            q.push(Data(0, 0, 0));

            while(!q.empty()) {
                Data here = q.front();
                q.pop();

                if(here.y == N - 1 &&
                   here.x == N - 1) {
                    if(answer > here.t) {
                        answer = here.t;
                        break;
                    }
                }

                for(int p = 0; p < 4; p++) {
                    int nextY = here.y + dy[p];
                    int nextX = here.x + dx[p];
                    
                    if(nextY < 0 || nextY >= N) continue;
                    if(nextX < 0 || nextX >= N) continue;
                    if(discovered[nextY][nextX]) continue;
                    if(map[here.y][here.x] > 1 && map[nextY][nextX] > 1) continue;
                    if(map[nextY][nextX] == 0) continue;

                    if(map[here.y][here.x] > 1) {
                        if(here.t % map[here.y][here.x] == 0) {
                            discovered[nextY][nextX] = true;
                            q.push(Data(nextY, nextX, here.t + 1));
                        } else {
                            q.push(Data(here.y, here.x, here.t + 1));
                        }
                    } else {
                        discovered[nextY][nextX] = true;
                        q.push(Data(nextY, nextX, here.t + 1));
                    }
                }
            }
        
            map[i][j] = 0;
        }
    }

    printf(
        "%d", answer
    );

    return 0;
}