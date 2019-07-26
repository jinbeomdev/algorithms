#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <stdlib.h>

using namespace std;

typedef pair<int, int> pii;

int TC;
int N;
int aLenght;
int bLenght;
int yStairs[2];
int xStairs[2];
vector<pii> posPeople;
int answer;
vector<int> temp;
// int cnt;

void dfs(int n, vector<pii> &a, vector<pii> &b) {

    if(n == posPeople.size()) {
        temp.clear();
        for(int i = 0 ; i < a.size(); i++) {
            int distance = abs(a[i].first - yStairs[0]) + abs(a[i].second - xStairs[0]);
            temp.push_back(distance);
        }
        sort(temp.begin(), temp.end());

        for(int i = 0; i < temp.size() && i < 3; i++) {
            temp[i] = temp[i] + aLenght + 1;
        }
        for(int i = 3; i < temp.size(); i++) {
            if(temp[i - 3] > temp[i]) {
                temp[i] = temp[i - 3] + aLenght;
            } else {
                temp[i] = temp[i] + aLenght + 1;
            }
        }

        int aTime;
        if(temp.empty()) {
            aTime = 0;
        } else {
            aTime = temp.back();
        }

        temp.clear();
        for(int i = 0; i < b.size(); i++) {
            int distance = abs(b[i].first - yStairs[1]) + abs(b[i].second - xStairs[1]);
            temp.push_back(distance);
        }
        sort(temp.begin(), temp.end());

        for(int i = 0; i < temp.size() && i < 3; i++) {
            temp[i] = temp[i] + bLenght + 1;
        }
        for(int i = 3; i < temp.size(); i++) {
            if(temp[i - 3] > temp[i]) {
                temp[i] = temp[i - 3] + bLenght;
            } else {
                temp[i] = temp[i] + bLenght + 1;
            }
        }

        int bTime;
        if(temp.empty()) {
            bTime = 0;
        } else {
            bTime = temp.back();
        }

        if(answer > max(aTime, bTime)) {
            answer = max(aTime, bTime);

            // printf("a ");
            // for(int i = 0 ; i < a.size(); i++) {
            //     printf("%d,%d ", a[i].first, a[i].second);
            // }
            // printf("\n");

            // printf("b ");
            // for(int i = 0 ; i < b.size(); i++) {
            //     printf("%d,%d ", b[i].first, b[i].second);
            // }
            // printf("\n");

            // printf("answer %d\n", answer);
        }

        return;
    }

    a.push_back(posPeople[n]);
    dfs(n+1, a, b);
    a.pop_back();

    b.push_back(posPeople[n]);
    dfs(n+1, a, b);
    b.pop_back();
}

int main() {
    scanf("%d", &TC);

    for(int tc= 1; tc <= TC; tc++) {
        scanf("%d", &N);

        posPeople.clear();
        yStairs[0] = yStairs[1] = -1;
        xStairs[0] = xStairs[1] = -1;
        answer = (int)1e8;

        for(int i = 0; i < N ; i++ ) {
            for(int j = 0; j < N; j++) {
                int input;
                scanf("%d", &input);

                if(input == 1) {
                    posPeople.push_back(make_pair(i, j));
                    continue;
                }

                if(input > 1) {
                    if (yStairs[0] == -1) {
                        yStairs[0] = i;
                        xStairs[0] = j;
                        aLenght = input;
                    } else {
                        yStairs[1] = i;
                        xStairs[1] = j;
                        bLenght = input;
                    }
                }
            }
        }

        vector<pii> a;
        vector<pii> b;
        // cnt=0;
        dfs(0, a, b);
        // printf("%d", cnt);
        printf("#%d %d\n", tc, answer);
    }
}