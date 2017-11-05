//10815번: 숫자 카드
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N, M;
	vector<int> cards;
	vector<int> ishave;
	cin >> N;
	cards = vector<int>(N);
	for (int i = 0; i < N; i++) {
		cin >> cards[i];
	}
	cin >> M;
	ishave = vector<int>(M);
	for (int i = 0; i < M; i++) {
		cin >> ishave[i];
	}
	sort(cards.begin(), cards.end());
	for (int i = 0; i < M; i++) {
		int mid;
		int left = 0;
		int right = cards.size() - 1;
		while (left <= right) {
			mid = (left + right) / 2;
			if (cards[mid] > ishave[i]) {
				right = mid - 1;
			}
			else if (cards[mid] < ishave[i]) {
				left = mid + 1;
			}
			else {
				break;
			}
		}
		if (cards[mid] == ishave[i]) {
			cout << "1 ";
		}
		else {
			cout << "0 ";
		}
	}

	return 0;
}