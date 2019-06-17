#ifndef NULL
#define NULL 0
#endif  // NULL

#include <stdio.h>

inline int min(const int lhs, const int rhs) { return lhs < rhs ? lhs : rhs; }
inline int max(const int lhs, const int rhs) { return lhs < rhs ? rhs : lhs; }

struct Data {
  int row;
  int col;
  Data *next;
};

const int MAX_N = 1000;
const int MAX_M = 20;
const int HASH_TABLE_SIZE = 10001;

int N;
int M;
int (*copiedAp)[MAX_N];

Data *hashTable[HASH_TABLE_SIZE];

Data dataSegment[MAX_N * MAX_N * 2];
int dataSegmentSize;

Data *getData(int r, int c) {
  dataSegment[dataSegmentSize].row = r;
  dataSegment[dataSegmentSize].col = c;
  return &dataSegment[dataSegmentSize++];
}

void init(int n, int ap[][1000], int m) {
  N = n;
  M = m;
  copiedAp = ap;
  dataSegmentSize = 0;

  long long int maskLow = (1 << m) - 1;
  long long int maskHigh = ((1 << 2 * m) - 1) - maskLow;

  for (int i = 0; i < HASH_TABLE_SIZE; i++) hashTable[i] = NULL;
  for (int i = 0; i <= n - m; i++) {
    long long int key = 0;
    long long int keyLow = 0;
    long long int keyHigh = 0;
    for (int j = 0; j < m - 1; j++) {
      keyLow = (keyLow << 1) + (long long int)ap[i][j];
      keyHigh = (keyHigh << 1) | ((long long int)ap[i + m - 1][j] << m);
    }

    for (int j = m - 1; j < n; j++) {
      keyLow = ((keyLow << 1) + (long long int)ap[i][j]) & maskLow;
      keyHigh =
          ((keyHigh << 1) + ((long long int)ap[i + m - 1][j] << m)) & maskHigh;
      key = keyHigh | keyLow;

      Data *data = getData(i, j - m + 1);
      data->next = hashTable[key % HASH_TABLE_SIZE];
      hashTable[key % HASH_TABLE_SIZE] = data;
    }
  }
}

bool isMatched(int r, int c, int bp[][20], int rotate, int userAns[], int nineR,
               int nineC) {
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < M; j++) {
      if (rotate == 0) {
        if (bp[i][j] != copiedAp[i + r][j + c]) return false;
        if (i == nineR && j == nineC) {
          userAns[2] = i + r;
          userAns[3] = j + c;
        }
      } else if (rotate == 1) {
        if (bp[M - 1 - j][i] != copiedAp[i + r][j + c]) return false;
        if (M - 1 - j == nineR && i == nineC) {
          userAns[2] = i + r;
          userAns[3] = j + c;
        }
      } else if (rotate == 2) {
        if (bp[M - 1 - i][M - 1 - j] != copiedAp[i + r][j + c]) return false;
        if (M - 1 - i == nineR && M - 1 - j == nineC) {
          userAns[2] = i + r;
          userAns[3] = j + c;
        }
      } else if (rotate == 3) {
        if (bp[j][M - 1 - i] != copiedAp[i + r][j + c]) return false;
        if (j == nineR && M - 1 - i == nineC) {
          userAns[2] = i + r;
          userAns[3] = j + c;
        }
      } else
        ;  //...
    }
  }

  return true;
}

int query(int bp[][20], int userAns[]) {
  int rotateDegree = 0;

  int nineR, nineC;
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < M; j++) {
      if (bp[i][j] == 9) {
        bp[i][j] = 1;
        nineR = i;
        nineC = j;
      }
    }
  }

  long long int key[4] = {0};
  long long int keyLow[4] = {0};
  long long int keyHigh[4] = {0};

  for (int i = 0; i < M; i++) {
    keyLow[0] = (keyLow[0] << 1) + (long long int)bp[0][i];  // 0
    keyHigh[0] = (keyHigh[0] << 1) + ((long long int)bp[M - 1][i] << M);

    keyLow[1] = (keyLow[1] << 1) + (long long int)bp[M - 1 - i][0];  // 90
    keyHigh[1] = (keyHigh[1] << 1) + ((long long int)bp[M - 1 - i][M - 1 - i]);

    keyLow[2] = (keyLow[2] << 1) + (long long int)bp[M - 1][M - 1 - i];  // 180
    keyHigh[2] = (keyHigh[2] << 1) + ((long long int)bp[0][M - 1 - i] << M);

    keyLow[3] = (keyLow[3] << 1) + (long long int)bp[i][M - 1];  // 270
    keyHigh[3] = (keyHigh[3] << 1) + ((long long int)bp[0][M - 1] << M);
  }

  key[0] = keyHigh[0] | keyLow[0];
  key[1] = keyHigh[1] | keyLow[1];
  key[2] = keyHigh[2] | keyLow[2];
  key[3] = keyHigh[3] | keyLow[3];

  for (int i = 0; i < 4; i++) {
    Data *data = hashTable[key[i] % HASH_TABLE_SIZE];
    bool isAnswerFinded = false;

    while (data != NULL) {
      if (isMatched(data->row, data->col, bp, i, userAns, nineR, nineC)) {
        userAns[0] = data->row;
        userAns[1] = data->col;
        rotateDegree = i;
        isAnswerFinded = true;
        break;
      }

      data = data->next;
    }

    if (isAnswerFinded) {
      break;
    }
  }

  return rotateDegree;
}