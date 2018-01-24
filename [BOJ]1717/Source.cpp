//https://www.acmicpc.net/problem/1717

/*
������ ǥ�� ����� ���� Ǯ��
������
�ð� ����	�޸� ����	����	����	���� ���	���� ����
2 ��	128 MB	8127	2626	1743	30.171%
����
�ʱ⿡ {0}, {1}, {2}, ... {n} �� ���� n+1���� ������ �̷�� �ִ�. ���⿡ ������ �����, �� ���Ұ� ���� ���տ� ���ԵǾ� �ִ����� Ȯ���ϴ� ������ �����Ϸ��� �Ѵ�.

������ ǥ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� n(1��n��1,000,000), m(1��m��100,000)�� �־�����. m�� �Է����� �־����� ������ �����̴�. ���� m���� �ٿ��� ������ ������ �־�����. �������� 0 a b�� ���·� �Է��� �־�����. �̴� a�� ���ԵǾ� �ִ� ���հ�, b�� ���ԵǾ� �ִ� ������ ��ģ�ٴ� �ǹ��̴�. �� ���Ұ� ���� ���տ� ���ԵǾ� �ִ����� Ȯ���ϴ� ������ 1 a b�� ���·� �Է��� �־�����. �̴� a�� b�� ���� ���տ� ���ԵǾ� �ִ����� Ȯ���ϴ� �����̴�. a�� b�� n ������ �ڿ����Ǵ� 0�̸� ���� ���� �ִ�.

���
1�� �����ϴ� �Է¿� ���ؼ� �� �ٿ� �ϳ��� YES/NO�� ����� ����Ѵ�. (yes/no �� ����ص� �ȴ�)

���� �Է�  ����
7 8
0 1 3
1 1 7
0 7 6
1 7 1
0 3 7
0 4 2
0 1 1
1 1 1
���� ���  ����
NO
NO
YES
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> parents;

int find(int n) {
	if (parents[n] < 0) return n;
	parents[n] = find(parents[n]);
	return parents[n];
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	if (parents[a] < parents[b]) {
		parents[a] += parents[b];
		parents[b] = a;
	}
	else {
		parents[b] += parents[a];
		parents[a] = b;
	}
}

string is_equls_root(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return string("YES");
	else return string("NO");
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n, m;

	cin >> n >> m;

	parents = vector<int>(n + 1, -1);

	for (int i = 0; i < m; i++) {
		int operation, a, b;

		cin >> operation >> a >> b;

		if (operation == 0) {
			merge(a, b);
		}
		else {
			cout << is_equls_root(a, b) << "\n";
		}
	}
}