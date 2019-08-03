#include <stdio.h>
#include <queue>
#include <string.h>

using namespace std;

struct Data {
    int y, x;
    Data (int y, int x) : y(y), x(x) { }
};

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};


int N, M;
int map[750][750];
bool canBeRhombus;
int size;
int qSize;
bool discovered[750][750];
queue<Data> q;
int answer;

int main() {
    int TC;
    scanf("%d", &TC);
    for (int tc = 1; tc <= TC; tc++) {
        answer = 0;
        scanf("%d%d", &N, &M);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                scanf("%1d", &map[i][j]);
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                q = queue<Data>();
                q.push(Data(i, j));
                memset(discovered, false, sizeof(discovered));
                discovered[i][j] = true;
                size = 1;
                if(map[i][j] == 1 && answer == 0) answer = size;
                bool forBreak = false;
                while (!q.empty()) {
                    qSize = q.size();

                    if (size == ((N < M) ? M : N)) {
                        break;
                    }

                    canBeRhombus = true;
                    for (int p = 0; p < qSize; p++) {
                        Data here = q.front();
                        q.pop();

                        for (int dir = 0; dir < 4; dir++) {
                            int nextY = here.y + dy[dir];
                            int nextX = here.x + dx[dir];

                            if (nextY < 0 || nextY >= N) {
                                forBreak = true;
                                break;
                            }
                            if (nextX < 0 || nextX >= M) {
                                forBreak = true;
                                break;
                            }
                            if (discovered[nextY][nextX]) continue;
                            if (map[nextY][nextX] == 0) {
                                canBeRhombus = false;
                            }
                            discovered[nextY][nextX] = true;
                            q.push(Data(nextY, nextX));

                            // printf("y(%d), x(%d), size(%d)\n", i, j, size);
                            // for (int n = 0; n < N; n++) {
                            //     for (int m = 0; m < M; m++) {
                            //         printf("%d", discovered[n][m] == true ? 1 : 0);
                            //     }
                            //     printf("\n");
                            // }
                            // printf("\n");
                        }

                        if(forBreak) break;
                    }

                    if(forBreak) break;

                    if(canBeRhombus && answer < size) {
                        printf("y(%d), x(%d), size(%d)\n", i, j, size);
                        answer = size;
                    }

                    size++;
                }
            }
        }

        printf("#%d %d\n", tc, answer);
    }
}