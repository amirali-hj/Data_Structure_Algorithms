
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long countPieces(const vector<long long>& a, const vector<long long>& b, long long x) {
    int n = a.size();
    int m = b.size();

    int j = m - 1;
    long long cnt = 0;

    for (int i = 0; i < n; i++) {
        while (j >= 0 && a[i] * b[j] >= x) {
            j--;
        }

        cnt += m - j - 1;
    }

    return cnt;
}

long long solve(vector<long long>& a,
                vector<long long>& b,
                long long k) {

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    long long low = 1;
    long long high = a.back() * b.back();
    long long ans = 0;

    while (low <= high) {
        long long mid = (high + low) / 2;

        if (countPieces(a, b, mid) >= k) {
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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    while (q--) {
        int n, m;
        long long k;

        cin >> n >> m >> k;

        vector<long long> a(n), b(m);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }

        cout << solve(a, b, k) << '\n';
    }

    return 0;
}
