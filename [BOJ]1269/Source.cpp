//https://www.acmicpc.net/problem/1269

/*
대칭 차집합 풀이
문제집
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
2 초	128 MB	1539	702	532	45.626%
문제
자연수를 원소로 갖는 공집합이 아닌 두 집합 A와 B가 있다. 이 때, 두 집합의 대칭 차집합의 원소의 개수를 출력하는 프로그램을 작성하시오. 두 집합 A와 B가 있을 때, (A-B)와 (B-A)의 합집합을 A와 B의 대칭 차집합이라고 한다.

예를 들어, A = { 1, 2, 4 } 이고, B = { 2, 3, 4, 5, 6 } 라고 할 때,  A-B = { 1 } 이고, B-A = { 3, 5, 6 } 이므로, 대칭 차집합의 원소의 개수는 1 + 3 = 4개이다.

입력
첫째 줄에 집합 A의 원소의 개수와 집합 B의 원소의 개수가 빈 칸을 사이에 두고 주어진다. 둘째 줄에는 집합 A의 모든 원소가, 셋째 줄에는 집합 B의 모든 원소가 빈 칸을 사이에 두고 각각 주어진다. 각 집합의 원소의 개수는 200,000을 넘지 않으며, 모든 원소의 값은 100,000,000을 넘지 않는다.

출력
첫째 줄에 대칭 차집합의 원소의 개수를 출력한다.

예제 입력  복사
3 5
1 2 4
2 3 4 5 6
예제 출력  복사
4
*/
#include <iostream>
#include <set>

using namespace std;

int main() {
	set<int> set_a;
	set<int> set_b;
	int num_a, num_b;

	cin >> num_a >> num_b;

	for (int i = 0; i < num_a; i++) {
		int element;

		cin >> element;
		
		set_a.insert(element);
	}

	for (int i = 0; i < num_b; i++) {
		int element;

		cin >> element;

		set_b.insert(element);
	}

	set<int> temp_set_a;
	for (set<int>::iterator it_a = set_a.begin(); it_a != set_a.end(); it_a++) {
		set<int>::iterator find_it = set_b.find(*it_a);

		if (find_it == set_b.end()) {
			temp_set_a.insert(*it_a);
			continue;
		}

		set_b.erase(find_it);
	}

	cout << temp_set_a.size() + set_b.size();
}