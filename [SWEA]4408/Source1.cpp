/*
4408. 자기 방으로 돌아가기
*/

#include <iostream>

using namespace std;

int T, N;
int visited[200];
int answer;

void init() {
	answer = 0;
	for (int i = 0; i < 200; i++) {
		visited[i] = 0;
	}
}

void swap(int &a, int &b) {
	if (a > b) {
		int temp;
		temp = a;
		a = b;
		b = temp;
	}
}

int main() {
	scanf("%d", &T);

	for (int test_case = 1; test_case <= T; test_case++) {
		scanf("%d", &N);
		init();

		for (int student = 0; student < N; student++) {
			int room[2];

			scanf("%d %d", &room[0], &room[1]);

			for (int i = 0; i < 2; i++) {
				if (!(room[i] % 2)) { //짝수
					room[i] = room[i] / 2 - 1; //복도 인덱스
				} else { //홀수
					room[i] = room[i] / 2; //복도 인덱스
				}
			}

			swap(room[0], room[1]);

			for (int i = room[0]; i <= room[1]; i++) {
				visited[i]++;
				if (visited[i] > answer) {
					answer = visited[i];
				}
			}
		}

		cout << '#' << test_case << ' ' << answer << endl;
	}
}