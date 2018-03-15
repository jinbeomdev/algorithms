//https://www.acmicpc.net/problem/4196

/*
문제
도미노는 재밌다. 도미노 블록을 일렬로 길게 늘어세운 뒤 블록 하나를 넘어뜨리면 그 블록이 넘어지며 다음 블록을 넘어뜨리는 일이 반복되어 일렬로 늘어선 블록들을 연쇄적으로 모두 쓰러뜨릴 수 있다. 그러나, 가끔씩 도미노가 다른 블록을 넘어뜨리지 못하게 배치되어 있다면, 우리는 다음 블록을 수동으로 넘어뜨려야 한다.

이제 각 도미노 블록의 배치가 주어졌을 때, 모든 블록을 넘어뜨리기 위해 손으로 넘어뜨려야 하는 블록 개수의 최소값을 구하자.

입력
첫 번째 줄에 테스트 케이스의 개수가 주어진다.

각 테스트 케이스의 첫 번째 줄에는 두 정수 N, M이 주어지며 두 수는 100,000을 넘지 않는다. N은 도미노의 개수를, M은 관계의 개수를 나타낸다. 도미노 블록의 번호는 1과 N 사이의 정수다. 다음 M개의 줄에는 각각 두 정수 x, y가 주어지는데, 이는 x번 블록이 넘어지면 y번 블록도 넘어짐을 뜻한다.

출력
각 테스트 케이스마다 한 줄에 정수 하나를 출력한다. 정답은 손으로 넘어뜨려야 하는 최소의 도미노 블록 개수이다.

예제 입력
1
3 2
1 2
2 3
예제 출력
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