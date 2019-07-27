#include <stdio.h>
#include <string.h>

#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

const int MAXN = (int)1e5 + 10;
const int INF = (int)1e8;

vector<int> adj[MAXN];
bool discovered[MAXN];
bool discovered2[MAXN];


int getDistance(int from, int to, const vector<int> adj[MAXN]) {
    queue<pii> q;
    q.push(make_pair(from , 0));

    memset(discovered2, false, sizeof(discovered2));
    discovered2[from] = true;


    while(!q.empty()) {
        int here = q.front().first;
        int distance = q.front().second;
        q.pop();

        if(here == to) {
            return distance;
        }

        for (int i = 0; i < adj[here].size(); i++) {
            int next = adj[here][i];
            
            if (discovered2[next]) continue;

            discovered2[next] = true;
            q.push(make_pair(next, distance + 1));
        }
    }

    return INF;
}

int main() {
    int TC;
    
    scanf("%d", &TC);

    for (int tc = 1; tc <= TC; tc++) {
        int N;
        
        scanf("%d", &N);

        for(int i = 1; i <= N; i++) {
            adj[i].clear();
        }

        for (int n = 2; n <= N; n++) {
            int parent;
            scanf("%d", &parent);
            adj[parent].push_back(n);
            adj[n].push_back(parent);
        }

        queue<int> q;
        memset(discovered, false, sizeof(discovered));
        
        discovered[1] = true;
        q.push(1);

        int distance = 0;
        int prevNode = 1;
        while (!q.empty()) {
            int here = q.front();
            q.pop();

            int temp = getDistance(prevNode, here, adj);
            distance += temp;
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