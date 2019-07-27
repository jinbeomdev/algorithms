#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

struct Data {
    int y, x, num, dir;
    Data (int y, int x, int num, int dir) : 
    y(y), x(x), num(num), dir(dir) { }

    bool operator< (const Data &rhs) const {
        if(y * 100 + x == rhs.y * 100 + rhs.x) {
            return num < rhs.num;
        }
        return y * 100 + x < rhs.y * 100 + rhs.x;
    }
};


int dy[] = {0, -1, 1, 0, 0}; //상하좌우
int dx[] = {0, 0, 0, -1, 1};
int reverseDir[] = {0, 2, 1, 4, 3};


int main() {
    int TC;
    scanf("%d", &TC);
    for (int tc = 1; tc <= TC; tc++) {
        int N, M, K;
        vector<Data> m;
        
        scanf("%d%d%d", &N, &M, &K);
        for (int k = 0; k < K; k++) {
            int y, x, num, dir;
            scanf("%d%d%d%d", &y, &x, &num, &dir);
            m.push_back(Data(y, x, num, dir));
        }

        while(M--) {
            // printf("M => %d\n", M);
            vector<Data> next;

            for (int i = 0; i < m.size(); i++) {
                Data here = m[i];
                here.y = m[i].y + dy[m[i].dir];
                here.x = m[i].x + dx[m[i].dir];

                if(here.y == 0 || here.x == 0 ||
                here.y == N - 1|| here.x == N -1) {
                    here.dir = reverseDir[here.dir];
                    here.num /= 2;
                }

                if(here.num == 0) continue; //dead

                next.push_back(here);
            }

            next.push_back(Data(101, 101, 10001, 0)); //보안관 역활
            sort(next.begin(), next.end());

            // for(int i = 0; i < next.size(); i++) {
            //     printf("next[%d] => %d %d %d %d\n", i, next[i].y, next[i].x, next[i].num, next[i].dir);
            // }

            vector<Data> alive;
            int sum = 0;
            for(int i = 0; i < next.size() - 1; i++) {
                if(next[i].y != next[i + 1].y ||
                next[i].x != next[i + 1].x) {
                    alive.push_back(Data(next[i].y, next[i].x, sum + next[i].num, next[i].dir));
                    sum = 0;
                    continue;
                }

                sum += next[i].num;
            }

            // for(int i = 0; i < alive.size(); i++) {
            //     printf("alive[%d] => %d %d %d %d\n", i, alive[i].y, alive[i].x, alive[i].num, alive[i].dir);
            // }

            m = alive;
        }

        int answer = 0;
        for (int i = 0; i < m.size(); i++) {
            answer += m[i].num;
        }
        printf("#%d %d\n", tc, answer);
    }
}