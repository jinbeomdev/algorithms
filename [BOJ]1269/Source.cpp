//https://www.acmicpc.net/problem/1269

/*
��Ī ������ Ǯ��
������
�ð� ����	�޸� ����	����	����	���� ���	���� ����
2 ��	128 MB	1539	702	532	45.626%
����
�ڿ����� ���ҷ� ���� �������� �ƴ� �� ���� A�� B�� �ִ�. �� ��, �� ������ ��Ī �������� ������ ������ ����ϴ� ���α׷��� �ۼ��Ͻÿ�. �� ���� A�� B�� ���� ��, (A-B)�� (B-A)�� �������� A�� B�� ��Ī �������̶�� �Ѵ�.

���� ���, A = { 1, 2, 4 } �̰�, B = { 2, 3, 4, 5, 6 } ��� �� ��,  A-B = { 1 } �̰�, B-A = { 3, 5, 6 } �̹Ƿ�, ��Ī �������� ������ ������ 1 + 3 = 4���̴�.

�Է�
ù° �ٿ� ���� A�� ������ ������ ���� B�� ������ ������ �� ĭ�� ���̿� �ΰ� �־�����. ��° �ٿ��� ���� A�� ��� ���Ұ�, ��° �ٿ��� ���� B�� ��� ���Ұ� �� ĭ�� ���̿� �ΰ� ���� �־�����. �� ������ ������ ������ 200,000�� ���� ������, ��� ������ ���� 100,000,000�� ���� �ʴ´�.

���
ù° �ٿ� ��Ī �������� ������ ������ ����Ѵ�.

���� �Է�  ����
3 5
1 2 4
2 3 4 5 6
���� ���  ����
4
*/
#include <iostream>
#include <set>

using namespace std;

int main() {
	set<int> set_a;
	set<int> set_b;
	int num_a, num_b;

	cin >> num_a >> num_b;

	for (int i = 0; i < num_a; i++) {
		int element;

		cin >> element;
		
		set_a.insert(element);
	}

	for (int i = 0; i < num_b; i++) {
		int element;

		cin >> element;

		set_b.insert(element);
	}

	set<int> temp_set_a;
	for (set<int>::iterator it_a = set_a.begin(); it_a != set_a.end(); it_a++) {
		set<int>::iterator find_it = set_b.find(*it_a);

		if (find_it == set_b.end()) {
			temp_set_a.insert(*it_a);
			continue;
		}

		set_b.erase(find_it);
	}

	cout << temp_set_a.size() + set_b.size();
}