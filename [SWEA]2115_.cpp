#include <stdio.h>

int N, M, C;
int map[10][10];
int maxV;
void dfs(int y, int start, int finish, int power, int sum) {
    if(sum > C) return;
    if(start > finish) {
        if(maxV < power) {
            maxV = power;
        }
        return;
    }
    dfs(y, start + 1, finish, power, sum);
    dfs(y, start + 1, finish, power + map[y][start] * map[y][start], sum + map[y][start]);
    return;
}
int main() {
    int TC;
    scanf("%d", &TC);
    for (int tc = 1; tc <= TC; tc++) {
        scanf("%d%d%d", &N, &M, &C);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                scanf("%d", &map[i][j]);
            }
        }
        int answer = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N - M + 1; j++) {
                for (int k = i; k < N; k++) {
                    int l;
                    if (k == i) {
                        l = j + M;
                    } else {
                        l = 0;
                    }
                    int temp;
                    for (; l < N - M + 1; l++) {
                        temp = 0;
                        maxV = 0;
                        dfs(i, j, j + M - 1, 0, 0);
                        temp += maxV;
                        // printf("1 => %d, %d ~ %d(%d)\n", i, j, j + M - 1, maxV);
                        maxV = 0;
                        dfs(k, l, l + M - 1, 0, 0);
                        temp += maxV;
                        // printf("2 => %d, %d ~ %d(%d)\n", k, l, l + M - 1, maxV);
                        if(answer < temp) {
                            answer = temp;
                        }
                    }
                }
            }
        }

        printf("#%d %d\n", tc, answer);
    }
}