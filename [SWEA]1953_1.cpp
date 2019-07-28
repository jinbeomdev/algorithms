#include <stdio.h>
#include <queue>
#include <string.h>

using namespace std;

struct Data {
    int y, x, time;
    Data (int y, int x, int time) :
        y(y), x(x), time(time) { }
};

int dy[8][4] = {
    {0, 0, 0, 0},
    {-1, 1, 0, 0},
    {-1, 1, 0, 0},
    {0, 0, 0, 0},
    {-1, 0, 0, 0},
    {1, 0, 0, 0},
    {1, 0, 0, 0},
    {-1, 0, 0, 0}
};

int dx[8][4] = {
    {0, 0, 0, 0},
    {0, 0, -1, 1},
    {0, 0, 0, 0,},
    {-1, 1, 0, 0},
    {0, 1, 0, 0},
    {0, 1, 0, 0},
    {0, -1, 0, 0},
    {0, -1, 0, 0},
};

int map[50][50];
bool discovered[50][50];

bool canBack(int hereY, int hereX, int nextY, int nextX) {
    int type = map[nextY][nextX];
    int size = 2;
    if (type == 1) size = 4;
    for (int i = 0; i < size; i++) {
        int y = nextY + dy[type][i];
        int x = nextX + dx[type][i];

        if(y == hereY && x == hereX) return true;
    }
    return false;
}

int main() {
    int TC;
    scanf("%d", &TC);

    for (int tc = 1; tc <= TC; tc++) {
        int N, M, R, C, L;
        scanf("%d%d%d%d%d", &N, &M, &R, &C, &L);

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                scanf("%d", &map[i][j]);
            }
        }

        queue<Data> q;
        q.push(Data(R, C, 1));
        memset(discovered, false, sizeof(discovered));
        discovered[R][C] = true;

        int answer = 1;
        while(!q.empty()) {
            Data here = q.front();
            q.pop();
            // printf("here => map[%d][%d](%d), y(%d), x(%d), time(%d)\n", here.y, here.x, map[here.y][here.x], here.y, here.x, here.time);

            if (here.time == L) continue;

            int type = map[here.y][here.x];
            int dSize = 2;
            if (type == 1) dSize = 4;
            for (int i = 0; i < dSize; i++) {
                int nextY = here.y + dy[type][i];
                int nextX = here.x + dx[type][i];
                // printf("next => y(%d), x(%d)\n", nextY, nextX);
                
                if (nextY < 0 || nextY >= N) continue;
                if (nextX < 0 || nextX >= M) continue;
                if (map[nextY][nextX] == 0) continue;
                if (discovered[nextY][nextX]) continue;
                if (!canBack(here.y, here.x, nextY, nextX)) continue;
                
                discovered[nextY][nextX] = true;
                answer++;
                q.push(Data(nextY, nextX, here.time + 1));
            }
        }

        printf("#%d %d\n", tc, answer);
    }
}