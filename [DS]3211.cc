#include <stdio.h>
#include <assert.h>
#include <string.h>

#include <queue>

using namespace std;

/*
* 퍼즐 타입 0 : 0, F : 1, M : 2
*/

/**
 *  3
 * 2 0
 *  1 
 **/
int OppsiteIdx[4] = {2, 3, 0, 1};
int OppsitePuzzle[3] = {0, 2, 1};
int N, M;

/*
* puuzle 최대 크기 16
* 각면 4개
*/
int eachPuzzles[2500][4][16];

/*
* 각 퍼즐에 매칭되는 퍼즐 인덱스
*/
int matchedIdx[2500][4];

int main()
{
    memset(matchedIdx, -1, sizeof(matchedIdx));
    scanf("%d %d%*c%*c", &N, &M);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                for (int l = 0; l < M; l++)
                {
                    char input;
                    int intInput;
                    scanf("%c", &input);

                    if (input == '0')
                        intInput = 0;
                    else if (input == 'F')
                        intInput = 1;
                    else if (input == 'M')
                        intInput = 2;

                    eachPuzzles[i * N + j][k][l] = intInput;
                }
                scanf("%*c%*c");
            }
        }
    }

/*
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {    
            for(int k = 0; k < 4; k++) {
                for(int l = 0; l < M; l++) {
                    printf("%d", eachPuzzles[i * N + j][k][l]);
                }
                puts("");
            }
            puts("");
            puts("");
        }
    }
*/

for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
        for(int k = 0; k < 4; k++) {
            if(matchedIdx[i * N + j][k] != -1) continue;

            bool isFind2 = false;
            for(int l = 0; l < N; l++) {
                for(int m = 0; m < N; m++) {
                    if(l == i && m == j) continue;
                    
                    bool isFind = true;
                    for(int n = 0; n < M; n++) {
                        if(eachPuzzles[i * N + j][k][n]
                            != OppsitePuzzle[eachPuzzles[l * N + m][OppsiteIdx[k]][n]]) {
                                isFind = false;
                            }
                    }

                    if(isFind) {
                        matchedIdx[i * N + j][k] = l * N + m;
                        matchedIdx[l * N + m][OppsiteIdx[k]] = i * N + j;
                        isFind2 = true;
                        break;
                    }
                }
                if(isFind2) break;
            }
        }
    }
}

/*
   for(int i = 0; i < N; i++) {
       for(int j = 0; j < N; j++) {
           for(int k = 0; k < 4; k++) {
               printf("%d : %d\n", i * N + j, matchedIdx[i * N + j][k]);
           }
       }
   }
*/
//0,0 위치에 놓이는 퍼즐의 2번과 3번의 모서리 부분은 -1이다
    int answer[50][50];
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(matchedIdx[i * N + j][2] == -1 && matchedIdx[i * N + j][3] == -1) {
                answer[0][0] = i * N + j;
            }
        }
    }

    for(int i = 1; i < N; i++) {
        answer[i][0] = matchedIdx[answer[i - 1][0]][1];
    }

    for(int i = 0; i < N; i++) {
        for(int j = 1; j < N; j++) {
            answer[i][j] = matchedIdx[answer[i][j - 1]][0];
        }
    }

    for(int i = 0; i < 4; i++) {
        int a, b;
        scanf("%d%d", &a, &b);;
    printf("%d ", answer[a][b]);
    }

}