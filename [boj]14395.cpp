#include <stdio.h>
#include <map>
#include <queue>
#include <iostream>
#include <string>

using namespace std;

typedef long long int lli;

lli s, t;

lli cal(lli n, int op) {
    if(op == 0) return n * n;
    else if(op == 1) return n + n;
    else if(op == 2) return n - n;
    else return n / n;
}
char oper(int op) {
    if(op == 0) return '*';
    else if(op == 1) return '+';
    else if(op ==2 ) return '-';
    else return '/';
}
int main() {
    scanf("%ld%ld", &s, &t);

    map<lli, bool> p;
    queue<pair<lli, string> > q;
    q.push(make_pair(s, ""));
    p[s] = true;

    while(!q.empty()) {
        lli here = q.front().first;
        string here_s = q.front().second;
        q.pop();

        if(here == t) {
            if(here_s.length() == 0) {
                here_s = "0";
            }
            cout << here_s << '\n';
            return 0;
        }

        for(int i = 0; i < 4; i++) {
            lli next = cal(here, i);
            string next_s = here_s;

            if(next < 1 || next > 10e9) continue;

            if(p.count(next) == 0) {
                p[next] = true;
                next_s += oper(i);
                q.push(make_pair(next, next_s));
            }
        }
    }

    cout << "-1" << '\n';

    return 0;
}