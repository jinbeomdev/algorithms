#include <stdio.h>

int K;
int A[4][8];

void shift(int a[4][8], int pos, int d) {
    int temp;
    if(d == 1) {
        temp = a[pos][7];
        for (int j = 7; j > 0; j--) {
            a[pos][j] = a[pos][j - 1];
        }
        a[pos][0] = temp;
        return;
    }

    temp = a[pos][0];
    for (int j = 0; j < 7; j++) {
        a[pos][j] = a[pos][j + 1];
    }
    a[pos][7] = temp;
    return;
}

int main() {
    int TC;
    scanf("%d", &TC);
    for (int tc = 1; tc <= TC; tc++) {
        int K;
        scanf("%d", &K);
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 8; j++) {
                scanf("%d", &A[i][j]);
            }
        }
        for (int i = 0; i < K; i++) {
            int pos, d;
            int tempD;
            scanf("%d%d", &pos, &d);
            pos--;
            int temp[4][8];
            for (int p = 0; p < 4; p++) {
                for (int q = 0; q < 8; q++) {
                    temp[p][q] = A[p][q];
                }
            }
            shift(temp, pos, d);
            tempD = d;
            for (int j = pos + 1; j < 4; j++) {
                if (A[j - 1][2] != A[j][6]) {
                    tempD *= -1;
                    shift(temp, j, tempD);
                } else {
                    break;
                }
            }
            tempD = d;
            for (int j = pos - 1; j >= 0; j--) {
                if (A[j][2] != A[j + 1][6]) {
                    tempD *= -1;
                    shift(temp, j, tempD);
                } else {
                    break;
                }
            }

            for (int p = 0; p < 4; p++) {
                for (int q = 0; q < 8; q++) {
                    A[p][q] = temp[p][q];
                } 
            }
        }
        int answer = 0;
        for (int i = 0; i < 4; i++) {
            answer += A[i][0] << i;
        }
        printf("#%d %d\n", tc, answer);
    }
}