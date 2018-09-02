#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

string solution(int n, int t, int m, int p) {
	string answer = "";
	char alpha[] = { 'A', 'B', 'C', 'D', 'E', 'F' };
	queue<char> q;
	for (int i = 0; i < 100000; i++) {
		int number = i;
		stack<char> s;

		if (number == 0) {
			s.push('0');
		}

		while (number > 0) {
			int r = number % n;
			if (r < 10) {
				s.push(r + '0');
			} else {
				s.push(alpha[r - 10]);
			}
			number /= n;
		}

		while (!s.empty()) {
			q.push(s.top());
			s.pop();
		}
	}

	while (t--) {
		for (int i = 0; i < m; i++) {
			char hold = q.front();
			q.pop();

			if (i == p - 1) {
				answer += hold;
			}
		}
	}

	return answer;
}

int main() {
	solution(16, 16, 2, 1);
}