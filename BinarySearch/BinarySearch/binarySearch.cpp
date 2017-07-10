#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 5005

int d[MAX], n;

bool bsearch(int val) {
	int left = 0;
	int right = n - 1;
	int mid;

	while (left <= right) {
		mid = (left + right) / 2;

		if (d[mid] < val) {
			left = mid + 1;
		}
		else if (d[mid] > val) {
			right = mid - 1;
		}
		else {
			return true;
		}
	}
	
	return false;
}

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		cin >> d[i];

	sort(d, d + n);

	int query;

	cin >> query;

	while (query--) {
		int x; cin >> x;

		if (bsearch(x)) cout << "exist" << endl;
		else cout << "not exist" << endl;
	}
}
