#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int N, vector<vector<int>> house) {
	int ret = 0;

	vector<int> d;

	for (int i = -100; i <= 100; i++) {
		for (int j = -100; j <= 100; j++) {
			int m = 80000;

			for (int n = 0; n < house.size(); n++) {
				int d = pow(house[n][1] - j, 2) + pow(house[n][0] - i, 2);
				m = min(d, m);
			}
			d.push_back(m);
		}
	}
	sort(d.begin(), d.end());


	ret = d[d.size() - N];

	return ret;
}