#include <stdio.h>
#include <queue>

using namespace std;

struct Data {
    int id;
    int arriveTime;
    int spareTime;
    int aNum;
    int bNum;
    Data() {
        id = -1;
        arriveTime = -1;
        spareTime = -1;
        aNum = -1;
        bNum = -1;
    }
};

int N, M, K, A, B;
int aTime[9];
int bTime[9];
Data a[9];
Data b[9];
queue<Data> aQ;
queue<Data> bQ;
int answer;

int main() {
    int TC;
    scanf("%d", &TC);
    for (int tc = 1; tc <= TC; tc++) {
        aQ = queue<Data>();
        bQ = queue<Data>();
        answer = -1;
        scanf("%d%d%d%d%d", &N, &M, &K, &A, &B);
        for (int i = 0; i < N; i++) {
            a[i] = Data();
            scanf("%d", &aTime[i]);
        }

        for (int i = 0; i < M; i++) {
            b[i] = Data();
            scanf("%d", &bTime[i]);
        }

        for (int i = 0; i < K; i++) {
            int arriveTime;
            scanf("%d", &arriveTime);
            Data data = Data();
            data.id = i;
            data.arriveTime = arriveTime;
            aQ.push(data);
        }

        int curTime = 0;
        int numA = 0;
        while(!aQ.empty() || !bQ.empty() || numA) {
            for (int i = 0; i < N; i++) {
                if (aQ.empty()) continue;
                if (a[i].spareTime > 0) continue;
                if (aQ.front().arriveTime > curTime) continue;
                a[i] = aQ.front();
                a[i].spareTime = aTime[i];
                a[i].aNum = i;
                numA++;
                aQ.pop();
            }

            for (int i = 0; i < N; i++) {
                a[i].spareTime--;
                if(a[i].spareTime > 0) continue;
                if(a[i].id < 0) continue;
                bQ.push(a[i]);
                a[i] = Data();
                numA--;
            }

            for (int i = 0; i < M; i++) {
                if(bQ.empty()) continue;
                if(b[i].spareTime > 0) continue;
                b[i] = bQ.front();
                b[i].spareTime = bTime[i];
                b[i].bNum = i;
                bQ.pop();

                if(b[i].aNum == A - 1 && b[i].bNum == B - 1) {
                    if(answer == -1) answer = 0;
                    answer += b[i].id + 1;
                }
            }

            for (int i = 0; i < M; i++) {
                b[i].spareTime--;
                if(b[i].spareTime > 0) continue;
                if(b[i].id < 0) continue;
                b[i] = Data();
            }

            // printf("curTime(%d)\n", curTime);
            // for (int i = 0; i < N; i++) {
            //     printf("%d ", a[i].id);
            // }
            // printf("\n");
            // for (int i = 0; i < N; i++) {
            //     printf("%d ", b[i].id);
            // }
            // printf("\n");

            curTime++;
        }

        printf("#%d %d\n", tc, answer);
    }
}