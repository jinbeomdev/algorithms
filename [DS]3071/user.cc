/**
 * 블럭의 쌍을 찾을 때 접점(?) 부분이 중요하기 때문에 몸통(?) 부분은 필요없다
 * 나의 쌍이 될 ******값******을 미리 저장해놓는 방법이 필요하다
 * 그리고 단순히 블록을 저장하면 매번 블록을 비교할 때 16번 탐색을 해야한다
 * 블록의 값(4*4)을 하나의 값으로 저장해놓는 방법(해싱)이 필요하다
 */
#include <algorithm>

using namespace std;

const int MAX = 30000;

inline int max(const int &lhs, const int &rhs) {
  return (lhs < rhs) ? rhs : lhs;
}

inline int min(const int &lhs, const int &rhs) {
  return (lhs < rhs) ? lhs : rhs;
}

struct Data {
  int _id;
  long long _code;
  int _minHeight;
  int _diff;
  int _isMatched;

  Data() : _id(0), _code(0), _minHeight(0), _diff(0), _isMatched(false) {}

  Data(int id, int code, int minHeight, int diff)
      : _id(id),
        _code(code),
        _minHeight(minHeight),
        _diff(diff),
        _isMatched(false) {}

  bool operator<(const Data &rhs) const {
    if (_code == rhs._code) return _minHeight < rhs._code;
    return _code < rhs._code;
  }
} face[MAX + 5], back[MAX + 5];
int faceSize, backSize;

int getCode(int module[][4]) {
  int ret[4] = {0};

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      ret[0] = ret[0] * 3 + module[i][j];
      ret[1] = ret[1] * 3 + module[j][3 - i];
      ret[2] = ret[2] * 3 + module[3 - i][3 - j];
      ret[3] = ret[3] * 3 + module[3 - j][i];
    }
  }

  int minRet = ret[0];

  for (int i = 1; i < 4; i++) {
    minRet = min(minRet, ret[i]);
  }

  return minRet;
}

void preprocess(int id, int module[][4]) {
  int faceTemp[4][4], backTemp[4][4];
  int minHeight = 10, maxHeight = 0, diff;

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      minHeight = min(minHeight, module[i][j]);
      maxHeight = max(maxHeight, module[i][j]);
    }
  }

  diff = maxHeight = minHeight;

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      faceTemp[i][j] = module[i][j] - minHeight;
      backTemp[i][3- j] = diff - faceTemp[i][j];
    }
  }

  face[faceSize++] = Data(id, getCode(faceTemp), minHeight, diff);
  back[backSize++] = Data(id, getCode(backTemp), minHeight, diff);
}

int makeTree(int module[][4][4]) {
  int ans = 0;
  faceSize = 0;
  backSize = 0;

  for (int i = 0; i < MAX; i++) {
    preprocess(i, module[i]);
  }

  sort(face, face + faceSize);
  sort(back, back + backSize);

/*
 * 이 부분도 다시 한번 보자....
 * 투 포인트....
 */
  int i = 0;
  int j = 0;
  while (i < faceSize && j < backSize) {
    while (i < faceSize && face[i]._isMatched) i++;
    while (j < backSize && !back[j]._isMatched) j++;
    if (face[i]._code == back[j]._code) {
      if (face[i]._id == back[j]._id) {
        j++;
      } else {
        ans += face[i]._minHeight + back[j]._minHeight + face[i]._diff;
        face[i]._isMatched = back[j]._isMatched = true;
        i++;
        j++;
      }
    } else if (face[i]._code < back[j]._code) {
      j++;
    } else {
      i++;
    }
  }
  // implement here

  return ans;
}