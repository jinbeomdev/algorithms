#include <stdio.h>
#include <deque>

using namespace std;

int T;
deque<int> deq[1000];
int K;
bool spin[999];

int main() {
	scanf("%d", &T);
	for(int i = 0; i < T;i ++) {
		for(int j = 0; j < 8; j++) {
			int a;
			scanf("%1d", &a);
			deq[i].push_back(a);
		}
	}
	scanf("%d", &K);
	for(int i = 0; i < K; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		a--;
		for(int j = 0; j < T - 1; j++) {
			if(deq[j].at(2) == deq[j + 1].at(6)) spin[j] = false;
			else spin[j] = true;
		}
		int right=a; int right_d = b;
		int left=a-1; int left_d = b * -1;
		while(right < T) {
			//printf("right : %d\n", right);
			if(right_d == 1) {
				int temp = deq[right].back();
				deq[right].pop_back();
				deq[right].push_front(temp);
			} else {
				int temp = deq[right].front();
				deq[right].pop_front();
				deq[right].push_back(temp);
			}
			for(int p = 0; p < 8; p++) {
				//printf("%d", deq[right].at(p));
			}
			//printf("\n");
			if(right == T -1) break;
			if(spin[right]) {
				right_d *= -1;
				right++;
			} else {
				break;
			}
		}
		while(left >= 0 && spin[left]) {
			//printf("left :%d", left);
			if(left_d == 1) {
				int temp = deq[left].back();
				deq[left].pop_back();
				deq[left].push_front(temp);
			} else {
				int temp = deq[left].front();
				deq[left].pop_front();
				deq[left].push_back(temp);
			}
			for(int p = 0; p < 8; p++) {
				//printf("%d", deq[left].at(p));
			}
			//printf("\n");
			if(left == 0) break;
			left--;
			if(spin[left]) {
				left_d *= -1;
			} else {
				break;
			}
		}
		//printf("\n");
	}
	int answer = 0;
	for(int i = 0; i < T; i++) {
		if(deq[i].at(0) == 1) answer++;
	}
	printf("%d", answer);
}
