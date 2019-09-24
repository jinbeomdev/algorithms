#include <stdio.h>
#include <queue>
#include <string.h>

using namespace std;

struct Info
{
    int y, x, t;
    Info(int y_, int x_, int t_) : y(y_), x(x_), t(t_) {}
};

int N, M;
int map[10][10];

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

bool can(int y, int x)
{
    bool garo = false;
    bool sero = false;
    if (y - 1 >= 0 && map[y - 1][x] == 0)
        sero = true;
    if (y + 1 < N && map[y + 1][x] == 0)
        sero = true;
    if (x - 1 >= 0 && map[y][x - 1] == 0)
        garo = true;
    if (x + 1 >= 0 && map[y][x + 1] == 0)
        garo = true;
    return !(garo && sero);
}

int main()
{
    scanf("%d%d", &N, &M);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &map[i][j]);
        }
    }

    int answer = 100000000;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (map[i][j] != 0)
                continue;

            if (!can(i, j))
                continue;

            int dist[10][10][20];

            memset(dist, false, sizeof(dist));

            map[i][j] = M;
            queue<Info> q;
            q.push(Info(0, 0, 0));
            dist[0][0][0] = true;

            while (!q.empty())
            {
                Info here = q.front();
                q.pop();

                for (int k = 0; k < 4; k++)
                {
                    int next_y = here.y + dy[k];
                    int next_x = here.x + dx[k];
                    int next_t;

                    if (next_y < 0 || next_y >= N || next_x < 0 || next_x >= N)
                        continue;

                    if (map[next_y][next_x] == 0)
                        continue;

                    if (map[here.y][here.x] > 1 && map[next_y][next_x] > 1)
                        continue;

                    if (dist[next_y][next_x][next_t])
                        continue;

                    if (map[here.y][here.x] > 1 && here.t % map[here.y][here.x] != 0)
                    {
                        next_t = here.t + (map[here.y][here.x] - here.t % map[here.y][here.x]) + 1;
                    }
                    else
                    {
                        next_t = here.t + 1;
                    }

                    dist[next_y][next_x][next_t] = true;
                    q.push(Info(next_y, next_x, next_t));
                }
            }

            for(int i = 0; i < 100 * 20; i++) {
                if(dist[N - 1][N - 1][i]) {
                    printf("%d\n", i);
                }
            }

            map[i][j] = 0;
        }
    }

    printf("%d", answer);

    return 0;
}