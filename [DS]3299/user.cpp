
int N, M;

inline long long int min(const long long int &lhs, const long long int &rhs) {
  return lhs < rhs ? lhs : rhs;
}
inline long long int max(const long long int &lhs, const long long int &rhs) {
  return lhs < rhs ? rhs : lhs;
}

struct Data {
  int row;
  int col;
  int encode;

  bool operator<(const Data &rhs) const { return encode < rhs.encode; }
} _data[1000 * 1000];
int dataSize;
int isSorted;
int (*copiedAp)[1000];

void swap(Data &lhs, Data &rhs) {
  Data temp = lhs;
  lhs = rhs;
  rhs = temp;
}

int partition(int low, int high) {
  Data pivot = _data[high];  // pivot
  int i = (low - 1);         // Index of smaller element

  for (int j = low; j <= high - 1; j++) {
    // If current element is smaller than or
    // equal to pivot
    if (_data[j].encode <= pivot.encode) {
      i++;  // increment index of smaller element
      swap(_data[i], _data[j]);
    }
  }
  swap(_data[i + 1], _data[high]);
  return (i + 1);
}

/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
void quickSort(int low, int high) {
  if (low < high) {
    /* pi is partitioning index, arr[p] is now
       at right place */
    int pi = partition(low, high);

    // Separately sort elements before
    // partition and after partition
    quickSort(low, pi - 1);
    quickSort(pi + 1, high);
  }
}

long long int encode(int bp[][20]) {
  long long int encode[4] = {0};

  for (int p = 0; p < M; p++) {
    for (int q = 0; q < M; q++) {
      encode[0] = encode[0] * 2 + ((bp[p][q] == 9) ? 1 : bp[p][q]);  // 0
      encode[1] = encode[1] * 2 +
                  ((bp[M - 1 - q][p] == 9) ? 1 : bp[M - 1 - q][p]);  // 90
      encode[2] = encode[2] * 2 + ((bp[M - 1 - p][M - 1 - q] == 9)
                                       ? 1
                                       : bp[M - 1 - p][M - 1 - q]);  // 180;
      encode[3] = encode[3] * 2 +
                  ((bp[q][M - 1 - p] == 9) ? 1 : bp[q][M - 1 - p]);  // 270;
    }
  }

  long long ret = encode[0];

  for (int i = 1; i < 4; i++) {
    ret = min(ret, encode[i]);
  }

  return ret;
}

void init(int n, int ap[][1000], int m) {
  N = n;
  M = m;
  dataSize = 0;
  isSorted = false;
  copiedAp = ap;

  for (int i = 0; i <= n - m; i++) {
    for (int j = 0; j <= n - m; j++) {
      int bp[20][20];

      for (int p = 0; p < m; p++) {
        for (int q = 0; q < m; q++) {
          bp[p][q] = ap[i + p][j + q];
        }
      }

      _data[dataSize].row = i;
      _data[dataSize].col = j;
      _data[dataSize++].encode = encode(bp);
    }
  }
}

void find(const Data &data, int &r, int &c, int &rotate, int bp[][20]) {
  bool var1, var2, var3, var4;
  var1 = var2 = var3 = var4 = true;

  int userAns[4][2];

  for (int p = 0; p < M; p++) {
    for (int q = 0; q < M; q++) {
      if (bp[p][q] == 9) {
        bp[p][q] = 1;
        r = p + data.row;
        c = p + data.col;
      } else if (bp[M - 1 - q][p] == 9) {
        bp[p][q] = 1;
        r = p + data.row;
        c = p + data.col;
      } else if (bp[M - 1 - p][M - 1 - q] == 9) {
        bp[p][q] = 1;
        r = p + data.row;
        c = p + data.col;
      } else if (bp[q][M - 1 - p] == 9) {
        bp[p][q] = 1;
        r = p + data.row;
        c = p + data.col;
      }

      if (var1) {
        if (bp[p][q] != copiedAp[p + data.row][q + data.col]) {
          var1 = false;
        }
      } else if (var2) {
        if (bp[M - 1 - q][p] != copiedAp[p + data.row][q + data.col]) {
          var2 = false;
        }
      } else if (var3) {
        if (bp[M - 1 - p][M - 1 - q] != copiedAp[p + data.row][q + data.col]) {
          var3 = false;
        }
      } else if (var4) {
        if (bp[q][M - 1 - p] != copiedAp[p + data.row][q + data.col]) {
          var4 = false;
        }
      } else {
        return;
      }
    }
  }

  if (var1) {
    rotate = 0;
  } else if (var2) {
    rotate = 1;
  } else if (var3) {
    rotate = 2;
  } else {
    rotate = 3;
  }

  return;
}

int query(int bp[][20], int userAns[]) {
  if (!isSorted) {
    quickSort(0, dataSize - 1);
    isSorted = true;
  }
  int row = 0, col = 0;

  int left = 0, right = dataSize - 1, mid;
  int key = encode(bp);

  while (left <= right) {
    mid = (left + right) / 2;

    if (key < _data[mid].encode) {
      right = mid - 1;
    } else if (key > _data[mid].encode) {
      left = mid + 1;
    } else {
      break;
    }
  }

  userAns[0] = _data[mid].col;
  userAns[1] = _data[mid].col;

  int rotate;
  find(_data[mid], userAns[2], userAns[3], rotate, bp);
  return rotate;
}