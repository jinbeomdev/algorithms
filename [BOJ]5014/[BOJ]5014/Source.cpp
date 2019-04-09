#include <stdio.h>
#include <queue>
#include <string.h>

using namespace std;

int map[1000001];
bool discovered[1000001];
int dist[1000001];
int F, S, G, U, D;

int main() {
	scanf("%d%d%d%d%d", &F, &S, &G, &U, &D);

	memset(dist, -1, sizeof(dist));

	queue<int> q;
	q.push(S);
	discovered[S] = true;
	dist[S] = 0;

	while (!q.empty()) {
		int here = q.front();
		q.pop();

		if (here == G) break;

		//U
		int next_up = here + U;
		
		if (next_up <= F && !discovered[next_up]) {
			q.push(next_up);
			discovered[next_up] = true;
			dist[next_up] = dist[here] + 1;
		}

		int next_down = here - D;

		if (next_down >= 1 && !discovered[next_down]) {
			q.push(next_down);
			discovered[next_down] = true;
			dist[next_down] = dist[here] + 1;
		}
	}

	if (dist[G] == -1) {
		printf("%s", "use the stairs");
	}
	else {
		printf("%d", dist[G]);
	}
}