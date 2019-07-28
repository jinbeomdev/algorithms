#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int N, K;
bool visited[10][10];

int map[10][10];

inline int max(int a, int b) {
    return a > b ? a : b;
}

struct Data {
    int y;
    int x;
    int length;
    bool cut;

    Data(int y, int x, int length, bool cut) :
    y(y), x(x), length(length), cut(cut) { }
};

int dfs(Data here) {
    // printf("here => y(%d), x(%d), length(%d), cut(%s)\n",
    // here.y,
    // here.x,
    // here.length,
    // here.cut ? "true" : "false");

    int maxLength = here.length;

    for (int i = 0; i < 4; i++) {
        int nextY = here.y + dy[i];
        int nextX = here.x + dx[i];

        if (nextY < 0 || nextY >= N) continue;
        if (nextX < 0 || nextX >= N) continue;
        if (visited[nextY][nextX]) continue;

        if (map[nextY][nextX] >= map[here.y][here.x]) {
            if (here.cut) continue;
            
            int diff = map[nextY][nextX] - map[here.y][here.x];

            if(K < diff + 1) continue;
            
            visited[nextY][nextX] = true;
            int temp = map[nextY][nextX];
            map[nextY][nextX] -= diff + 1;
            maxLength = 
                max(maxLength,
                    dfs(Data(nextY, nextX, here.length + 1, true)));
            visited[nextY][nextX] = false;
            map[nextY][nextX] = temp;
            continue;
        }

        visited[nextY][nextX] = true;
        maxLength = 
            max(maxLength,
                dfs(Data(nextY, nextX, here.length + 1, here.cut)));
        visited[nextY][nextX] = false;;
    }

    return maxLength;
}

int main() {
    int TC;
    scanf("%d", &TC);
    for (int tc = 1; tc <= TC; tc++) {
        vector<Data> high;

        scanf("%d%d", &N, &K);
        int maxV = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                scanf("%d", &map[i][j]);
                maxV = max(maxV, map[i][j]);
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if(maxV == map[i][j])
                    high.push_back(Data(i, j, 0, false));
            }
        }

        memset(visited, false, sizeof(visited));
        int answer = 0;
        for (int i = 0; i < high.size(); i++) {
            visited[high[i].y][high[i].x] = true;
            answer = max(answer, dfs(Data(high[i].y, high[i].x, 1, false)));
            visited[high[i].y][high[i].x] = false;
        }

        printf("#%d %d\n", tc, answer);
    }
}