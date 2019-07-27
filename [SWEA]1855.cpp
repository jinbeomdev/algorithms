#include <stdio.h>
#include <string.h>

#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

const int MAXN = (int)1e5 + 10;
const int INF = (int)1e8;

int depth[MAXN][MAXN];

int main() {
    int TC;
    
    scanf("%d", &TC);

    for (int tc = 1; tc <= TC; tc++) {
        vector<int> adj[MAXN];
        int N;
        
        scanf("%d", &N);

        for (int i = 0; i <= N; i++) {
            for (int j = 0; j <= N; j++) {
                depth[i][j] = ((i == j) ? 0 : INF);
            }
        }

        for (int n = 2; n <= N; n++) {
            int parent;
            scanf("%d", &parent);
            adj[parent].push_back(n);
            adj[n].push_back(parent);
            depth[parent][n] = 1;
            depth[n][parent] = 1;
        }

        depth[0][1] = 0;
        for (int k = 1; k <= N; k++) {
            for (int i = 1; i <= N; i++) {
                for (int j = 1; j <= N; j++) {
                    depth[i][j] = min(depth[i][j], depth[i][k] + depth[k][j]);
                }
            }
        }

        bool discovered[MAXN];
        queue<int> q;
        memset(discovered, false, sizeof(discovered));
        
        discovered[1] = true;
        q.push(1);

        int distance = 0;
        int prevNode = 0;
        while (!q.empty()) {
            int here = q.front();
            q.pop();

            printf("bfs => from(%d) -> here(%d)\n", prevNode, here);

            distance += depth[prevNode][here];
            printf("bfs => depth[%d][%d](%d)\n", prevNode, here, depth[prevNode][here]);
            prevNode = here;

            for (int i = 0; i < adj[here].size(); i++) {
                int next = adj[here][i];

                if (discovered[next]) continue;

                discovered[next] = true;
                q.push(next);
            }
        }

        printf("#%d %d\n", tc, distance);
    }
}