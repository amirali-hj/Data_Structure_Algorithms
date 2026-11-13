
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void merge(vector<long long>& target, int left, int mid, int right) {
	vector<long long> temp;

	int i = left;
	int j = mid + 1;

	while (i <= mid && j <= right) {
		if (target[i] <= target[j]) {
			temp.push_back(target[i]);
			i++;
		}
		else {
			temp.push_back(target[j]);
			j++;
		}
	}

	while (i <= mid) {
		temp.push_back(target[i]);
		i++;
	}

	while (j <= right) {
		temp.push_back(target[j]);
		j++;
	}

	for (int k = 0; k < (int)temp.size(); k++) {
		target[left + k] = temp[k];
	}
}

void mergeSort(vector<long long>& target, int left, int right) {
    if (left >= right) {
        return;
    }

    int mid =  (right + left) / 2;

    mergeSort(target, left, mid);
    mergeSort(target, mid + 1, right);

    merge(target, left, mid, right);
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
	
	mergeSort(arz, 0, arz.size() - 1);
	mergeSort(tol, 0, tol.size() - 1);

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
