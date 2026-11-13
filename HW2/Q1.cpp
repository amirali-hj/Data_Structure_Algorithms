
#include <iostream>
#include <vector>
using namespace std;

long long merge(vector<int>& input_vec, vector<int>& curr_vec, int left, int mid, int right) {
	int L = left;
	int R = mid + 1;
	int index = left;
	long long num = 0;

	while (L <= mid && R <= right) {
		if (input_vec[L] <= input_vec[R]) {
			curr_vec[index++] = input_vec[L++];
		}
		else {
			curr_vec[index++] = input_vec[R++];
			num += mid - L + 1;
		}
	}

	while (L <= mid) {
		curr_vec[index++] = input_vec[L++];
	}

	while (R <= right) {
		curr_vec[index++] = input_vec[R++];
	}

	for (int p = left; p <= right; p++) {
		input_vec[p] = curr_vec[p];
	}

	return num;
}

long long merge_sort(vector<int>& input_vec, vector<int>& curr_vec, int left, int right) {
	if (left >= right) {
		return 0;
	}

	int mid = (right + left) / 2;

	long long num = merge_sort(input_vec, curr_vec, left, mid);
	num += merge_sort(input_vec, curr_vec, mid + 1, right);
	num += merge(input_vec, curr_vec, left, mid, right);

	return num;
}

int main() {
	int n;
	cin >> n;

	vector<int> input_vec(n);
	vector<int> curr_vec(n);

	for (int L = 0; L < n; L++) {
		cin >> input_vec[L];
	}

	cout << merge_sort(input_vec, curr_vec, 0, n - 1) << '\n';

	return 0;
}