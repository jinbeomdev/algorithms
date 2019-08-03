#include <stdio.h>
#include <queue>
#include <string.h>
#include <stdlib.h>

using namespace std;

const int dy[] = {0, -1, 0, 1, 0};
const int dx[] = {0, 0, 1, 0, -1};

struct Pos {
    int y, x;
    Pos () { }
    Pos (int y, int x) : y(y), x(x) { }
};

struct Info {
    Pos pos;
    int c, p;
    Info () { }
    Info (Pos pos, int c, int p) : pos(pos), c(c), p(p) { }
};

int map[11][11][8];
int path[2][101]; //0 : a, 1 : b
Pos a;
Pos b;
Info bc[8];
int M, A;
int main() {
    int TC;
    scanf("%d", &TC);
    for (int tc = 1; tc <= TC; tc++) {
        scanf("%d%d", &M, &A);
        for (int i = 0; i < 2; i++) {
            for (int j = 1; j <= M; j++) {
                scanf("%d", &path[i][j]);
            }
        }
        for (int i = 0; i < A; i++) {
            scanf("%d%d%d%d", &bc[i].pos.x, &bc[i].pos.y, &bc[i].c, &bc[i].p);
        }
        int answer = 0;

        a.y = a.x = 1;
        b.y = b.x = 10;
        for (int t = 0; t <= M; t++) {
            a.y = a.y + dy[path[0][t]];
            a.x = a.x + dx[path[0][t]];
            b.y = b.y + dy[path[1][t]];
            b.x = b.x + dx[path[1][t]];

            int best = 0;
            for (int i = 0; i < A; i++) {
                for (int j = 0; j < A; j++) {
                    int ab = (abs(a.y - bc[i].pos.y) + abs(a.x - bc[i].pos.x) <= bc[i].c) ? bc[i].p : 0;
                    int bb = (abs(b.y - bc[j].pos.y) + abs(b.x - bc[j].pos.x) <= bc[j].c) ? bc[j].p : 0;
                    if(i == j && ab > 0 && bb > 0) {
                        ab /= 2;
                        bb /= 2;
                    }
                    if(best < ab+ bb) {
                        best = ab + bb;
                    }
                }
            }
            answer += best;
        }
        printf("#%d %d\n", tc, answer);
    }
}