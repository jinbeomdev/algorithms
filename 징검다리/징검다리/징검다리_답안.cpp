#include <iostream> 
#include <cstdio> 
#include <vector> 
#include <memory.h> 
using namespace std;
#define MOD 1000000009 
#define MAXN 50500 
int T, N, K, L;
int dp[MAXN][101];
vector<bool> mine;
int main()
{
	setbuf(stdout, NULL);
	scanf("%d", &T);
	for (int t = 1; t <= T; t++)
	{
		memset(dp, 0, sizeof(dp));
		scanf("%d%d%d", &N, &K, &L);
		mine = vector<bool>(N + 1, false);
		for (int i = 1; i <= L; i++)
		{
			int tmp; scanf("%d", &tmp); mine[tmp] = true;
		}
		//N번째 징검다리에 오면 개울을 건넌 것이므로 모두 1로 초기화 한다. 
		for (int j = 1; j <= K; j++)
			dp[N][j] = 1;
		for (int i = N - 1; i >= 1; i--)
		{ //지뢰가 있으면 dp[i][1~K]값이 모두 0이므로 넘어간다.
			if (mine[i]) continue;
			//시그마는 한번만 계산 
			int sum = 0;
			for (int p = 1; p <= K; p++)
				sum = (sum + dp[i + p][p]) % MOD;
			//점화식 
			for (int j = 1; j <= K; j++)
			{
				dp[i][j] = (sum + MOD - dp[i + j][j]) % MOD;
			}
		}
		int ans = 0;
		for (int j = 1; j <= K; j++)
			ans = (ans + dp[j][j]) % MOD;
		printf("Case #%d\n%d\n", t, ans);

	} return 0;

}