#include <stdio.h>

inline int max(const int &a, const int &b) {
    return (a < b) ? b : a;
}

int main() {
    int N, t, p;
    int dp[1500010];
    scanf("%d%d%d", &N, &t, &p);
    if(t <= N) dp[t] = p;
    for (int i = 1; i < N; i++) {
        scanf("%d%d", &t, &p);
        if(dp[i] < dp[i - 1]) dp[i] = dp[i - 1];
        if(i + t <= N) dp[i + t] = max(dp[i + t], dp[i] + p);
    }

    int maxV = 0;
    for(int i = 0; i <= N; i++) {
        maxV = max(maxV, dp[i]);
    }

    printf("%d", maxV);
    
    return 0;
}