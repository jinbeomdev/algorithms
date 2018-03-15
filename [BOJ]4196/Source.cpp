//https://www.acmicpc.net/problem/4196

/*
����
���̳�� ��մ�. ���̳� ����� �Ϸķ� ��� �þ�� �� ��� �ϳ��� �Ѿ�߸��� �� ����� �Ѿ����� ���� ����� �Ѿ�߸��� ���� �ݺ��Ǿ� �Ϸķ� �þ ��ϵ��� ���������� ��� �����߸� �� �ִ�. �׷���, ������ ���̳밡 �ٸ� ����� �Ѿ�߸��� ���ϰ� ��ġ�Ǿ� �ִٸ�, �츮�� ���� ����� �������� �Ѿ�߷��� �Ѵ�.

���� �� ���̳� ����� ��ġ�� �־����� ��, ��� ����� �Ѿ�߸��� ���� ������ �Ѿ�߷��� �ϴ� ��� ������ �ּҰ��� ������.

�Է�
ù ��° �ٿ� �׽�Ʈ ���̽��� ������ �־�����.

�� �׽�Ʈ ���̽��� ù ��° �ٿ��� �� ���� N, M�� �־����� �� ���� 100,000�� ���� �ʴ´�. N�� ���̳��� ������, M�� ������ ������ ��Ÿ����. ���̳� ����� ��ȣ�� 1�� N ������ ������. ���� M���� �ٿ��� ���� �� ���� x, y�� �־����µ�, �̴� x�� ����� �Ѿ����� y�� ��ϵ� �Ѿ����� ���Ѵ�.

���
�� �׽�Ʈ ���̽����� �� �ٿ� ���� �ϳ��� ����Ѵ�. ������ ������ �Ѿ�߷��� �ϴ� �ּ��� ���̳� ��� �����̴�.

���� �Է�
1
3 2
1 2
2 3
���� ���
1
*/

#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
#include <algorithm>

using namespace std;

const int MAX = 100001;

vector<int> adj[MAX];
int dfsn[MAX];
bool finished[MAX];
int sn;
int scc_index;
int scc[MAX];
int scc_indegree[MAX];
stack<int> scc_stack;

int dfs(int n) {
	dfsn[n] = scc_index++;
	scc_stack.push(n);

	int result = n;
	for (int next : adj[n]) {
		if (dfsn[next] == 0) {
			result = min(result, dfs(next));
		}
		else if (!finished[next]) {
			result = min(result, dfs(next));
		}
	}

	if (result == n) {
		int temp;
		
		do {
			temp = scc_stack.top();
			scc_stack.pop();

			scc[temp] = sn;
			finished[temp] = true;
		} while (temp != n);

		sn++;
	}

	return result;
}

int main() {
	int T, test_case;

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int N, M;

		cin >> N >> M;
		
		//init
		sn = 0;
		scc_index = 1;

		for (int i = 1; i <= N; i++) {
			adj[i].clear();
		}

		while (!scc_stack.empty()) {
			scc_stack.pop();
		}

		memset(dfsn, 0, sizeof(dfsn));
		memset(finished, false, sizeof(finished));
		memset(scc, 0, sizeof(scc));
		memset(scc_indegree, 0, sizeof(scc_indegree));

		for (int i = 0; i < M; i++) {
			int x, y;

			cin >> x >> y;

			adj[x].push_back(y);
		}

		//to separate the graph as SCC 
		for (int i = 1; i <= N; i++) {
			if (dfsn[i] == 0) {
				dfs(i);
			}
		}

		for (int i = 1; i <= N; i++) {
			for (int j : adj[i]) {
				if (scc[i] != scc[j]) {
					scc_indegree[scc[j]]++;
				}
			}
		}

		int result = 0;

		for (int i = 0; i < sn; i++) {
			if (scc_indegree[i] == 0) {
				result++;
			}
		}

		cout << result << endl;
	}

	//system("pause");
}