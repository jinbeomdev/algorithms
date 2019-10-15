#include <stdio.h>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
const int SIZE = 4 * 75010;
struct ST { //Segment Tree
    int arr[SIZE];
    ST() {
        fill(arr, arr + SIZE, 0);
    }
    void inc(int n) {
        n += SIZE / 2;
        while (n > 0) {
            arr[n]++;
            n /= 2;
        }
    }

    int sum(int s, int e) {
        return _sum(s, e, 1, 0, SIZE - 1);
    }
    int _sum(int s, int e, int node, int ns, int ne) {
        if (s > ne || ns > e) return 0;
        if (s <= ns && ne <= e) return arr[node];
        int mid = (ns + ne) / 2;
        return _sum(s, e, node * 2, ns, mid) + _sum(s, e, node * 2 + 1, mid + 1, ne);
    }
};
bool comp(pii lhs, pii rhs) {
    return lhs.second < rhs.second;
}

bool comp2(pii lhs, pii rhs) {
    if (lhs.first == rhs.first) {
        return lhs.second > rhs.second;
    }
    return lhs.first < rhs.first;
}
int main() {
    int TC;
    scanf("%d", &TC);
    for (int i = 0; i < TC; i++) {
        ST st;
        pii input[75010];
        int N;
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
            scanf("%d%d", &input[i].first, &input[i].second);
        }

        sort(input, input + N, comp);
        int compress = 0;
        int newY[75010];
        for (int i = 0; i < N; i++) {
            if (i > 0 && input[i].second != input[i + 1].second) compress++;
            newY[i] = compress;
        }
        for (int i = 0; i < N; i++) {
            input[i].second = newY[i];
        }
        sort(input, input + N, comp2);
        long long int answer = 0;
        for (int i = 0; i < N; i++) {
            answer += st.sum(input[i].second, 75010);
            st.inc(input[i].second);
        }
        printf("%lld\n", answer);
    }
}