#include <stdio.h>
#include <array>
#include <map>
#include <string>
#include <queue>
#include <iostream>

using namespace std;

int main() {
    array<string, 3> a;

    for(int i = 0; i < 3; i++) {
        int cnt;
        scanf("%d", &cnt);
        if(cnt > 0) {
            cin >> a[i];
        } else {
            a[i] = "";
        }
    }

    int cnt[3] = {0, 0, 0};

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < a[i].size(); j++) {
            cnt[a[i][j] - 'A']++;
        }
    }

    map<array<string, 3>, int> d;
    queue<array<string, 3>> q;
    q.push(a);
    d[a] = 0;

    while(!q.empty()) {
        array<string, 3> here = q.front();
        q.pop();

        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(i == j) continue;
                if(here[i].length() == 0) continue;
                array<string, 3> next(here);
                next[j].push_back(here[i].back());
                next[i].pop_back();
                if(d.count(next) == 0) {
                    d[next] = d[here] + 1;
                    q.push(next);
                }
            }
        }
    }
    array<string, 3> ans;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < cnt[i]; j++) {
            ans[i] += (char)('A' + i);
        }
    }
    cout << d[ans] << '\n';
    return 0;
}