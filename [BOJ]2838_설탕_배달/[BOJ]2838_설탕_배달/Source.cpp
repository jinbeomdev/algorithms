//2839번:설탕 배달
#include <iostream>
#include <vector>

const int INF = 987654321;

using namespace std;
vector<int> cache = vector<int>(5001, INF);

#define __min(a,b) (((a) < (b)) ? (a) : (b))

int main() {
	int N;
	cin >> N;

	cache[0] = 0;
	cache[3] = 1;

	for (int i = 5; i <= N; i++) {
		if (cache[i - 3] == INF && cache[i - 5] == INF) continue;
		cache[i] = __min(cache[i - 3], cache[i - 5]) + 1;
	}

	if (cache[N] == INF) {
		cout << "-1";
	}
	else {
		cout << cache[N];
	}
}