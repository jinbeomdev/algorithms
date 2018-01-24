//reference : https://www.acmicpc.net/blog/view/9
//https://www.acmicpc.net/problem/2042

/*
����
� N���� ���� �־��� �ִ�. �׷��� �߰��� ���� ������ ����� �Ͼ�� �� �߰��� � �κ��� ���� ���Ϸ� �Ѵ�. ���࿡ 1,2,3,4,5 ��� ���� �ְ�, 3��° ���� 6���� �ٲٰ� 2��°���� 5��°���� ���� ���϶�� �Ѵٸ� 17�� ����ϸ� �Ǵ� ���̴�. �׸��� �� ���¿��� �ټ� ��° ���� 2�� �ٲٰ� 3��°���� 5��°���� ���� ���϶�� �Ѵٸ� 12�� �� ���̴�.

�Է�
ù° �ٿ� ���� ���� N(1<=N<=1,000,000)�� M(1<=M<=10,000), K(1<=k<=10,000) �� �־�����. M�� ���� ������ �Ͼ�� ȸ���̰�, K�� ������ ���� ���ϴ� ȸ���̴�. �׸��� ��° �ٺ��� N+1��° �ٱ��� N���� ���� �־�����. �׸��� N+2��° �ٺ��� N+M+K+1��° �ٱ��� �� ���� ���� a,b,c�� �־����µ�, a�� 1�� ��� b��° ���� c�� �ٲٰ� a�� 2�� ��쿡�� b��° ������ c��° �������� ���� ���Ͽ� ����ϸ� �ȴ�.

���
ù° �ٺ��� K�ٿ� ���� ���� ������ ���� ����Ѵ�. (�� ������ long long ������ ���� �ʴ´�)

���� �Է�  ����
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
���� ���  ����
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