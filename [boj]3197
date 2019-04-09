#include <stdio.h>
#include <queue>

using namespace std;

typedef pair<int ,int> pii;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int R, C;
char map[1500][1500];
bool vwater[1500][1500];
bool vduck[1500][1500];
int sy, sx, ey, ex;

int main() {
    queue<pii> water;
    queue<pii> nwater;
    queue<pii> duck;
    queue<pii> nduck;
    sy=sx=ey=ex=-1;
    scanf("%d%d", &R, &C);
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            scanf(" %c", &map[i][j]);
            if(map[i][j] == '.') {
                water.push(make_pair(i, j));
                vwater[i][j] = true;
            }

            if(map[i][j] == 'L') {
                if(sy == -1) {
                    sy = i;
                    sx = j;
                    vduck[i][j] = true;
                    duck.push(make_pair(i, j));
                } else {
                    ey = i;
                    ex = j;
                }
                map[i][j] = '.';
                water.push(make_pair(i ,j));
                vwater[i][j] = true;
            }
        }
    }
    
    for(int i = 0;;i++) {
        while(!water.empty()) {
            int y = water.front().first;
            int x = water.front().second;
            water.pop();
            map[y][x] = '.';
            for(int j = 0; j < 4; j++) {
                int ny = y + dy[j];
                int nx = x + dx[j];
                if(ny < 0 || ny >= R) continue;
                if(nx < 0 || nx >= C) continue;
                if(vwater[ny][nx]) continue;
                if(map[ny][nx] == '.') {
                    water.push(make_pair(ny, nx));
                    vwater[ny][nx] = true;
                } else {
                    nwater.push(make_pair(ny, nx));
                    vwater[ny][nx] = true;
                }
            }
        }
        while(!duck.empty()) {
            int y = duck.front().first;
            int x = duck.front().second;
            duck.pop();
            for(int j = 0; j < 4; j++) {
                int ny = y + dy[j];
                int nx = x + dx[j];
                if(ny < 0 || ny >= R) continue;
                if(nx < 0 || nx >= C) continue;
                if(vduck[ny][nx]) continue;
                if(map[ny][nx] == '.') {
                    duck.push(make_pair(ny, nx));
                    vduck[ny][nx] = true;
                } else {
                    nduck.push(make_pair(ny, nx));
                    vduck[ny][nx] = true;
                }
            }
        }
        if(vduck[ey][ex]) {
            printf("%d\n", i);
            break;
        }

        water = nwater;
        duck  = nduck;
        nwater = queue<pii>();
        nduck = queue<pii>();
    }
    return 0;
}