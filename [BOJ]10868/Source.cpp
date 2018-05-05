/*
https://www.acmicpc.net/problem/10868

����
N(1 �� N �� 100,000)���� �������� ���� ��, a��° �������� b��° �������� �߿��� ���� ���� ������ ã�� ���� ����� ���� �ƴϴ�. ������ �̿� ���� a, b�� ���� M(1 �� M �� 100,000)�� �־����� ���� ����� ������ �ȴ�. �� ������ �ذ��� ����.

���⼭ a��°��� ���� �ԷµǴ� ������ a��°��� �̾߱��̴�. ���� ��� a=1, b=3�̶�� �Էµ� ������� 1��, 2��, 3�� ���� �߿��� �ּҰ��� ã�ƾ� �Ѵ�. ������ �������� 1�̻� 1,000,000,000������ ���� ���´�.

�Է�
ù° �ٿ� N, M�� �־�����. ���� N���� �ٿ��� N���� ������ �־�����. ���� M���� �ٿ��� a, b�� ���� �־�����.

���
M���� �ٿ� �Է¹��� ������� �� a, b�� ���� ���� ����Ѵ�.

���� �Է� 1
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
���� ��� 1
5
38
20
5

Ǯ��:
���׸�Ʈ Ʈ���� ������ �ּڰ��� �����ϵ��� �Ѵ�.
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
