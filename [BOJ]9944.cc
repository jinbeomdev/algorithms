#include <stdio.h>

int N, M;
char map[30][30];
int num_dots;
int answer;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

bool can(int here_y, int here_x) {
    if(here_y < 0 || here_y >= N) return false;

    if(here_x < 0 || here_x >= M) return false;

    return true;
}

void dfs(int here_y, int here_x, int cnt, int level) { //cnt : 빈칸의 개수, level 회전한 횟수
    if(cnt == num_dots) {
        if(answer == -1) {
            answer = level;
        } else {
            if(answer > level) {
                answer = level;
            }
        }
       return; 
    }

    for(int i = 0; i < 4; i++) {
        int next_y = here_y + dy[i];
        int next_x = here_x + dx[i];

        if(!can(next_y, next_x)) continue;

        if(map[next_y][next_x] == '*') continue;

        while(can(next_y, next_x) && map[next_y][next_x] == '.') {
            map[next_y][next_x] = '*';
            cnt += 1;
            next_y += dy[i];
            next_x += dx[i];
        }
        next_y -= dy[i];
        next_x -= dx[i];

        //printf("%d %d -> %d %d %d\n", here_y, here_x, next_y, next_x, cnt);
        dfs(next_y, next_x, cnt, level + 1);

        while(!(next_y == here_y && next_x == here_x)) {
            map[next_y][next_x] = '.';
            cnt -= 1;
            next_y -= dy[i];
            next_x -= dx[i];
        }
    }
}

int main() {
    int tc = 1;
    while(scanf("%d %d", &N, &M) != EOF) {
        num_dots = 0;
        answer = -1;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                scanf(" %c", &map[i][j]);
                if(map[i][j] == '.') num_dots++;
            }
        }

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(map[i][j] == '*') continue;
                map[i][j] = '*';
                dfs(i, j, 1, 0);
                map[i][j] = '.';
            }
        }

        printf("Case %d: %d\n", tc, answer);
        tc+=1;
    }
}