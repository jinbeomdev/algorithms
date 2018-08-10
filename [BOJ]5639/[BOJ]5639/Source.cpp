#include <cstdio>
#include <vector>

using namespace std;

vector<pair<int, int>> tree(1000000, make_pair(-1, -1)); // saving left, right children index

void getTree(int root, int key) {
	if (root < key) {
		if (tree[root].second == -1) {
			tree[root].second = key;
		} else {
			getTree(tree[root].second, key);
		}
	} else {
		if (tree[root].first == -1) {
			tree[root].first = key;
		} else {
			getTree(tree[root].first, key);
		}
	}
}

void PostOrder(int root) {
	if (tree[root].first != -1) PostOrder(tree[root].first);
	if (tree[root].second != -1) PostOrder(tree[root].second);
	printf("%d\n", root);
}

int main() {
	int key;
	int root;
	scanf("%d", &root);
	
	while (scanf("%d", &key) != EOF) {
		getTree(root, key);
	}

	/* for debuging
	while (true) {
		scanf("%d", &key);
		if (key == -1) break;
		getTree(root, key);
	}
	*/

	PostOrder(root);
}