#include <stdio.h>
#include <vector>

using namespace std;

vector<int> hashTable[40000];
vector<int> user[10001];

int getIndex(int year, int month, int day) {
	int index = day;
	int baseYear = 2018;
	int diffYear = year - baseYear;
	index += 365 * diffYear + (year / 4) - (baseYear / 4);
	for (int i = 1; i < month; i++) {
		if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
			index += 31;
		else if (i == 4 || i == 6 || i == 9 || i == 11)
			index += 30;
		else if (i == 2) {
			if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
				index += 29;
			else
				index += 28;
		}
	}
	return index;
}

int main() {
	int T;
	scanf("%d", &T);

	for (int tc = 0; tc < T; tc++) {
		int numQuery;
		scanf("%d", numQuery);

		for (int i = 0; i < numQuery; i++) {
			int query;
			int id, registerType, numRoutin, date;
			int cancleType;

			scanf("%d", query);

			switch (query) {
			case 1:
				scanf("%d %d %d %d", &id, &registerType, &numRoutin, &date);
			case 2:
				scanf("%d")
			case 3:
			default:
				break;
			}
		}
	}
}