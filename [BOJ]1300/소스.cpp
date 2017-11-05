//1300번:K번째 수
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N;
	int K;
	vector<vector<int>> A;
	vector<int> B;

	cin >> N;
	cin >> K;
	A = vector<vector<int>>(N + 1, vector<int>(N + 1));
	B = vector<int>((N + 1) * (N + 1));
	for (int i = 1; i < (int)A.size(); i++) {
		for (int j = 1; j < (int)A[i].size(); j++) {
			A[i][j] = i * j;
			//    1 2 3
			// 1  1 2 3
			// 2  4 5 6
			B[(i - 1) * N + j] = A[i][j];
			cout << (i - 1) * N + j << " " << A[i][j];
		}
	}
	sort(B.begin(), B.end());
}