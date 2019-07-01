#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    for(int tc = 1; tc <= T; tc++) {
        int N;
        vector<int> v;
        scanf("%d", &N);
        while(N--) {
            int i;
            scanf("%d", &i);
            v.push_back(i);
        }
        sort(v.begin(), v.end());
        printf("#%d %d\n", tc, v.front() * v.back());
    }
}