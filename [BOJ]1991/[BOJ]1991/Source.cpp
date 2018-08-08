#include <cstdio>
#include <vector>

using namespace std;

vector<pair<int, int>> adj;
int N;

void PreOrder(int root) {
	printf("%c", (char)root + 'A');
	if (adj[root].first != -19) PreOrder(adj[root].first);
	if (adj[root].second != -19) PreOrder(adj[root].second);
}

void InOrder(int root) {
	if (adj[root].first != -19) InOrder(adj[root].first);
	printf("%c", (char)root + 'A');
	if (adj[root].second != -19) InOrder(adj[root].second);
}

void PostOrder(int root) {
	if (adj[root].first != -19) PostOrder(adj[root].first);
	if (adj[root].second != -19) PostOrder(adj[root].second);
	printf("%c", (char)root + 'A');
}

int main() {
	scanf("%d", &N);
	adj.resize(26);
	for (int i = 0; i < N; i++) {
		char parent, left, right;
		scanf("%*[\n]%c%*[ ]%c%*[ ]%c", &parent, &left, &right);
		parent = parent - 'A';
		left = left - 'A';
		right = right - 'A';
		adj[parent].first = (int)left;
		adj[parent].second = (int)right;
	}

	PreOrder(0);
	puts("");
	InOrder(0);
	puts("");
	PostOrder(0);
	puts("");
}