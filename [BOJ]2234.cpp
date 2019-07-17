#include <stdio.h>
#include <string.h>

int N, M;
int map[50][50][4];
int visited[50][50];
int dy[] = {0, -1, 0, 1};
int dx[] = {-1, 0, 1, 0};
int rn = 0;
int rs[300];
int maxr = -1;

int dfs(int y, int x) {
    if(y < 0 || y >= M) return 0;
    if(x < 0 || x >= N) return 0;
    if(visited[y][x]) return 0;
    visited[y][x] = rn;
    int ret = 1;

    for(int i = 0; i < 4; i++) {
        if(map[y][x][i]) continue;
        int nx = x + dx[i];
        int ny = y + dy[i];
        ret += dfs(ny, nx);
    }

    return ret;
}

int main() {
    memset(visited, 0, sizeof(visited));
    memset(rs, 0, sizeof(rs));
    scanf("%d%d", &N, &M);
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            int w;
            scanf("%d", &w);
            for(int p = 0; p < 4; p++) {
                map[i][j][p] = ((1 << p) & w) ? 1 : 0;
            }
        }
    }

    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            if(visited[i][j]) continue;
            rn++;
            int ret = dfs(i, j);
            rs[rn] = ret;
            if(maxr < ret) maxr = ret;
        }
    }

    int mmrs = -1;
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            for(int p = 0; p < 4; p++) {
                if(!map[i][j][p]) continue;
                int ny = i + dy[p];
                int nx = j + dx[p];
                if(visited[i][j] == visited[ny][nx]) continue;
                int mrs = rs[visited[i][j]] + rs[visited[ny][nx]];
                if(mmrs < mrs) {
                    mmrs = mrs;
                }
            }
        }
    }
    printf("%d\n", rn);
    printf("%d\n", maxr);
    printf("%d\n", mmrs);
}