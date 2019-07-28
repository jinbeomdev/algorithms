#include <stdio.h>
#include <algorithm>

using namespace std;

const int INF = (int)1e8;

int main() {
    int TC;
    scanf("%d", &TC);
    for (int tc = 1; tc <= TC; tc++) {
        int cost[4];
        scanf("%d%d%d%d", cost, cost + 1, cost + 2, cost + 3);
        int input[12];
        int dp[12];
        fill(dp, dp + 12, INF);
        for (int i = 0; i < 12; i++) {
            scanf("%d", input + i);
        }

        dp[0] = min(cost[1], input[0] * cost[0]);
        dp[2] = cost[2];
        for (int i = 1; i < 12; i++) {
            if (i - 3 > -1) {
                dp[i] = min(dp[i], dp[i - 3] + cost[2]);
            }
            dp[i] = min(dp[i], dp[i - 1] + input[i] * cost[0]);
            dp[i] = min(dp[i], dp[i - 1] + cost[1]);
        }
        dp[11] = min(dp[11], cost[3]);
        printf("#%d %d\n", tc, dp[11]);
    }
}
