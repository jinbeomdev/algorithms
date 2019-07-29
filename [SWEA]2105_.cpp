#include <stdio.h>
#include <string.h>

int N;
int map[20][20];
bool visited[20][20];
bool desert[101];
int startY;
int startX;
int answer;

const int dy[] = {1, 1, -1, -1};
const int dx[] = {1, -1, -1, 1};

void dfs(int hereY, int hereX, int dir, int cnt) {
    // printf("dfs => hereY(%d), hereX(%d), dir(%d), cnt(%d)\n", hereY, hereX, dir, cnt);

    for (int i = 0; i < 2; i++) {
        if(dir + i > 3) continue;

        int nextY = hereY + dy[dir + i];
        int nextX = hereX + dx[dir + i];

        // printf("next => nextY(%d), next(%d), nextDir(%d)\n", nextY, nextX, dir + i);

        if (nextY == startY && nextX == startX) {
            if (answer < cnt) {
                // printf("answer => startY(%d), startX(%d), cnt(%d)\n", startY, startX, cnt);
                answer = cnt;
            }

            return;
        }

        if(nextY < 0 || nextY >= N) continue;
        if(nextX < 0 || nextX >= N) continue;
        if(visited[nextY][nextX]) continue;
        if(desert[map[nextY][nextX]]) continue;

        visited[nextY][nextX] = true;
        desert[map[nextY][nextX]] = true;
        dfs(nextY, nextX, dir + i, cnt + 1);
        visited[nextY][nextX] = false;
        desert[map[nextY][nextX]] = false;
    }
}

int main() {
    int TC;
    scanf("%d", &TC);
    for (int tc = 1; tc <= TC; tc++) {
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                scanf("%d", &map[i][j]);
            }
        }

        answer = -1;
        memset(visited, false, sizeof(visited));
        memset(desert, false, sizeof(desert));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                startY = i;
                startX = j;
                visited[i][j] = true;
                desert[map[i][j]] = true;
                dfs(i, j, 0, 1);
                visited[i][j] = false;
                desert[map[i][j]] = false;
            }
        }
        // startY = 0;
        // startX = 1;
        // visited[0][1] = true;
        // desert[map[0][1]] = true;
        // dfs(0, 1, 0, 1);
        // visited[0][1] = false;
        // desert[map[0][1]] = false;
        printf("#%d %d\n", tc, answer);
    }
}