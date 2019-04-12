#include <stdio.h>
#include <stdlib.h>

int T;
int N;
int num_oper[4];
int num[12];
int min_answer;
int max_answer;

int cal(int oper, int a, int b) {
    if(oper == 0) return a + b;
    else if(oper == 1) return a - b;
    else if(oper == 2) return a * b;
    else return a / b;
}

void dfs(int idx, int ret) {
    if(idx == N - 1) {
        if(min_answer > ret) min_answer = ret;
        if(max_answer < ret) max_answer = ret;
        return;
    }

    for(int i = 0; i < 4; i++) {
        if(num_oper[i] > 0) {
            num_oper[i] -= 1;
            dfs(idx + 1, cal(i, ret, num[idx + 1]));
            num_oper[i] += 1;
        }
    }
}

int main() {
    scanf("%d", &T);

    for(int tc = 1; tc <= T; tc++) {
        min_answer = 100000001;
        max_answer = -100000001;
        scanf("%d", &N);

        for(int i = 0; i < 4; i++) {
            scanf("%d", num_oper + i);
        }

        for(int i = 0; i < N; i++) {
            scanf("%d", num + i);
        }

        dfs(0, num[0]);

        printf("#%d %d\n", tc, abs(max_answer - min_answer));
    }
}