#include <stdio.h>
 
#define MAX_ECB_SIZE 1000
#define MAX_SAMPLE_SIZE 50
 
static int N, M;
static unsigned char ecb[MAX_ECB_SIZE][MAX_ECB_SIZE];
static unsigned char sample[MAX_SAMPLE_SIZE][MAX_SAMPLE_SIZE];
 
static unsigned int seed;
static unsigned int myRand() {
    seed = seed * 1103515245 + 12345;
    return seed;
}
 
extern void init(int n, int m);
extern void setEcb(unsigned char ecb[][1000]);
extern int testSample(unsigned char sample[][50]);
 
static void makeECB() {
    int i, j;
    for (i = 0; i < N; ++i) {
        for (j = 0; j < N; ++j) {
            ecb[i][j] = myRand() % 255 + 1;
        }
    }
    for (i = 0; i < N; ++i) {
        ecb[0][i] = ecb[N - 1][i] = 0;
        ecb[i][0] = ecb[i][N - 1] = 0;
    }
    setEcb(ecb);
}
 
static int run(int tc) {
    int sr = myRand() % N;
    int sc = myRand() % N;
    int dr = myRand() % M;
    int dc = myRand() % M;
    int h = myRand() % 3 + 1;
    int w = myRand() % 3 + 1;
 
    int i, j, r, c;
    int flag = 0;
 
    for (i = 0; i < M; ++i) {
        for (j = 0; j < M; ++j) {
            r = (i + sr) % N, c = (j + sc) % N;
            sample[i][j] = ecb[r][c];
        }
    }
 
    if (h && w && sample[dr][dc]) {
        for (i = 0; i < h && dr + i < M; ++i) {
            if (sample[dr + i][dc] == 0) break;
        }
        h = i;
        for (i = 0; i < w && dc + i < M; ++i) {
            if (sample[dr][dc + i] == 0) break;
        }
        w = i;
 
        for (i = 0; i < h; ++i) {
            for (j = 0; j < w; ++j) {
                int num = myRand() % 255 + 1;
                while (sample[dr + i][dc + j] == num) {
                    num = myRand() % 255 + 1;
                }
                sample[dr + i][dc + j] = num;
            }
        }
        flag = 1;
    }
 
    if (flag == 0) {
        h = w = 0;
    }
 
    int userResult = testSample(sample);
    int ans = h * 4 + w;
    if (userResult != ans) {
        int debug = 1;
    }
    return (userResult == ans) * 100;
}
 
int main() {
    //freopen("input.txt", "r", stdin);
    int TC, totalScore, queryCnt;
    int i, j;
    scanf("%d", &TC);
    for (i = 1; i <= TC; ++i) {
        scanf("%u %d %d %d", &seed, &N, &M, &queryCnt);
        init(N, M);
        makeECB();
        totalScore = 0;
        for (j = 1; j <= queryCnt; ++j) {
            int sc = run(j);
            totalScore += sc;
        }
        printf("#case %d : %d\n", i, totalScore / queryCnt);
    }
    return 0;
}