/* https://www.acmicpc.net/problem/1946 */

//#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

struct Ranks
{
	int doc_rank;
	int interview_rank;

	Ranks(int _doc_rank, int _interview_rank) : doc_rank(_doc_rank), interview_rank(_interview_rank) {}

	bool operator < (const Ranks &rhs) const {
		return (doc_rank < rhs.doc_rank);
	}
};

int main() {
	int test_case_size;

	scanf("%d", &test_case_size);

	for (int i = 1; i <= test_case_size; i++) {
		vector<Ranks> ranks;
		int num_employees;

		scanf("%d", &num_employees);

		for (int i = 0; i < num_employees; i++) {
			int doc_rank, interview_rank;

			scanf("%d %d", &doc_rank, &interview_rank);

			ranks.push_back(Ranks(doc_rank, interview_rank));
		}

		sort(ranks.begin(), ranks.end());

		/*
		for (Ranks &rank : ranks) {
			printf("debug : %d\n", rank.interview_rank);
		} putchar('\n');
		*/

		/*
		n^2 풀이 방법 : 시간 초과
		vector<int> dp(num_employees, 1);
		int result = 0;
		for (int i = 0; i < num_employees; i++) {
			for (int j = 0; j < i; j++) {
				if (ranks[i].interview_rank < ranks[j].interview_rank) {
					if (dp[i] < dp[j] + 1) dp[i] = dp[j] + 1;
					result = max(result, dp[i]);
				}
			}
		}
		*/

		vector<int> lds;
		lds.push_back(ranks[0].interview_rank);
		for (int i = 1; i < num_employees; i++) {
			if (lds.back() > ranks[i].interview_rank) lds.push_back(ranks[i].interview_rank);
		}

		printf("%d\n", lds.size());
	}

	//system("pause");
}