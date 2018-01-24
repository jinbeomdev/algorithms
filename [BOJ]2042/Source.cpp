//reference : https://www.acmicpc.net/blog/view/9
//https://www.acmicpc.net/problem/2042

/*
문제
어떤 N개의 수가 주어져 있다. 그런데 중간에 수의 변경이 빈번히 일어나고 그 중간에 어떤 부분의 합을 구하려 한다. 만약에 1,2,3,4,5 라는 수가 있고, 3번째 수를 6으로 바꾸고 2번째부터 5번째까지 합을 구하라고 한다면 17을 출력하면 되는 것이다. 그리고 그 상태에서 다섯 번째 수를 2로 바꾸고 3번째부터 5번째까지 합을 구하라고 한다면 12가 될 것이다.

입력
첫째 줄에 수의 개수 N(1<=N<=1,000,000)과 M(1<=M<=10,000), K(1<=k<=10,000) 가 주어진다. M은 수의 변경이 일어나는 회수이고, K는 구간의 합을 구하는 회수이다. 그리고 둘째 줄부터 N+1번째 줄까지 N개의 수가 주어진다. 그리고 N+2번째 줄부터 N+M+K+1번째 줄까지 세 개의 정수 a,b,c가 주어지는데, a가 1인 경우 b번째 수를 c로 바꾸고 a가 2인 경우에는 b번째 수부터 c번째 수까지의 합을 구하여 출력하면 된다.

출력
첫째 줄부터 K줄에 걸쳐 구한 구간의 합을 출력한다. (단 정답은 long long 범위를 넘지 않는다)

예제 입력  복사
5 2 2
1
2
3
4
5
1 3 6
2 2 5
1 5 2
2 3 5
예제 출력  복사
17
12
*/

#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
long long init(vector<long long> &a, vector<long long> &tree, int node, int start, int end) {
	if (start == end) {
		return tree[node] = a[start];
	}
	else {
		return tree[node] = init(a, tree, node * 2, start, (start + end) / 2) + init(a, tree, node * 2 + 1, (start + end) / 2 + 1, end);
	}
}
void update(vector<long long> &tree, int node, int start, int end, int index, long long diff) {
	if (index < start || index > end) return;
	tree[node] = tree[node] + diff;
	if (start != end) {
		update(tree, node * 2, start, (start + end) / 2, index, diff);
		update(tree, node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
	}
}
long long sum(vector<long long> &tree, int node, int start, int end, int left, int right) {
	if (left > end || right < start) {
		return 0;
	}
	if (left <= start && end <= right) {
		return tree[node];
	}
	return sum(tree, node * 2, start, (start + end) / 2, left, right) + sum(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}
int main() {
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	vector<long long> a(n);
	int h = (int)ceil(log2(n));
	int tree_size = (1 << (h + 1));
	vector<long long> tree(tree_size);
	m += k;
	for (int i = 0; i<n; i++) {
		scanf("%lld", &a[i]);
	}
	init(a, tree, 1, 0, n - 1);
	while (m--) {
		int t1, t2, t3;
		scanf("%d", &t1);
		if (t1 == 1) {
			int t2;
			long long t3;
			scanf("%d %lld", &t2, &t3);
			t2 -= 1;
			long long diff = t3 - a[t2];
			a[t2] = t3;
			update(tree, 1, 0, n - 1, t2, diff);
		}
		else if (t1 == 2) {
			int t2, t3;
			scanf("%d %d", &t2, &t3);
			printf("%lld\n", sum(tree, 1, 0, n - 1, t2 - 1, t3 - 1));
		}
	}
	return 0;
}