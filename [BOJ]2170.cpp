#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int main() {
    int N;
    vector<pii> v;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int s, e;
        scanf("%d%d", &s, &e);
        v.push_back(make_pair(s, e));
    }
    sort(v.begin(), v.end());
    int answer = 0;
    int s = v[0].first;
    for (int i = 0; i < v.size() - 1; i++) {
        if (!(v[i].first <= v[i + 1].first && v[i].second >= v[i + 1].first)) {
            answer += v[i].second - s;
            s = v[i + 1].first;
        }
    }
    if (!(v[N - 2].first <= v[N - 1].first && v[N - 2].second >= v[N - 1].first)) {
        answer += v[N - 1].second - v[N - 1].first;
    }
    printf("%d\n", answer);
}