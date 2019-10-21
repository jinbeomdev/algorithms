#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int _time[510] = {0,};
int indegree[510] = {0,};
vector<int> adj[510];

int main() {
    int N;
    scanf("%d", &N);
    for (int v = 1; v <= N; v++) {
        int t, u;
        scanf("%d", &t);
        _time[v] = t;
        while(true) {
            scanf("%d", &u);
            if (u == -1) break;
            // printf("adj[%d].push_back(%d)\n", u, v);
            adj[u].push_back(v);
            indegree[v]++;
        }
    }

    queue<int> q;
    int result[510] = {0,};
    for (int v = 1; v <= N; v++) {
        if (indegree[v] == 0) {
            // printf("indegree[%d] == 0\n", v);
            result[v] = _time[v];
            q.push(v);
        }
    }
    for (int i = 1; i <= N; i++) {
        int v = q.front();
        q.pop();
        // printf("pop %d\n", v);
        for (int j = 0; j < adj[v].size(); j++) {
            int next = adj[v][j];
            result[next] = max(result[next], result[v] + _time[next]);
            indegree[next]--;
            if (indegree[next] == 0) {
                // printf("push %d\n", next);
                q.push(next);
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        printf("%d\n", result[i]);
    }
}