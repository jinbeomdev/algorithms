#include <stdio.h>
#include <string.h>

int N;
int numArr[12];
int opArr[4];
int useOpArr[12];
int maxAnswer;
int minAnswer;

int cal(int op, int a, int b) {
    if(op == 0) {
        return a + b;
    } else if(op == 1) {
        return a - b;
    } else if(op == 2) {
        return a * b;
    } else {
        return a / b;
    }
}

void dfs (int idx) {
    if(idx == N - 1) {
        int result = numArr[0];
        // printf("oper => ");
        for (int i = 1; i < N; i++) {
            // printf("%d ", useOpArr[i - 1]);
            result = cal(useOpArr[i - 1], result, numArr[i]);
        }
        // printf("\n<== result(%d)\n", result);
        if(maxAnswer < result) {
            maxAnswer = result;
        }
        if(minAnswer > result) {
            minAnswer = result;
        }
        return;
    }

    for(int i = 0; i < 4; i++) {
        if(opArr[i] < 1) continue;
        opArr[i]--;
        useOpArr[idx] = i;
        dfs(idx + 1);
        opArr[i]++;
    }
}

int main() {
    int TC;
    scanf("%d", &TC);
    for (int tc = 1; tc <= TC; tc++) {
        memset(numArr, 0, sizeof(numArr));
        memset(opArr, 0, sizeof(numArr));
        memset(useOpArr, 0, sizeof(useOpArr));
        scanf("%d", &N);
        for (int j = 0; j < 4; j++) {
            scanf("%d", &opArr[j]);
        }
        for (int i = 0; i < N; i++) {
            scanf("%d", &numArr[i]);
        }
        maxAnswer = (int)-1e9;
        minAnswer = (int)1e9;

        dfs(0);
        printf("#%d %d\n", tc, maxAnswer - minAnswer);
    }
}