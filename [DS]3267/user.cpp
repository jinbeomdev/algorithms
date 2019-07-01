// *** user.cpp ***
struct Position {
    int y, x, dir;
};

#define MAXN 200
#define GOFORWARD 0
#define TURNRIGHT 1

extern void identify(int minimap[4][4]);
extern bool moving(int method);

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int N;
int map[MAXN][MAXN];
int key[MAXN][MAXN][4];  // map의 값을 3진수로 표현하고 4*4 배열씩 윈도우
                         // 슬라이딩하여 10진수로 변환한 값을 저장 + 4방향

struct Data {
    int y, x, d;
    void push(int _y, int _x, int _d) {
        y = _y;
        x = _x;
        d = _d;
    }
} queue[MAXN * MAXN * 4];

int head, tail;

void encode(int sy, int sx) {
  for (int i = 0; i < 4; i++) {
    key[sy][sx][i] = 0;
  }

  for (int i = sy - 1; i < sy + 3; i++) {
    for (int j = sx - 1; j < sx + 3; j++) {
      key[sy][sx][0] = key[sy][sx][0] * 3 + map[i][j];
    }
  }

  for (int j = sx + 2; j >= sx - 1; j--) {
    for (int i = sy - 1; i < sy + 3; i++) {
        key[sy][sx][1] = key[sy][sx][1] * 3 + map[i][j];
    }
  }

  for(int i = sy + 2; i >= sy - 1; i--) {
      for(int j = sx + 2; j >= sx - 1; j--) {
          key[sy][sx][2] = key[sy][sx][2] * 3 + map[i][j];
      }
  }

  for(int j = sx - 1; j < sx + 3; j++) {
      for(int i = sy + 2; i >= sy - 1; i--) {
          key[sy][sx][3] = key[sy][sx][3] * 3 + map[i][j];
      }
  }
}

void userInit(int n, int Map[MAXN][MAXN]) {
  N = n;

  // copy
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      map[i][j] = Map[i][j];
      if (map[i][j] == -1) map[i][j] = 2;
    }
  }

  // encode
  for (int i = 1; i <= N - 3; i++) {
    for (int j = 1; j <= N - 3; j++) {
      encode(i, j);
    }
  }
}

int getKey() {
    int minimap[4][4];
    identify(minimap);
    int key = 0;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if(minimap[i][j] == -1) minimap[i][j] = 2;
            key = key * 3 + minimap[i][j];
        }
    }
    return key;
}

Position pos_search() {
    int here = getKey();


    /*
     * 모든 후보를 큐에 삽입
     */
    head = tail = 0;
    for(int i = 1; i <= N - 3; i++) {
        for(int j = 1; j <= N - 3; j++) {
            for(int d = 0; d < 4; d++) {
                if(key[i][j][d] == here) {
                    queue[tail++].push(i, j, d);
                }
            }
        }
    }

    /*
     * 모든 후보를 테스트
     * 한 칸 움직이고 여전히 일치하는지 검사
     */
    while(tail > 1) {
        for(int d = 0; d < 4; d++) {
            if(moving(0)) break;
            moving(1);
            for(int i = 0; i < tail; i++) {
                queue[i].d = (queue[i].d + 1) % 4;
            }
        }

        /*
         * 한 칸 움직이고 모든 후보에 대해 검사 
         */
        here = getKey();
        head = 0;
        for(int i = 0; i < tail; i++) {
            /*
             * 후보도 한 칸 전진
             */
            queue[i].y += dy[queue[i].d];
            queue[i].x += dx[queue[i].d];

            /*
             * 일치한 경우 다시 큐에 삽입
             */
            if(here == key[queue[i].y][queue[i].x][queue[i].d]) {
                queue[head++].push(queue[i].y, queue[i].x, queue[i].d);
            }
        }
        tail = head;
    }

    Position ret;
    ret.y = queue[0].y;
    ret.x = queue[0].x;
    ret.dir = queue[0].d;

    return ret;
}