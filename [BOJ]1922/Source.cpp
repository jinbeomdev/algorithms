//https://www.acmicpc.net/problem/1922

/*
����
�����̴� ��ǻ�Ϳ� ��ǻ�͸� ��� �����ϴ� ��Ʈ��ũ�� �����Ϸ� �Ѵ�. ������ �ƽ��Ե� ��갡 ���� �ʾ� ��ǻ�Ϳ� ��ǻ�͸� ���� �����Ͽ��� �Ѵ�. �׷��� ��ΰ� �ڷḦ �����ϱ� ���ؼ��� ��� ��ǻ�Ͱ� ������ �Ǿ� �־�� �Ѵ�. (a�� b�� ������ �Ǿ� �ִٴ� ���� a���� b���� ��ΰ� �����Ѵٴ� ���� �ǹ��Ѵ�. a���� b�� �����ϴ� ���� �ְ�, b�� c�� �����ϴ� ���� ������ a�� c�� ������ �Ǿ� �ִ�.)

�׷��� �̿��̸� ��ǻ�͸� �����ϴ� ����� �ּҷ� �Ͽ��� ��ǻ�͸� �����ϴ� ��� �ܿ� �ٸ� ���� ���� �� �� �� ���� ���̴�. ���� �� ��ǻ�͸� �����ϴµ� �ʿ��� ����� �־����� �� ��� ��ǻ�͸� �����ϴµ� �ʿ��� �ּҺ���� ����϶�. ��� ��ǻ�͸� ������ �� ���� ���� ����.

�Է�
ù° �ٿ� ��ǻ���� ��(1<=N<=1000)�� �־�����.

��° �ٿ��� ������ �� �ִ� ���� ��(1<=M<=100,000)�� �־�����.

��° �ٺ��� M+2��° �ٱ��� �� M���� �ٿ� �� ��ǻ�͸� �����ϴµ� ��� ����� �־�����. �� ����� ������ �� ���� ������ �־����µ�, ���࿡ a b c �� �־��� �ִٰ� �ϸ� a��ǻ�Ϳ� b��ǻ�͸� �����ϴµ� ����� c��ŭ ��ٴ� ���� �ǹ��Ѵ�.

���
��� ��ǻ�͸� �����ϴµ� �ʿ��� �ּҺ���� ù° �ٿ� ����Ѵ�.

���� �Է�  ����
6
9
1 2 5
1 3 4
2 3 2
2 4 7
3 4 6
3 5 11
4 5 3
4 6 8
5 6 8
���� ���  ����
23
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int find(int p[], int a) {
	if (p[a] < 0) return a;
	return find(p, p[a]);
}

void merge(int p[], int a, int b) {
	a = find(p, a);
	b = find(p, b);
	if (a == b) return;
	p[b] = a;
}

struct Edge {
	int u, v, w;

	Edge() :Edge(-1, -1, 0) {}
	Edge(int u1, int v1, int w1) : u(u1), v(v1), w(w1) {}
	bool operator <(Edge &rhs) {
		return w < rhs.w;
	}
};

int computers[1000];
Edge e[100000];

int main() {
	memset(computers, -1, sizeof(computers));

	int N;
	int M;

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int a, b, c;

		cin >> a >> b >> c;

		e[i] = Edge(a-1, b-1, c);
	}

	sort(e, e + M);

	int result = 0;
	int cnt = 0;
	for (int i = 0; i < M; i++) {
		if (cnt == N - 1) break;
		if (find(computers, e[i].u) == find(computers, e[i].v)) continue;

		result += e[i].w;
		cnt++;
		merge(computers, e[i].u, e[i].v);
	}

	cout << result;
}