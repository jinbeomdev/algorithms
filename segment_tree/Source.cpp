/*
segment tree init, sum, update
*/

#include <iostream>
#include <vector>

using namespace std;

long long init(vector<long long> &a,
							 vector<long long> &segment_tree,
							 int node, int start, int end) {
	if (start == end) {
		segment_tree[node] = a[start];
	} else {
		int mid = (start + end) / 2;
		segment_tree[node] = init(a, segment_tree, node * 2, start, mid) +
												 init(a, segment_tree, node * 2 + 1, mid + 1, end);
	}
}

long long sum(vector<long long> &segment_tree,
						  int node,
							int start, int end,
							int left, int right) {
	if (start > right || end < left) return 0;
	if (start >= left && end <= right) return segment_tree[node];

	int mid = (start + end) / 2;
	return sum(segment_tree, node * 2, start, mid, left, right) +
				 sum(segment_tree, node * 2, mid + 1, end, left, right);
}

void update(vector<long long> &segment_tree,
						int node,
						int start, int end,
						int index,
						long long diff) {
	if (index < start || index > end) return;
	segment_tree[node] = segment_tree[node] + diff;
	if (start != end) {
		int mid = (start + end) / 2;
		update(segment_tree, node * 2, start, mid, index, diff);
		update(segment_tree, node * 2 + 1, mid + 1, end, index, diff);
	}
}