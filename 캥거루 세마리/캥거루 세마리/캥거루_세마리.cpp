#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define kangaroo_size 3
#define diff_size 2
int main() {
	int Answer = 0;
	vector<int> kangaroos(kangaroo_size, 0);
	vector<int> diff(diff_size, 0);

	for (int i = 0; i < kangaroo_size; i++)
		cin >> kangaroos[i];

	for (int i = 0; i < diff_size; i++)
		diff[i] = abs(kangaroos[i] - kangaroos[i + 1]);

	if (diff[0] < diff[1]) Answer = diff[1];
	else Answer = diff[0];

	cout << Answer - 1;
}