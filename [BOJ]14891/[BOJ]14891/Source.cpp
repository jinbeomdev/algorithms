/*
	���ǻ��� :
	ȸ���� ��Ų ����� ���� ��Ϲ����� ���ĵǴ� ���� �ƴ϶�
	ȸ���� ��Ű�� ���� ȸ���ؾ��� ��Ϲ����� �̹� �����Ǿ� �ִ�.
*/
#include <stdio.h>

int arr[4][8];
int K;

void print(int idx, int dir) {
	printf("%d ��Ϲ��� %d �������� ����Ʈ : ", idx, dir);
	for (int i = 0; i < 8; i++) {
		printf("%d", arr[idx][i]);
	}
	puts("");
}


//01234567
void shift(int idx, int dir) {
	int hold;
	if (dir < 0) { //�ݽð�
		hold = arr[idx][0];
		for (int i = 0; i < 7; i++) {
			arr[idx][i] = arr[idx][i + 1];
		}
		arr[idx][7] = hold;
	} else { //�ð�
		hold = arr[idx][7];
		for (int i = 7; i > 0; i--) {
			arr[idx][i] = arr[idx][i - 1];
		}
		arr[idx][0] = hold;
	}

	//print(idx, dir);
}

int main() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}

	scanf("%d", &K);

	for (int i = 0; i < K; i++) {
		int idx, dir;

		scanf("%d%d", &idx, &dir);
		idx--;

		int left_dir = dir;
		int left_dirs[] = { 0, 0, 0, 0 };
		bool left_is_cir[] = { false, false, false, false };
		for (int pivot = idx; pivot > 0; pivot--) {
			if (arr[pivot][6] != arr[pivot - 1][2]) { //���� üũ
				left_is_cir[pivot - 1] = true;
				left_dirs[pivot - 1] = (left_dir *= -1);
			} else {
				break;
			}
		}

		int right_dir = dir;
		int right_dirs[] = { 0, 0, 0, 0 };
		bool right_is_cir[] = { false, false, false, false };
		for (int pivot = idx; pivot < 3; pivot++) {
			if (pivot + 1 < 4 && arr[pivot][2] != arr[pivot + 1][6]) {//������ üũ
				right_is_cir[pivot + 1] = true;
				right_dirs[pivot + 1] = (right_dir *= -1);
			} else {
				break;
			}
		}

		for (int i = 0; i < 4; i++) {
			if (left_is_cir[i]) shift(i, left_dirs[i]);
			if (right_is_cir[i]) shift(i, right_dirs[i]);
		}

		shift(idx, dir);
	}

	int ret = 0;
	for (int i = 0, pow = 1; i < 4; i++, pow *= 2) {
		if (arr[i][0] == 1) ret += pow;
	}

	printf("%d", ret);
}