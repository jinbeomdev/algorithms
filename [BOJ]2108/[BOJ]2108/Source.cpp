#include <cstdio>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>
#include <queue>
#include <limits>
#include <functional>

using namespace std;

typedef pair<int, int> P; //number, frequency

int N;
vector<P> v;
map<int, int> m;
priority_queue<int, vector<int>, greater<int>> min_heap;
priority_queue<int, vector<int>, less<int>> max_heap;

int sum = 0;
int min_value = numeric_limits<int>::max();
int max_value = numeric_limits<int>::min();

bool Comp(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}

	return a.second > b.second;
}

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int key;
		scanf("%d", &key);
		m[key]++;

		sum += key;

		if (min_value > key) min_value = key;
		if (max_value < key) max_value = key;


		if (max_heap.empty()) {
			max_heap.push(key);
		} else if (max_heap.size() == min_heap.size()) {
			max_heap.push(key);
		} else {
			min_heap.push(key);
		}

		if (!max_heap.empty() && !min_heap.empty() &&
			!(max_heap.top() <= min_heap.top())) {
			int max = max_heap.top();
			int min = min_heap.top();
			max_heap.pop();
			min_heap.pop();
			max_heap.push(min);
			min_heap.push(max);
		}
	}

	for (auto p : m) {
		v.push_back(P(p.first, p.second));
	}

	sort(v.begin(), v.end(), Comp);
	
	int most_frequency = v[0].first;
	if (v.size() > 1 && v[0].second == v[1].second) {
		most_frequency = v[1].first;
	}

	double average = (double)sum / (double)N;
	if (average < 0) {
		average -= 0.5;
	} else {
		average += 0.5;
	}

	printf("%d\n%d\n%d\n%d\n",
		(int)average,
		max_heap.top(),
		most_frequency,
		max_value - min_value);
}