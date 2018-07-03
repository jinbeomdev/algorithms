#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int N, C;
vector<int> houses;
int answer;

int main() {
	scanf("%d %d", &N, &C);

	houses.resize(N);
	
	for (int house_pos = 0; house_pos < N; house_pos++) {
		scanf("%d", &houses[house_pos]);
	}

	sort(houses.begin(), houses.end());

	int left = 1;
	int right = houses.back() - houses[0];
	
	while (left <= right) {
		int mid = (right + left) / 2;
		int cnt = 1;
		int start = houses[0];

		for (int house_pos = 1; house_pos < houses.size(); house_pos++) {
			if (houses[house_pos] - start >= mid) {
				cnt++;
				start = houses[house_pos];
			}
		}

		if (cnt >= C) {
			answer = mid;
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}

	printf("%d", answer);
}