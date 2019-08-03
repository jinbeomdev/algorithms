#include <stdio.h>
#include <string.h>

int N, X;
int map[20][20];

void go(int build[20], int begin, int finish) {
    for (int i = begin; i <= finish; i++) {
        build[i] = 1;
    }
}

bool isBuild(int build[20], int begin, int finish) {
    for (int i = begin; i <= finish; i++) {
        if(build[i] != 0) return false;
    }
    return true;
}

bool can(int temp[20], int begin, int finish) {
    if (begin < 0) return false;
    if (finish >= N) return false;
    for (int i = begin; i < finish; i++) {
        if(temp[i] != temp[i + 1]) return false;
    }
    return true;
}

bool check(int temp[20]) {
    int build[20];
    memset(build, 0, sizeof(build));
    for(int i = 0; i < N - 1; i++) {
        if(temp[i] < temp[i + 1]) {
            if(temp[i + 1] - temp[i] != 1)  return false;
            if(!can(temp, i - X + 1, i)) return false;
            if(!isBuild(build, i - X + 1, i)) return false;
            go(build, i - X + 1, i);
        }
        if(temp[i] > temp[i + 1]) {
            if(temp[i] - temp[i + 1] != 1)  return false;
            if(!can(temp, i + 1, i + X)) return false;
            if(!isBuild(build, i + 1, i + X)) return false;
            go(build, i + 1, i + X);
        }
    }

    // printf("success =>\n");
    // for(int i = 0; i < N; i++) {
    //     printf("%d", temp[i]);
    // }
    // printf("\n");
    return true;
}

int main() {
    int TC;
    scanf("%d", &TC);
    for (int tc = 1; tc <= TC; tc++) {
        scanf("%d%d", &N, &X);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                scanf("%d", &map[i][j]);
            }
        }
        int answer = 0;
        for(int i = 0; i < N; i++) {
            int temp[20];
            for(int j = 0; j < N; j++) {
                temp[j] = map[i][j];
            }
            if(check(temp)) answer++;
            for (int j = 0; j < N; j++) {
                temp[j] = map[j][i];
            }
            if(check(temp)) answer++;
        }
        printf("#%d %d\n", tc, answer);
    }
}