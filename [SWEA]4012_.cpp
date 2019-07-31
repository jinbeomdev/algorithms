#include <stdio.h>
#include <stdlib.h>

int N;
int map[16][16];
int a[16];
int b[16];
int answer;

void dfs(int idx, int aSize, int bSize) {
    if(idx == N) {
        if(aSize != bSize) return;
        int aSum = 0;
        int bSum = 0;
        for(int i = 0; i < N / 2 - 1; i++) {
            for(int j = i + 1; j < N / 2; j++) {
                aSum += map[a[i]][a[j]] + map[a[j]][a[i]];
            }
        }
        for(int i = 0; i < N / 2 - 1; i++) {
            for(int j = i + 1; j < N / 2; j++) {
                bSum += map[b[i]][b[j]] + map[b[j]][b[i]];
            }
        }
        if(answer > abs(aSum - bSum)) {
            answer = abs(aSum - bSum);
        }
        return;
    }
    a[aSize] = idx;
    dfs(idx + 1, aSize + 1, bSize);
    b[bSize] = idx;
    dfs(idx + 1, aSize, bSize + 1);
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

        answer = (int)1e9;
        dfs(0, 0, 0);

        printf("#%d %d\n", tc, answer);
    }
}

/**
a => 1 2 3
b => 0 4 5
<== aSum(193), bSum(167)

s12=>15 s21=>33
s13=>26 s31=>10
s23=>79 s32=>66
 */

