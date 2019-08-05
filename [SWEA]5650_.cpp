#include <stdio.h>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

struct Data {
    int x1, y1, x2, y2;

    Data () {
        x1 = y1 = x2 = y2 = -1;
    }

    bool check (int x, int y) {
        if (x == x1 && y == y1) return true;
        if (x == x2 && y == y2) return true;
        return false;
    }

    pii get (int x, int y) {
        pii ret;            
        if (x == x1 && y == y1) {
            ret = make_pair(x2, y2);
            return ret;
        }

        ret = make_pair(x1, y1);
        return ret;
    }

    void push (int x, int y) {
        if (x1 == -1 && x2 == -1) {
            x2 = x;
            y2 = y;
            return;
        }

        x1 = x;
        y1 = y;
    }
};

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int blockDir[6][4] = {
    {0, 0, 0, 0},
    {2, 3, 1, 0},
    {1, 3, 0, 2},
    {3, 2, 0, 1},
    {2, 0, 3, 1},
    {2, 3, 0, 1}
};

int map[110][110];
Data hole[11];

int N;

int main() {
    int TC;
    scanf("%d", &TC);
    for (int tc = 1; tc <= TC; tc++) {
        for (int i = 0; i < 11; i++) {
            hole[i] = Data();
        }
        scanf("%d", &N);
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                scanf("%d", &map[i][j]);

                if (map[i][j] > 5) {
                    hole[map[i][j]].push(i, j);
                }
            }
        }

        for (int i = 0; i <= N + 1; i++) {
            map[0][i] = map[i][0] = 5;
            map[N + 1][i] = map[i][N + 1] = 5;
        }

        // for (int i = 0; i < N + 2; i++ ){
        //     for(int j = 0; j < N + 2; j++) {
        //         printf("%d ", map[i][j]);
        //     }
        //     printf("\n");
        // }

        int answer = 0;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                for (int k = 0; k < 4; k++) {
                    if (map[i][j] != 0) continue;
                    int score = 0;
                    bool start = false;
                    int y = i, x = j, d = k;
                    // printf("새로시작\n");
                    while ((map[y][x] != -1) && !(start && y == i && x == j)) {
                        if(!start) start = true;
                        // printf("%d %d %d\n", y, x, d);
                        // getchar();
                        int nextY = y + dy[d];
                        int nextX = x + dx[d];

                        if (map[nextY][nextX] > 5) {
                            pii next = hole[map[nextY][nextX]].get(nextY, nextX);
                            y = next.first;
                            x = next.second;
                            continue;
                        }

                        if (map[nextY][nextX] > 0 && map[nextY][nextX] < 6) {
                            d =  blockDir[map[nextY][nextX]][d];
                            score++;
                        }

                        y = nextY;
                        x = nextX;
                    }
                    if (answer < score) {
                        answer = score;
                    }
                }
            }
        }

        printf("#%d %d\n", tc, answer);
    }
}