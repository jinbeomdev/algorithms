#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int answer = 9;
void dfs(int dest, int number, int count, int case_[]) {
	if (count > 8) {	return;	} if (number == dest) {	answer = min(answer, count);	return;	}
	for (int i = 1; i < 9; i++) {	dfs(dest, number + case_[i], count + i, case_);	dfs(dest, number - case_[i], count + i, case_);	dfs(dest, case_[i] - number, count + i, case_);	dfs(dest, number * case_[i], count + i, case_);	dfs(dest, number / case_[i], count + i, case_);	if (number > 0) {	dfs(dest, case_[i] / number, count + i, case_);	}	}
}

int solution(int N, int number) {
	int case_[9];	int pow = 10;	case_[1] = N;
	for (int i = 2; i <= 8; i++) { case_[i] = N * pow; case_[i] += case_[i - 1]; pow *= 10;	printf("%d\n", case_[i]); }
	for (int i = 1; i < 9; i++) {	dfs(number, case_[i], i, case_); }
	return (answer == 9) ? -1 : answer;
}