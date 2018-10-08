#include <stdio.h>

#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N;
	vector<pair<int, int>> lines;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int s, e;
		scanf("%d%d", &s, &e);
		lines.push_back({ s, e});
	}

	sort(lines.begin(), lines.end());

	int left = lines[0].first, right = lines[0].second;
	int result = right - left;
	for (int i = 1; i < lines.size(); i++) {
		if (right < lines[i].first) {
			left = lines[i].first;
			right = lines[i].second;
			result += right - left;
		} else if(right < lines[i].second) {
			right = lines[i].second;
			result = right - left;
		}
	}

	printf("%d", result);
}