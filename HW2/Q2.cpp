
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void insertionSort(vector<long long>& arr) {
	int n = arr.size();
	for (int i = 1; i < n; i++) {
		long long key = arr[i];
		int j = i - 1;

		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

long long countPieces(const vector<long long>& arz, const vector<long long>& tol, long long x) {
	int n = arz.size();
	int m = tol.size();

	int j = m - 1;
	long long cnt = 0;

	for (int i = 0; i < n; i++) {
		while (j >= 0 && arz[i] * tol[j] >= x) {
			j--;
		}

		cnt += m - j - 1;
	}

	return cnt;
}

long long solve(vector<long long>& arz,
				vector<long long>& tol,
				long long num) {
	
	insertionSort(arz);
	insertionSort(tol);

	long long low = 1;
	long long high = arz.back() * tol.back();
	long long ans = 0;

	while (low <= high) {
		long long mid = (high + low) / 2;

		if (countPieces(arz, tol, mid) >= num) {
			ans = mid;
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}

	return ans;
}

int main() {

	int q;
	cin >> q;

	while (q--) {
		int n, m;
		long long num;

		cin >> n >> m >> num;

		vector<long long> arz(n), tol(m);

		for (int i = 0; i < n; i++) {
			cin >> arz[i];
		}

		for (int i = 0; i < m; i++) {
			cin >> tol[i];
		}

		cout << solve(arz, tol, num) << '\n';
	}

	return 0;
}
