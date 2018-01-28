//https://www.acmicpc.net/problem/2150

/*
문제
방향 그래프가 주어졌을 때, 그 그래프를 SCC들로 나누는 프로그램을 작성하시오.

방향 그래프의 SCC는 우선 정점의 최대 부분집합이며, 그 부분집합에 들어있는 서로 다른 임의의 두 정점 u, v에 대해서 u에서 v로 가는 경로와 v에서 u로 가는 경로가 모두 존재하는 경우를 말한다.



예를 들어 위와 같은 그림을 보자. 이 그래프에서 SCC들은 {a, b, e}, {c, d}, {f, g}, {h} 가 있다. 물론 h에서 h로 가는 간선이 없는 경우에도 {h}는 SCC를 이룬다.

입력
첫째 줄에 두 정수 V(1≤V≤10,000), E(1≤E≤100,000)가 주어진다. 이는 그래프가 V개의 정점과 E개의 간선으로 이루어져 있다는 의미이다. 다음 E개의 줄에는 간선에 대한 정보를 나타내는 두 정수 A, B가 주어진다. 이는 A번 정점과 B번 정점이 연결되어 있다는 의미이다. 이 때 방향은 A->B가 된다.

출력
첫째 줄에 SCC의 개수를 K를 출력한다. 다음 K개의 줄에는 각 줄에 하나의 SCC에 속한 정점의 번호를 출력한다. 각 줄의 끝에는 -1을 출력하여 그 줄의 끝을 나타낸다. 각각의 SCC를 출력할 때 그 안에 속한 정점들은 오름차순으로 출력한다. 또한 여러 개의 SCC에 대해서는 그 안에 속해있는 가장 작은 정점의 정점 번호 순으로 출력한다.

예제 입력  복사
7 9
1 4
4 5
5 1
1 6
6 7
2 7
7 3
3 7
7 2
예제 출력  복사
3
1 4 5 -1
2 3 7 -1
6 -1
*/

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
const int MAX = 10000;

// SN: SCC 개수, sn[i]: i가 속한 SCC의 번호
int V, E, cnt, dfsn[MAX], SN, sn[MAX];
vector<int> adj[MAX];
bool finished[MAX]; // SCC 분리가 끝난 정점만 true
stack<int> S;
vector<vector<int>> SCC;

// 자신의 결과값을 리턴하는 DFS 함수
int DFS(int curr) {
	dfsn[curr] = ++cnt; // dfsn 결정
	S.push(curr); // 스택에 자신을 push

				  // 자신의 dfsn, 자식들의 결과나 dfsn 중 가장 작은 번호를 result에 저장
	int result = dfsn[curr];
	for (int next : adj[curr]) {
		// 아직 방문하지 않은 이웃
		if (dfsn[next] == 0) result = min(result, DFS(next));
		// 방문은 했으나 아직 SCC로 추출되지는 않은 이웃
		else if (!finished[next]) result = min(result, dfsn[next]);
	}

	// 자신, 자신의 자손들이 도달 가능한 제일 높은 정점이 자신일 경우 SCC 추출
	if (result == dfsn[curr]) {
		vector<int> currSCC;
		// 스택에서 자신이 나올 때까지 pop
		while (1) {
			int t = S.top();
			S.pop();
			currSCC.push_back(t);
			finished[t] = true;
			sn[t] = SN;
			if (t == curr) break;
		}
		// 출력을 위해 원소 정렬
		sort(currSCC.begin(), currSCC.end());
		// SCC 추출
		SCC.push_back(currSCC);
		SN++;
	}
	return result;
}

int main() {
	// 그래프 정보 입력
	std::cin >> V >> E;
	for (int i = 0; i<E; i++) {
		int A, B;
		std::cin >> A >> B;
		adj[A - 1].push_back(B - 1);
	}

	// DFS를 하며 SCC 추출
	for (int i = 0; i<V; i++)
		if (dfsn[i] == 0) DFS(i);
	// 출력을 위해 SCC들을 정렬
	sort(SCC.begin(), SCC.end());

	// SCC 개수
	printf("%d\n", SN);
	// 각 SCC 출력
	for (auto& currSCC : SCC) {
		for (int curr : currSCC)
			printf("%d ", curr + 1);
		puts("-1");
	}
}