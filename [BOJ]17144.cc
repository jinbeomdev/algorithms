#include <stdio.h>

#include <vector>

using namespace std;

typedef pair<int, int> pii;

const int dy[] = {1, -1, 0, 0};
const int dx[] = {0, 0, 1, -1};

int main() {
    int R, C, T;
    int map[50][50];
    int ay1, ax1, ay2, ax2;
    ay1 = ax1 = ay2 = ax2 = -1;

    scanf("%d%d%d", &R, &C, &T);

    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            scanf("%d", &map[i][j]);

            if(map[i][j] == -1) {
                if(ay1 == -1) {
                    ay1 = i;
                    ax1 = j;
                } else {
                    ay2 = i;
                    ax2 = j;
                }
            }
        }
    }

    while(T--) {
        vector<pii> dust;

        int temp_map[50][50];
        for(int i = 0; i < R; i++) {
            for(int j = 0; j < C; j++) {
                if(map[i][j] > 0) dust.push_back(make_pair(i, j));
                temp_map[i][j] = 0;
            }
        }

        //spread
        for(int i = 0; i < dust.size(); i++) {
            int y = dust[i].first;
            int x = dust[i].second;
            int cnt_adj = 0;

            for(int j = 0; j < 4; j++) {
                int next_y = y + dy[j];
                int next_x = x + dx[j];

                if(next_y < 0 || next_y >= R) continue;
                if(next_x < 0 || next_x >= C) continue;
                if(next_y == ay1 && next_x == ax1) continue;
                if(next_y == ay2 && next_x == ax2) continue;
                cnt_adj++;
            }

            for(int j = 0; j < 4; j++) {
                int next_y = y + dy[j];
                int next_x = x + dx[j];

                if(next_y < 0 || next_y >= R) continue;
                if(next_x < 0 || next_x >= C) continue;
                if(next_y == ay1 && next_x == ax1) continue;
                if(next_y == ay2 && next_x == ax2) continue;
                temp_map[next_y][next_x] += (map[y][x] / 5);
            }

            temp_map[y][x] += (map[y][x] - ((map[y][x] / 5) * cnt_adj));
        }

        for(int i = 0; i < R; i++) {
            for(int j = 0 ; j < C; j++) {
                map[i][j] = temp_map[i][j];
            }
        }

        int temp_ay1 = ay1;
        int temp_ax1 = ax1 + 2;
        temp_map[ay1][ax1 + 1] = 0;

        while(temp_ax1 < C) {
            temp_map[temp_ay1][temp_ax1] = map[temp_ay1][temp_ax1 - 1];
            temp_ax1++;
        }
        temp_ax1--;
        temp_ay1--;

        while(temp_ay1 >= 0) {
            temp_map[temp_ay1][temp_ax1] = map[temp_ay1 + 1][temp_ax1];
            temp_ay1--;
        }
        temp_ay1++;
        temp_ax1--;

        while(temp_ax1 >= 0) {
            temp_map[temp_ay1][temp_ax1] = map[temp_ay1][temp_ax1 + 1];
            temp_ax1--;
        }
        temp_ay1++;
        temp_ax1++;

        while(temp_ay1 < ay1) {
            temp_map[temp_ay1][temp_ax1] = map[temp_ay1 - 1][temp_ax1];
            temp_ay1++;
        }

        int temp_ay2 = ay2;
        int temp_ax2 = ax2 + 2;
        temp_map[ay2][ax2 + 1] = 0;

        while(temp_ax2 < C) {
            temp_map[temp_ay2][temp_ax2] = map[temp_ay2][temp_ax2 - 1];
            temp_ax2++;
        }
        temp_ax2--;
        temp_ay2++;

        while(temp_ay2 < R) {
            temp_map[temp_ay2][temp_ax2] = map[temp_ay2 - 1][temp_ax2];
            temp_ay2++;
        }
        temp_ay2--;
        temp_ax2--;

        while(temp_ax2 >= 0) {
            temp_map[temp_ay2][temp_ax2] = map[temp_ay2][temp_ax2 + 1];
            temp_ax2--;
        }
        temp_ay2--;
        temp_ax2++;

        while(temp_ay2 > ay2) {
            temp_map[temp_ay2][temp_ax2] = map[temp_ay2 + 1][temp_ax2];
            temp_ay2--;
        }

        for(int i = 0; i < R; i++) {
            for(int j = 0 ; j < C; j++) {
                map[i][j] = temp_map[i][j];
            }
        }
    }

    int answer = 0;
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            if(map[i][j] > 0) answer += map[i][j];
        }
    }
    printf("%d", answer);
    return 0;
}