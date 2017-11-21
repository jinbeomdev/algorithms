/*
https://www.acmicpc.net/problem/1068

����
Ʈ������ ���� ����, �ڽ��� ������ 0�� ��带 ���Ѵ�.

Ʈ���� �־����� ��, ��� �� �ϳ��� ������ ���̴�. �� ��, ���� Ʈ������ ���� ����� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

���� ���, ������ ���� Ʈ���� �ִٰ� ����.



���� ���� ����� ������ 3���̴�. (�ʷϻ� ��ĥ�� ���) �� ��, 1���� �����Ѵٰ� �ϸ�, ������ ���� �ȴ�.



���� ���� ����� ������ 1���̴�.

�Է�
ù° �ٿ� Ʈ���� ����� ���� N�� �־�����. N�� 50���� �۰ų� ���� �ڿ����̴�. ��° �ٿ��� 0�� ������ N-1�� ������, �� ����� �θ� �־�����. ���� �θ� ���ٸ� (��Ʈ) -1�� �־�����. ��° �ٿ��� ���� ����� ��ȣ�� �־�����.

���
ù° �ٿ� �Է����� �־��� Ʈ������ �Է����� �־��� ��带 ������ ��, ���� ����� ������ ����Ѵ�.

���� �Է�  ����
5
-1 0 0 1 1
2
���� ���  ����
2
*/
#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e10;

int N;
vector<vector<int>> parent_nodes;
int num_leaf_node = 0;
int deleted_node;
int root;

int dfs(int parent_node, int node) {
	if(node == deleted_node) {
		return 0;
	}
	else if (parent_nodes[node].size() == 1 && parent_nodes[node][0] == deleted_node) {
		return 1;
	}
	else if (parent_nodes[node].size() == 0) {
		return 1;
	}

	for (int i = 0; i < parent_nodes[node].size(); i++) {
		int next_node = parent_nodes[node][i];

		num_leaf_node += dfs(node, next_node);
	}

	return 0;
}

int main() {
	cin >> N;

	parent_nodes = vector<vector<int>>(N);

	for (int childe_node = 0; childe_node < N; childe_node++) {
		int parent_node;

		cin >> parent_node;

		if (parent_node == -1) {
			root = childe_node;
			continue;
		}

		parent_nodes[parent_node].push_back(childe_node);
	}
	
	cin >> deleted_node;

	dfs(-1, root);

	cout << num_leaf_node;
}