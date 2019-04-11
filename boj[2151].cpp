#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int main() {
    int N;

    scanf("%d", &N);
    
    char map[50][50];
    
    int start = -1;
    int end = -1;

    vector<pii> location;
    vector<vector<int> > location_idx(N, vector<int>(N));

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            scanf(" %c", &map[i][j]);

            if(map[i][j] == '#') {
                if(start == -1) {
                    start = location.size();
                } else {
                    end = location.size();
                }
                location.push_back(make_pair(i, j));
                location_idx[i][j] = location.size() - 1;
            }

            if(map[i][j] == '!') {
                location.push_back(make_pair(i, j));
                location_idx[i][j] = location.size() - 1;
            }
        }
    }

    vector<vector<int> > adj(location.size());

    for(int i = 0; i < location.size(); i++) {
        int here_y = location[i].first;
        int here_x = location[i].second;

        for(int j = 0; j < 4; j++) {
            int next_y = here_y + dy[j];
            int next_x = here_x + dx[j];

            while(next_y >= 0 && next_y < N && next_x >= 0 && next_x < N) {
                if(map[next_y][next_x] == '*') break;
                if(map[next_y][next_x] == '!' || map[next_y][next_x] == '#') {
                    adj[i].push_back(location_idx[next_y][next_x]);
                    //printf("%d %d\n", i, location_idx[next_y][next_x]);
                }
                next_y += dy[j];
                next_x += dx[j];
            }
        }
    }

    vector<int> dist(location.size(), 0);
    queue<int> q;
    q.push(start);
    dist[start] = 0;

    while(!q.empty()) {
        int here = q.front();
        q.pop();

        //printf("%d %d\n", here, dist[here]);

        for(int i = 0; i < adj[here].size(); i++) {
            int next = adj[here][i];

            if(dist[next] != 0) continue;
            
            dist[next] = dist[here] + 1;
            q.push(next);
        }
    }

    printf("%d", dist[end] - 1);

    return 0;
}