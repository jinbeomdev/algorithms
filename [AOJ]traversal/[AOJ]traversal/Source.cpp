#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int C;
int N;

vector<int> slice(const vector<int>& v, int a, int b) {
	return vector<int>(v.begin() + a, v.begin() + b);
}

void PrintPostOrder(const vector<int>& preorder, const vector<int>& inorder) {
	const int size = preorder.size();

	if (!size) return;

	const int root = preorder[0];

	int left_size = find(inorder.begin(), inorder.end(), root) - inorder.begin();
	int right_size = size - left_size - 1;

	PrintPostOrder(slice(preorder, 1, left_size + 1), slice(inorder, 0, left_size));
	PrintPostOrder(slice(preorder, left_size + 1, size), slice(inorder, left_size + 1, size));
	printf("%d ", root);
}

int main() {
	scanf("%d", &C);

	for (int tc = 0; tc < C; tc++) {
		scanf("%d", &N);

		vector<int> preorder;
		vector<int> inorder;
		
		preorder.resize(N);
		inorder.resize(N);
	
		for (int i = 0; i < N; i++) {
			int input;
			scanf("%d", &input);
			preorder[i] = input;
		}

		for (int i = 0; i < N; i++) {
			int input;
			scanf("%d", &input);
			inorder[i] = input;
		}

		PrintPostOrder(preorder, inorder);
		puts("");
	}
}