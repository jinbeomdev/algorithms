#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, -1, 1};

struct Data {
    int y, x, d, k;

    Data() { }
    Data(int y, int x, int d, int k) : y(y), x(x), d(d), k(k) { }
    bool operator< (const Data &rhs) const {
        return y * 1000 + x < rhs.y * 1000 + rhs.x;
    }
};

vector<Data> data;
vector<Data> temp;

int main() {
    int TC;
    scanf("%d", &TC);
    for (int tc = 1; tc <= TC; tc++) {
        data.clear();
        int N;
        scanf("%d", &N);
        for (int n = 0; n < N; n++) {
            Data d;
            scanf("%d%d%d%d", &d.x, &d.y, &d.d, &d.k);
            d.x *= 2;
            d.y *= 2;
            data.push_back(d);
        }

        int answer = 0;
        while(!data.empty()) {
            temp.clear();
            for (int i = 0; i < data.size(); i++) {
                // printf("data[%d] => y(%d), x(%d), d(%d), k(%d)\n", i, data[i].y, data[i].x, data[i].d, data[i].k);
                // getchar();
                int nextY = data[i].y + dy[data[i].d];
                int nextX = data[i].x + dx[data[i].d];
                
                if (nextY < -2000 || nextY > 2000) continue;
                if (nextX < -2000 || nextX > 2000) continue;

                temp.push_back(Data(nextY, nextX, data[i].d, data[i].k));
            }

            data.clear();
            temp.push_back(Data(2001, 2001, 0, 0));
            sort(temp.begin(), temp.end());

            int sum = 0;
            for (int i = 0; i < temp.size() - 1; i++) {
                if(temp[i].y == temp[i + 1].y && temp[i].x == temp[i + 1].x) {
                    if(sum == 0) {
                        sum = temp[i].k + temp[i + 1].k;
                    } else {
                        sum += temp[i + 1].k;
                    }
                } else {
                    answer += sum;
                    if (sum == 0) {
                        data.push_back(Data(temp[i].y, temp[i].x, temp[i].d, temp[i].k));
                    }
                    sum = 0;
                }
            }
        }

        printf("#%d %d\n", tc, answer);
    }
}