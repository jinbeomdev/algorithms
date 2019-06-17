const int MAX_HASH_TABLE = 10079;
const int MAX_N = 1000;
const int MAX_M = 20;
int N, M;

struct Data {
  int row;
  int col;
  Data *next;
};

Data *hashTable[MAX_HASH_TABLE];
Data dataSegment[MAX_N * MAX_N * 2];
int dataSegmentUsed;

int (*copiedAp)[MAX_N];

Data *getData(int r, int c) {
  dataSegment[dataSegmentUsed].row = r;
  dataSegment[dataSegmentUsed].col = c;
  return &dataSegment[dataSegmentUsed++];
}

void init(int n, int ap[][1000], int m) {
  int mask = (1 << m) - 1;

  N = n;
  M = m;
  copiedAp = ap;
  dataSegmentUsed = 0;

  for (int i = 0; i < MAX_HASH_TABLE; i++) hashTable[i] = 0;
  for (int i = 0; i < n; i++) {
    int key = 0;
    for (int j = 0; j < m - 1; j++) {
      key = (key << 1) + ap[i][j];
    }

    for (int j = m - 1; j < n; j++) {
      key = ((key << 1) + ap[i][j]) & mask;
      Data *data = getData(i, j - m + 1);
      data->next = hashTable[key % MAX_HASH_TABLE];
      hashTable[key % MAX_HASH_TABLE] = data;
    }
  }
}

bool isMatched(int r, int c, int bp[][20]) {
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < M; j++) {
      if (copiedAp[i + r][j + c] != bp[i][j]) return false;
    }
  }
  return true;
}

int query(int bp[][20]) {
  int key = 0;
  for (int i = 0; i < M; i++) {
    key = (key << 1) + bp[0][i];
  }

  Data *data = hashTable[key % MAX_HASH_TABLE];

  while (data != 0) {
    if (isMatched(data->row, data->col, bp)) break;
    data = data->next;
  }

  return data->row * N + data->col;
}