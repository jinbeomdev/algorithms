int N;
int map[3010][3010];
int stime;
int ctime;
int an;
int bn;

int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};

struct data {
    int y, x;
    
    void push(int _y, int _x) {
        y = _y;
        x = _x;
    }
} a[10000], b[10000], *now, *next;

void userInit(int boardSize) {
    N = boardSize;
    ctime += 10;
    stime = ctime;
    an = bn = 0;
    now = a, next = b;
}

void toEgg(int r, int c) {
    r++, c++;
    if(map[r][c] == ctime) return;
    map[r][c] = ctime;
    now[an++].push(r, c);
}

void toImago(int r, int c, int d, int L) {
    r++, c++;
    int i;
    if(d == 0) {
        map[r][c] = ctime - 2;
    } else if(d == 1) {
        for(i = c; i < c + L && i <= N; i++) {
            map[r][i] = ctime - 2;
        }
    } else {
        for(int i = r; i < r + L && i <= N; i++) {
            map[i][c] = ctime - 2;
        }
    }
}

int isEgg(int y, int x) {
    int cnt = 0, ny, nx, i;
    for(i = 0; i < 8; i++) {
        ny = y + dy[i], nx = x + dx[i];
        if(map[ny][nx] == ctime) cnt++;
        if(cnt > 2) return 0;
    }
    return 1;
}

int getEggCount(int tick) {
    int etime = stime + tick, i, j, ny, nx;
    data *tmp;
    for (i = 0; i < an; i++) {
        if(map[now[i].y][now[i].x] == ctime) now[j++] = now[i];
    }
    an = j;
    while(ctime < etime) {
        bn = 0;
        for(i = 0; i < an; i++) {
            for(j =0; j < 8; j++) {
                ny = now[i].y + dy[j], nx = now[i].x + dx[j];
                if(map[ny][nx] < stime - 2 ||
                map[ny][nx] > ctime - 2) continue;
                if(isEgg(ny, nx)) {
                    next[bn++].push(ny, nx);
                    map[ny][nx] = ctime + 1;
                }
            }
        }
        tmp = now;
        now = next;
        next = tmp;
        an = bn;
        ctime++;
    }
    
    return an;
}