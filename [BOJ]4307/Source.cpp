//#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int test_case_size;
	int stick_length;
	int num_ant;

	scanf("%d", &test_case_size);

	for (int test_case = 1; test_case <= test_case_size; test_case++) {
		vector<int> ant_position;
		vector<int> min_ant_position;
		int min_result;
		int max_result;

		scanf("%d %d", &stick_length, &num_ant);

		for (int i = 0; i < num_ant; i++) {
			int postion;

			scanf("%d", &postion);

			ant_position.push_back(postion);
			min_ant_position.push_back(min(postion, stick_length - postion));
		}

		sort(ant_position.begin(), ant_position.end());
		sort(min_ant_position.begin(), min_ant_position.end());
		max_result = max(stick_length - ant_position.front(), ant_position.back());
		min_result = min_ant_position.back();

		printf("%d %d\n", min_result, max_result);
	}

	//system("pause");
}