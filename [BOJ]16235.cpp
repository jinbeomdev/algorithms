#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

struct Tree {
    int x, y, z;
    Tree(int _x, int _y, int _z) {
        x = _x, y = _y, z = _z;
    }
};

int N, M, K;
int A[10][10];
vector<int> treeMap[10][10];
int feedMap[10][10];

int main() {
    scanf("%d%d%d", &N, &M, &K);
    for(int i = 0; i < N ; i++) {
        for(int j = 0; j < N; j++) {
            scanf("%d", &A[i][j]);
            feedMap[i][j] = 5;
        }
    }

    for(int i = 0; i < M; i++) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        x--, y--;
        treeMap[x][y].push_back(z);
    }

    while(K--) {
        vector<Tree> deadTree;
        vector<int> aliveTree;
        vector<int> hereTree;

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                aliveTree.clear();
                hereTree = treeMap[i][j];
                sort(hereTree.begin(), hereTree.end());
                for(int p = 0; p < hereTree.size(); p++) {
                    //printf("treeMap[%d][%d][%d] : %d\n", i, j, p, hereTree[p]);
                    if(feedMap[i][j] - hereTree[p] > -1) {
                        feedMap[i][j] -= hereTree[p];
                        aliveTree.push_back(hereTree[p] + 1);
                    } else {
                        deadTree.push_back(Tree(j, i, hereTree[p]));
                    }
                }
                treeMap[i][j] = aliveTree;
            }
        }

        for(int i = 0; i < deadTree.size(); i++) {
            int y = deadTree[i].y;
            int x = deadTree[i].x;
            int z = deadTree[i].z;

            feedMap[y][x] += z / 2;
        }

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                int dy[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
                int dx[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
                for(int p = 0; p < treeMap[i][j].size(); p++) {
                    if(treeMap[i][j][p] % 5 != 0) continue;

                    for(int q = 0; q < 8; q++) {
                        int y = i + dy[q];
                        int x = j + dx[q];
                        if(y < 0 || y >= N) continue;
                        if(x < 0 || x >= N) continue;
                        treeMap[y][x].push_back(1);
                    }
                }
            }
        }

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                feedMap[i][j] += A[i][j];
            }
        }
    }

    int answer = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            answer += treeMap[i][j].size();
        }
    }
    printf("%d", answer);
}