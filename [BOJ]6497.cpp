#include <stdio.h>

#include <algorithm>

using namespace std;

const int MAX = 200010;

int uf[MAX];

int find(int u) {
    if (uf[u] < 0) return u;
    return uf[u] = find(uf[u]);
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

    Edge() {
        u = -1;
        v = -1;
        w = 0;
    }

    Edge(int u, int v, int w) : u(u), v(v), w(w) {}

    bool operator<(const Edge& rhs) const {
        return w < rhs.w;
    }
} edge[MAX];

int main() {
    while(true) {
        int m, n;
        int total = 0;
        scanf("%d%d", &m, &n);
        if (m == 0 && n == 0) break;
        fill(uf, uf + m, -1);
        for (int i = 0; i < n; i++) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            edge[i] = Edge(u, v, w);
            total += w;
        }
        sort(edge, edge + n);
        int result = 0, cnt = 0;
        for (int i = 0; i < n; i++) {
            if(merge(edge[i].u, edge[i].v)) {
                cnt++;
                result += edge[i].w;
                if (cnt == m - 1) break;
            }
        }
        printf("%d\n", total - result);
    }
    return 0;
}