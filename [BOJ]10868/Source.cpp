/*
https://www.acmicpc.net/problem/10868

문제
N(1 ≤ N ≤ 100,000)개의 정수들이 있을 때, a번째 정수부터 b번째 정수까지 중에서 제일 작은 정수를 찾는 것은 어려운 일이 아니다. 하지만 이와 같은 a, b의 쌍이 M(1 ≤ M ≤ 100,000)개 주어졌을 때는 어려운 문제가 된다. 이 문제를 해결해 보자.

여기서 a번째라는 것은 입력되는 순서로 a번째라는 이야기이다. 예를 들어 a=1, b=3이라면 입력된 순서대로 1번, 2번, 3번 정수 중에서 최소값을 찾아야 한다. 각각의 정수들은 1이상 1,000,000,000이하의 값을 갖는다.

입력
첫째 줄에 N, M이 주어진다. 다음 N개의 줄에는 N개의 정수가 주어진다. 다음 M개의 줄에는 a, b의 쌍이 주어진다.

출력
M개의 줄에 입력받은 순서대로 각 a, b에 대한 답을 출력한다.

예제 입력 1
10 4
75
30
100
38
50
51
52
20
81
5
1 10
3 5
6 9
8 10
예제 출력 1
5
38
20
5

풀이:
세그먼트 트리에 구간의 최솟값을 저장하도록 한다.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

const int kMax = 100000;
const int kInf = 10e8;

long long Min(long long a, long long b) {
	if (a < b) {
		return a;
	} else {
		return b;
	}
}

using namespace std;

long long Init(
	vector<long long> &input_buffer,
	vector<long long> &segment_tree,
	int node,
	int start, int end) {
	if (start == end) {
		return segment_tree[node] = input_buffer[start];
	} else {
		int mid = (start + end) / 2;
		return segment_tree[node] = Min(
			Init(input_buffer, segment_tree, node * 2, start, mid),
			Init(input_buffer, segment_tree, node * 2 + 1, mid + 1, end));
	}
}

long long FindMin(
	vector<long long> &segment_tree,
	int node,
	int start,	int end,
	int left, int right) {
	if (start > right || end < left) return kInf;
	if (start >= left && end <= right) return segment_tree[node];
	int mid = (start + end) / 2;
	return Min(
		FindMin(segment_tree, node * 2    , start, mid, left, right),
		FindMin(segment_tree, node * 2 + 1, mid + 1, end, left, right));
}

int main() {
	ios_base ::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;

	cin >> n >> m;
	
	vector<long long> input_buffer(n);
	for (int i = 0; i < n; i++) {
		cin >> input_buffer[i];
	}

	int h = (int)ceil(log2(n));
	int segment_tree_size = 1 << (h + 1);
	vector<long long> segment_tree(segment_tree_size);

	Init(input_buffer, segment_tree, 1, 0, n - 1);

	for (int i = 0; i < m; i++) {
		int a, b;
		
		cin >> a >> b;

		cout << FindMin(segment_tree, 1, 0, n - 1, a-1, b-1) << "\n";
	}

	//system("pause");
}
