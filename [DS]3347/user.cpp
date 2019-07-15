#ifndef NULL
#define NULL 0
#endif

typedef unsigned short US;
typedef unsigned char UC;
typedef unsigned int UI;

const int ALM = 1100;
const int BLM = 50;

const int MOD = (1 << 16);

int N, M;

UC A[ALM][ALM], (*B)[BLM]; //2D-array pointer
int bCnt;

struct Node {
    int r, c;
    Node *next;
    Node *push_front(int nr, int nc, Node *nn) {
        r = nr, c = nc, next = nn;
        return this;
    }
} *htab[MOD], buf[ALM * ALM * 2];

void init(int n, int m) {
    N = n, M = m;
    for (int i = 0; i < MOD; i++) {
        htab[i] = NULL;
    }
    bCnt = 0;
}

void setEcb(unsigned char ecb[][1000]) {
    int i, j;
    for (i = 0; i < N; i++) {
        for(j = 0; j < N; j++) {
            A[i][j] = ecb[i][j];
        }
        for(j = 0; j < M; j++) {
            A[i][N + j] = A[i][j];
        }
    }
    for (i = 0; i < M; i++) {
        for (j = 0; j < N + M; j++) {
            A[N + i][j] = A[i][j];
        }
    }
    for(i = 0; i < N + M; i++) {
        for(j = 0; j < N + M; j++) {
            US hidx = *(US*)(A[i] + j);
            htab[hidx] = buf[bCnt++].push_front(i, j, htab[hidx]);
        }
    }
}

int check(int r, int c) {
    if(c < 0) return -1;
    int i, j, sr = N, sc = N, er = -1, ec = -1;
    int diffCnt = 0;
    for (i = 0; i < M; i++) {
        for (j = 0; j < M; j++) {
            if (A[r + i][c + j] != B[i][j]) {
                diffCnt++;
                if (diffCnt > 9) return -1;
                if (sr > i) sr = i;
                if (sc > j) sc = j;
                if (er < i) er = i;
                if (ec < j) ec = j;
                if (er - sr > 2 || ec - sc > 2) return -1;
            }
        }
    }
    if(diffCnt == 0) return 0;
    if((er - sr + 1) * (ec - sc + 1) != diffCnt) return - 1;
    return ((er - sr + 1) << 2) + (ec - sc + 1);
}

int testSample(unsigned char sample[][50]) {
    B = sample;
    US hidx1 = *(US*)(B[0]);
    US hidx2 = *(US*)(B[0] + M - 2);
    Node *p = htab[hidx1];
    for(; p; p = p->next) {
        int rv = check(p->r, p->c);
        if (rv >= 0) {
            return rv;
        }
    }

    p = htab[hidx2];
    for(; p; p = p->next) {
        int rv = check(p->r, p->c);
        if (rv >= 0) {
            return rv;
        }
    }

    return 0;
}