//https://www.acmicpc.net/problem/2150

/*
����
���� �׷����� �־����� ��, �� �׷����� SCC��� ������ ���α׷��� �ۼ��Ͻÿ�.

���� �׷����� SCC�� �켱 ������ �ִ� �κ������̸�, �� �κ����տ� ����ִ� ���� �ٸ� ������ �� ���� u, v�� ���ؼ� u���� v�� ���� ��ο� v���� u�� ���� ��ΰ� ��� �����ϴ� ��츦 ���Ѵ�.



���� ��� ���� ���� �׸��� ����. �� �׷������� SCC���� {a, b, e}, {c, d}, {f, g}, {h} �� �ִ�. ���� h���� h�� ���� ������ ���� ��쿡�� {h}�� SCC�� �̷��.

�Է�
ù° �ٿ� �� ���� V(1��V��10,000), E(1��E��100,000)�� �־�����. �̴� �׷����� V���� ������ E���� �������� �̷���� �ִٴ� �ǹ��̴�. ���� E���� �ٿ��� ������ ���� ������ ��Ÿ���� �� ���� A, B�� �־�����. �̴� A�� ������ B�� ������ ����Ǿ� �ִٴ� �ǹ��̴�. �� �� ������ A->B�� �ȴ�.

���
ù° �ٿ� SCC�� ������ K�� ����Ѵ�. ���� K���� �ٿ��� �� �ٿ� �ϳ��� SCC�� ���� ������ ��ȣ�� ����Ѵ�. �� ���� ������ -1�� ����Ͽ� �� ���� ���� ��Ÿ����. ������ SCC�� ����� �� �� �ȿ� ���� �������� ������������ ����Ѵ�. ���� ���� ���� SCC�� ���ؼ��� �� �ȿ� �����ִ� ���� ���� ������ ���� ��ȣ ������ ����Ѵ�.

���� �Է�  ����
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
���� ���  ����
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

// SN: SCC ����, sn[i]: i�� ���� SCC�� ��ȣ
int V, E, cnt, dfsn[MAX], SN, sn[MAX];
vector<int> adj[MAX];
bool finished[MAX]; // SCC �и��� ���� ������ true
stack<int> S;
vector<vector<int>> SCC;

// �ڽ��� ������� �����ϴ� DFS �Լ�
int DFS(int curr) {
	dfsn[curr] = ++cnt; // dfsn ����
	S.push(curr); // ���ÿ� �ڽ��� push

				  // �ڽ��� dfsn, �ڽĵ��� ����� dfsn �� ���� ���� ��ȣ�� result�� ����
	int result = dfsn[curr];
	for (int next : adj[curr]) {
		// ���� �湮���� ���� �̿�
		if (dfsn[next] == 0) result = min(result, DFS(next));
		// �湮�� ������ ���� SCC�� ��������� ���� �̿�
		else if (!finished[next]) result = min(result, dfsn[next]);
	}

	// �ڽ�, �ڽ��� �ڼյ��� ���� ������ ���� ���� ������ �ڽ��� ��� SCC ����
	if (result == dfsn[curr]) {
		vector<int> currSCC;
		// ���ÿ��� �ڽ��� ���� ������ pop
		while (1) {
			int t = S.top();
			S.pop();
			currSCC.push_back(t);
			finished[t] = true;
			sn[t] = SN;
			if (t == curr) break;
		}
		// ����� ���� ���� ����
		sort(currSCC.begin(), currSCC.end());
		// SCC ����
		SCC.push_back(currSCC);
		SN++;
	}
	return result;
}

int main() {
	// �׷��� ���� �Է�
	std::cin >> V >> E;
	for (int i = 0; i<E; i++) {
		int A, B;
		std::cin >> A >> B;
		adj[A - 1].push_back(B - 1);
	}

	// DFS�� �ϸ� SCC ����
	for (int i = 0; i<V; i++)
		if (dfsn[i] == 0) DFS(i);
	// ����� ���� SCC���� ����
	sort(SCC.begin(), SCC.end());

	// SCC ����
	printf("%d\n", SN);
	// �� SCC ���
	for (auto& currSCC : SCC) {
		for (int curr : currSCC)
			printf("%d ", curr + 1);
		puts("-1");
	}
}