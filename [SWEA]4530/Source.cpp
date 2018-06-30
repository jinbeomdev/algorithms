/*
	4530. 극한의 청소 작업 D4
*/

#include <cstdio>

int T;
long long A, B;
long long answer;

long long abs(const long long a) {
	if (a > 0) {
		return a;
	} else {
		return -a;
	}
}

long long diff(const long long a, const long long b) {
	return abs(a - b);
}

long long power(const int base, const int num) {
	long long result = 1;

	for (int i = 0; i < num; i++) {
		result = result * base;
	}

	return result;
}

long long solution(const long long num) {
	long long temp = abs(num);
	int num_length = 0;
	
	while (temp > 0) {
		temp = temp / 10;
		num_length++;
	}

	temp = abs(num);

	long long sum = 0;
	while (num_length > 0) {
		long long h = temp / power(10, num_length - 1);
		temp = temp % power(10, num_length - 1);
		//printf("h:%d\n", h);

		if (h > 4) {
			sum += (h - 1) * power(9, num_length - 1);
		} else {
			sum += h * power(9, num_length - 1);
		}

		num_length--;
	}

	return sum;
}

int main() {
	scanf("%d", &T);
	
	for (int test_case = 1; test_case <= T; test_case++) {
		answer = 0;
		scanf("%lld %lld", &A, &B);


		//부호가 같을 때
		if ((A < 0 && B < 0) ||
			  (A > 0 && B > 0)) {
			answer = diff(solution(A), solution(B));
		}
		//부호가 다를 때
		else if (A < 0 && B > 0) {
			answer = solution(A) + solution(B) - 1;
		}
		
		printf("%c%d %lld\n",
			'#', test_case, answer);
	}
}