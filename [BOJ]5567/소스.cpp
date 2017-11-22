/*
https://www.acmicpc.net/problem/5567

문제
상근이는 자신의 결혼식에 학교 동기 중 자신의 친구와 친구의 친구를 초대하기로 했다. 상근이의 동기는 모두 N명이고, 이 학생들의 학번은 모두 1부터 N까지이다. 상근이의 학번은 1이다.

상근이는 동기들의 친구 관계를 모두 조사한 리스트를 가지고 있다. 이 리스트를 바탕으로 결혼식에 초대할 사람의 수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 상근이의 동기의 수 n (2 ≤ n ≤ 500)이 주어진다. 둘째 줄에는 리스트의 길이 m (1 ≤ m ≤ 10000)이 주어진다. 다음 줄부터 m개 줄에는 친구 관계 ai bi가 주어진다. (1 ≤ ai < bi ≤ n) ai와 bi가 친구라는 뜻이며, bi와 ai도 친구관계이다.

출력
첫째 줄에 상근이의 결혼식에 초대하는 동기의 수를 출력한다.

예제 입력  복사
6
5
1 2
1 3
3 4
2 3
4 5
예제 출력  복사
3
*/

#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int n, m;
	int friends[501][501];
	int invited_frineds[501];

	memset(friends, -1, sizeof(friends));
	memset(invited_frineds, -1, sizeof(invited_frineds));
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int friend_1, friend_2;

		cin >> friend_1 >> friend_2;

		friends[friend_1][friend_2] = 1;
		friends[friend_2][friend_1] = 1;
	}

	for (int i = 2; i <= n; i++) {
		if (friends[1][i] != 1) continue; //친구가 아닐 경우

		int my_friend = i;

		invited_frineds[i] = 1;
		
		for (int j = 2; j <= n; j++) {
			if (friends[i][j] != 1) continue; //친구의 친구가 아닐 경우
			
			int my_friend_of_friend = j;

			invited_frineds[j] = 1;
		}
	}

	int num_invited_friends = 0;
	for (int i = 2; i <= n; i++) {
		if (invited_frineds[i] == 1) num_invited_friends++;
	}

	cout << num_invited_friends;
}