#include <iostream>
using namespace std;

int main() {
	int n; //삼각형의 크기
	int **triangle;
	int **dp;
	int Answer = 0;

	cin >> n;

	dp = new int*[n];
	for (int i = 0; i < n; i++) {
		dp[i] = new int[n];
	}

	triangle = new int*[n];
	for (int i = 0; i < n; i++) {
		triangle[i] = new int[n];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> triangle[i][j];
			dp[i][j] = -1;
		}
	}

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j <= i; j++) {
			if (i == 0 && j == 0) dp[i][j] = triangle[i][j];
			if(dp[i + 1][j] < dp[i][j] + triangle[i + 1][j])
				dp[i + 1][j] = dp[i][j] + triangle[i + 1][j];
			if(dp[i + 1][j + 1] < dp[i][j] + triangle[i + 1][j + 1])
				dp[i + 1][j + 1] = dp[i][j] + triangle[i + 1][j + 1];
		}
	}

	for (int i = 0; i < n; i++) {
		if (Answer < dp[n - 1][i])
			Answer = dp[n - 1][i];
	}

	cout << Answer;
}