#include <stdio.h>
#include <stdlib.h>
#include <queue>

using namespace std;

struct Data {
    int y, x, t;
    bool o;
    int oY, oX;

    Data() {}
    Data(int _y, int _x, int _t, bool _o, int _oY = -1, int _oX = -1) {
        y = _y, x = _x, t = _t;
        o = _o;
        oY = _oY;
        oX = _oX;
    }
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
    if(x - 1 > - 1 && map[y][x-1] == 0) h = true;
    if(x + 1 < N && map[y][x + 1] == 0) h = true;
    return v && h;
}

void outputDebug(Data here) {
    printf("here => y:%d, x:%d, t:%d, o:%s, oY:%d, oX:%d\n",
    here.y,
    here.x,
    here.t,
    here.o ? "true" : "false",
    here.oY,
    here.oX
    );
}

int main() {
    scanf("%d%d", &N, &M);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    Data answer;
    queue<Data> q;
    q.push(Data(0, 0, 0, false));
    visited[0][0] = 1;

    while(!q.empty()) { 
        Data here = q.front();
        q.pop();

        if(here.y == N - 1 &&
           here.x == N - 1) {
               answer = here;
               break;
        }

        for(int i = 0; i < 4; i++) {
            int nextY = here.y + dy[i];
            int nextX = here.x + dx[i];

            if(nextY < 0 || nextY >= N) continue;
            if(nextX < 0 || nextX >= N) continue;

            if(visited[nextY][nextX]) continue;

            if(map[here.y][here.x] > 1) {
                if(map[nextY][nextX] == 0) continue;
                if(map[nextY][nextX] > 1) continue;
                if(here.t % map[here.y][here.x]) {
                    Data temp = here;
                    temp.t++;
                    q.push(temp);
                } else {
                    visited[nextY][nextX] = 1;
                    q.push(Data(nextY, nextX, here.t + 1, here.o, here.oY, here.oX));
                }
            } else if(here.o && here.y == here.oY && here.x == here.oX) {
                if(map[nextY][nextX] == 0) continue;
                if(map[nextY][nextX] > 1) continue;
                if(here.t % M) {
                    Data temp = here;
                    temp.t++;
                    q.push(temp);
                } else {
                    visited[nextY][nextX] = 1;
                    q.push(Data(nextY, nextX, here.t + 1, here.o, here.oY, here.oX));
                }
            } else {
                if(map[nextY][nextX] == 0) {
                    if(here.o) continue;
                    if(!canBuildO(nextY, nextX)) continue;
                    visited[nextY][nextX] = 1;
                    q.push(Data(nextY, nextX, here.y + 1, true, nextY, nextX));
                } else {

                    visited[nextY][nextX] = 1;
                    q.push(Data(nextY, nextX, here.t + 1, here.o, here.oY, here.oX));
                }
            }
        }
    }

    printf("%d", answer.t);
}