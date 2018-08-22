#include <cstdio>
#include <algorithm>

using namespace std;

int x, y, w, h;

int main() {
	scanf("%d%d%d%d", &x, &y, &w, &h);

	int answer = x;
	answer = min(answer, y);
	answer = min(answer, h - y);
	answer = min(answer, w - x);
	printf("%d", answer);
}