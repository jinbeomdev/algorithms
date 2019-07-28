#include <stdio.h>
#include <queue>
#include <string.h>
using namespace std;
int N, M;
int map[20][20];
int numHouses;
int answer;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
struct Data {
    int y, x, k;
    Data (int y, int x, int k) : y(y), x(x), k(k) { }
};
int main() {
    int TC;
    scanf("%d", &TC);
    for (int tc = 1; tc <= TC; tc++) {
        answer = 0;
        numHouses = 0;
        scanf("%d%d", &N,&M);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                scanf("%d", &map[i][j]);
                if(map[i][j] == 1) numHouses++;
            }
        }
        int maxCost = numHouses * M;
        int maxK = 1;
        while((maxK * maxK) + (maxK - 1) * (maxK - 1) <= maxCost) {
            maxK++;
        }
        maxK--;
        for (int i = 0; i < N; i++ ) {
            for (int j = 0; j < N; j++) {
                queue<Data> q;
                q.push(Data(i, j, 0));
                bool discovered[20][20];
                memset(discovered, false, sizeof(discovered));
                discovered[i][j] = true;
                int k = 1;
                int houses = 0;
                if(map[i][j] == 1) houses++;
                if(houses > 0 && answer == 0) answer = 1;
                while(!q.empty()) {
                    if(k > maxK) break;
                    int qSize = q.size();
                    for(int z = 0; z < qSize; z++) {
                        Data here = q.front();
                        q.pop();
                        // if(i == 3 && j == 6)
                        // printf("center(%d, %d) houses(%d) => here => y(%d), x(%d), level(%d)\n", i, j, houses, here.y, here.x, k);
                        for(int p = 0; p < 4; p++) {
                            int nextY = here.y + dy[p];
                            int nextX = here.x + dx[p];

                            if(nextY < 0 || nextY >= N) continue;
                            if(nextX < 0 || nextX >= N) continue;
                            if(discovered[nextY][nextX]) continue;
                            if(map[nextY][nextX] == 1) {
                                // if(i == 3 && j == 6)
                                // printf("nextY(%d) nextX(%d)\n", nextY, nextX);
                                houses++;
                            }
                            discovered[nextY][nextX] = true;
                            q.push(Data(nextY, nextX, here.k + 1));
                        }
                    }
                    k++;
                    int revenue = M * houses - (k * k + (k-1) * (k-1));
                    if(revenue >= 0) {
                        if(answer < houses) {
                            answer = houses;
                        }
                    }
                }
            }
        }
        printf("#%d %d\n", tc, answer);
    }
}