/*
https://www.acmicpc.net/problem/1068

문제
트리에서 리프 노드란, 자식의 개수가 0인 노드를 말한다.

트리가 주어졌을 때, 노드 중 하나를 제거할 것이다. 그 때, 남은 트리에서 리프 노드의 개수를 구하는 프로그램을 작성하시오.

예를 들어, 다음과 같은 트리가 있다고 하자.



현재 리프 노드의 개수는 3개이다. (초록색 색칠된 노드) 이 때, 1번을 제거한다고 하면, 다음과 같이 된다.



이제 리프 노드의 개수는 1개이다.

입력
첫째 줄에 트리의 노드의 개수 N이 주어진다. N은 50보다 작거나 같은 자연수이다. 둘째 줄에는 0번 노드부터 N-1번 노드까지, 각 노드의 부모가 주어진다. 만약 부모가 없다면 (루트) -1이 주어진다. 셋째 줄에는 지울 노드의 번호가 주어진다.

출력
첫째 줄에 입력으로 주어진 트리에서 입력으로 주어진 노드를 지웠을 때, 리프 노드의 개수를 출력한다.

예제 입력  복사
5
-1 0 0 1 1
2
예제 출력  복사
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