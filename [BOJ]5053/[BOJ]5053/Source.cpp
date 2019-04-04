#include <stdio.h>

const int MAX = 10;

class Trie {
public:
	Trie *children[MAX];
	bool isEndOfWord;
	bool hasChildren;

	Trie() {
		for (int i = 0; i < MAX; i++) {
			children[i] = 0;
		}
		isEndOfWord = false;
		hasChildren = false;
	}

	~Trie() {
		for (int i = 0; i < MAX; i++) {
			if (children[i]) delete children[i];
		}
	}

	void insert(char *key) {
		if (*key == '\0') isEndOfWord = true;
		else {
			int next = *key - '0';

			if (!children[next]) children[next] = new Trie();
			hasChildren = true;
			children[next]->insert(key + 1);
		}
	}

	bool consistent() {
		if (isEndOfWord && hasChildren) return false;

		for (int i = 0; i < MAX; i++) {
			if (children[i] && !children[i]->consistent()) return false;
		}
		return true;
	}
};

int main() {
	int T;
	scanf("%d", &T);
	for (int tc = 0; tc < T; tc++) {
		int N;
		scanf("%d", &N);

		Trie *root = new Trie();
		for (int i = 0; i < N; i++) {
			char tel[11];
			scanf("%s", tel);
			root->insert(tel);
		}

		puts(root->consistent() ? "YES" : "NO");
		delete root;
	}
}