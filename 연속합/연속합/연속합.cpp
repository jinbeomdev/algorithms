#include <iostream>
#include <vector>

#define INT_MIN     (-2147483647 - 1) // minimum (signed) int value

#define max(a,b) (((a) > (b)) ? (a) : (b))

using namespace std;

vector<int> subSum;

pair<int, pair<int, int>> find_max_crossing_subarry(int low, int mid, int high) {
	int sum;
	int left_sum = INT_MIN;
	int right_sum = INT_MIN;
	int max_left;
	int max_right;

	for (int i = mid; i >= low; i--) {
		sum = subSum[mid] - subSum[i - 1];
		if (sum > left_sum) {
			left_sum = sum;
			max_left = i;
		}
	}

	for (int j = mid + 1; j <= high; j++) {
		sum = subSum[j] - subSum[mid];
		if (sum > right_sum) {
			right_sum = sum;
			max_right = j;
		}
	}
	
	//cout << "left_ sum + right_sum : " << left_sum + right_sum << " max_left : " << max_left << " max_right : " << max_right << endl;
	return make_pair(left_sum + right_sum, make_pair(max_left, max_right));
}


pair<int, pair<int, int>> find_maximum_subarray(int low, int high) {
	if (low == high) {
		return make_pair(subSum[high] - subSum[low - 1], make_pair(low, high));
	}

	int mid = (low + high) / 2;
	pair<int, pair<int, int>> left = find_maximum_subarray(low, mid);
	pair<int, pair<int, int>> right = find_maximum_subarray(mid + 1, high);
	pair<int, pair<int, int>> cross = find_max_crossing_subarry(low, mid, high);

	//cout << "crsss_sum : " << cross.first << " cross_left : " << cross.second.first << " cross_right : " << cross.second.second << endl;

	if (left.first >= right.first && left.first >= cross.first)	return left;
	else if(right.first >= left.first && right.first >= cross.first) return right;
	else return cross;
}

//실패함...ㅠㅠㅠㅠ
//int find_maximum_subarray(int low, int high) {
//	int ret;
//	int mid = (low + high) / 2;
//	int left = mid;
//	int right = mid + 1;
//
//	if (low == high) {
//		return subSum[low] - subSum[low - 1];
//	}
//
//	ret = max(subSum[right] - subSum[left - 1], max(find_maximum_subarray(low, mid), find_maximum_subarray(mid + 1, high)));
//		
//	while (left > low || right < high) {
//		if (right < high && ((left == low) || (subSum[right + 1] - subSum[left - 1] >  subSum[right] - subSum[left - 2]))) {
//			right++;
//		}
//		else {
//			left--;
//		}
//
//		ret = max(ret, subSum[right] - subSum[left - 1]);
//
//	}
//
//	return ret;
//}

int main() {
	int N;
	int p = 1, q = 2;

	cin >> N;

	subSum = vector<int>(N + 1, 0);

	for (int i = 1; i < N + 1; i++) {
		int temp;
		cin >> temp;
		
		subSum[i] = subSum[i - 1] + temp;
	}

	////O(n2) brute-force solution -> 시간초과
	//for (int i = 1; i <= N; i++) {
	//	for (int j = 1; j <= N; j++) {
	//		if (Answer < subSum[j] - subSum[i - 1])
	//			Answer = subSum[j] - subSum[i - 1];
	//	}
	//}

	//cout << Answer << endl;

	pair<int, pair<int, int>> Answer = find_maximum_subarray(1, N);

	//cout << "low : " << Answer.second.first << " high : " << Answer.second.second << endl;

	cout << Answer.first << endl;
}