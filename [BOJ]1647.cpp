#include <stdio.h>

#include <algorithm>

using namespace std;

const int NMAX = 100010;
const int MMAX = 1000010;

int uf[NMAX];

int find(int v) {
    if (uf[v] < 0) return v;
    return uf[v] = find(uf[v]);
}

bool merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return false;
    uf[u] = v;
    return true;
}

struct Edge {
    int u, v, w;
    Edge() : u(-1), v(-1), w(0) {}
    Edge(int u, int v, int w) : u(u), v(v), w(w) {}
    bool operator<(const Edge& rhs) const {
        return w < rhs.w;
    }
}edge[MMAX];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    fill(uf, uf + n, -1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        edge[i] = Edge(u, v, w);
    }
    sort(edge, edge + m);
    int result = 0, cnt = 0;
    for (int i = 0; i < m; i++) {
        if(merge(edge[i].u, edge[i].v)) {
            cnt++;
            result += edge[i].w;
            if (cnt == n - 2) break;
        }
    }
    printf("%d", result);
    return 0;
}