#include <stdio.h>

int D, W, K;
int map[13][20];
int answer;

bool check() {
    for (int p = 0; p < W; p++) {
        int maxA = 0;
        int maxB = 0;
        int tempA = 0;
        int tempB = 0;
        for (int q = 0; q < D - 1; q++) {
            if(map[q][p] == 0 && map[q + 1][p] == 0) {
                if(tempA == 0) tempA = 2;
                else tempA++;
            } else {
                tempA = 0;
            }
            if(maxA < tempA) {
                maxA = tempA;
            }

            if(map[q][p] == 1 && map[q + 1][p] == 1) {
                if(tempB == 0) tempB = 2;
                else tempB++;
            } else {
                tempB = 0;
            }
            if(maxB < tempB) {
                maxB = tempB;
            }
        }

        if(maxA < K && maxB < K) return false;
    }

    return true;
}

void dfs(int i, int cnt) {
    if (cnt >= answer) return;

    if(i == D) {
        if(!check()) return;

        if(answer > cnt) {
            answer = cnt;
        }

        return;
    }

    int temp[20];
    for (int j = 0; j < W; j++) {
        temp[j] = map[i][j];
    }
    //투입 X
    dfs(i + 1, cnt);

    //투입 A
    for (int j = 0; j < W; j++) {
        map[i][j] = 0;
    }
    dfs(i + 1, cnt + 1);
    for (int j = 0; j < W; j++) {
        map[i][j] = temp[j];
    }

    //투입 B;
    for (int j = 0; j < W; j++) {
        map[i][j] = 1;
    }
    dfs(i + 1, cnt + 1);
    for (int j = 0; j < W; j++) {
        map[i][j] = temp[j];
    }
}

int main() {
    int TC;
    scanf("%d", &TC);
    for (int tc = 1; tc <= TC; tc++) {
        scanf("%d%d%d", &D, &W, &K);
        for (int i = 0; i < D; i++) {
            for (int j = 0; j < W; j++) {
                scanf("%d", &map[i][j]);
            }
        }

        answer = (int)1e8;
        dfs(0, 0);

        printf("#%d %d\n", tc, answer);
    }
}