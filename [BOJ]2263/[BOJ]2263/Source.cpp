#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int N;

vector<int> slice(const vector<int>& v, int left, int right) {
	return vector<int>(v.begin() + left, v.begin() + right);
}

void printPreorder(const vector<int>& inorder, const vector<int>& postorder) {
	if (postorder.empty()) return;

	int root = postorder.back();
	int left_size = find(inorder.begin(), inorder.end(), root) - inorder.begin();

	printf("%d ", root);
	printPreorder(slice(inorder, 0, left_size), slice(postorder, 0, left_size));
	printPreorder(slice(inorder, left_size + 1, inorder.size()), slice(postorder, left_size, postorder.size() - 1));
}

void printPreorder2(const vector<int>& inorder, int in_left, int in_right,
										const vector<int>& postorder, int post_left, int post_right) {
	if (in_left > in_right) return;

	int root = postorder[post_right];
	int left_size = find(inorder.begin() + in_left, inorder.begin() + in_right + 1, root) - inorder.begin() - in_left;

	printf("%d ", root);
	printPreorder2(inorder, in_left, in_left + left_size - 1, postorder, post_left, post_left + left_size - 1);
	printPreorder2(inorder, in_left + left_size + 1, in_right, postorder, post_left + left_size, post_right - 1);
}

int main() {
	scanf("%d", &N);
	vector<int> inorder;
	vector<int> postorder;

	for (int i = 0; i < N; i++) {
		int node;
		scanf("%d", &node);
		inorder.push_back(node);
	}

	for (int i = 0; i < N; i++) {
		int node;
		scanf("%d", &node);
		postorder.push_back(node);
	}

	//printPreorder(inorder, postorder);
	printPreorder2(inorder, 0, inorder.size() -1, postorder, 0, postorder.size() - 1);
}