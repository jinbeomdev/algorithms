#include <stdio.h>

int N, C;
int nArr[20];
int answer = 0;

void dfs(int idx, int power, int cnt) {
    if(cnt > C) return;
    if(idx > N) return;

    if(answer < power) {
        answer = power;
    }

    dfs(idx + 1, power + nArr[idx] * nArr[idx], cnt + nArr[idx]);
    dfs(idx + 1, power, cnt);
}

int main() {
    int TC;
    scanf("%d", &TC);
    for (int tc = 1; tc <= TC; tc++) {
        answer = 0;
        scanf("%d%d", &N, &C);
        for (int i = 0; i < N; i++) {
            scanf("%d", &nArr[i]);
        }
        dfs(0, nArr[0] * nArr[0], nArr[0]);
        dfs(0, 0, 0);

        printf("#%d %d\n", tc, answer);
    }
}