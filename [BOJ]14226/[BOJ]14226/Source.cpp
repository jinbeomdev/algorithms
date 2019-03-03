#include <stdio.h>
#include <queue>

using namespace std;

bool discoverd[2000][2000] = { 0, };

struct System {
	int display;
	int clipboard;
	int time;
};

int main() {
	int S;

	scanf("%d", &S);

	queue<System> q;
	System system;
	system.display = 1;
	system.clipboard = 0;
	system.time = 0;
	q.push(system);

	while (!q.empty()) {
		System here = q.front();
		q.pop();

		if (here.display == S) {
			printf("%d", here.time);
			break;
		}

		for (int i = 0; i < 3; i++) {
			System next = here;
			
			if (i == 0) {
				if (next.display == next.clipboard) continue;
				next.clipboard = next.display; //복사
			} else if (i == 1) {
				if (next.clipboard == 0) continue;
				next.display += next.clipboard; //붙여넣기
			} else {
				if (next.display <= 0 || next.clipboard <= 0) continue;
				next.display--; //빼기
			}

			next.time++;

			if (next.display > 2000 || next.clipboard > 2000) continue;
			if (discoverd[next.display][next.clipboard]) continue;

			discoverd[next.display][next.clipboard] = true;
			q.push(next);
		}
	}
}
