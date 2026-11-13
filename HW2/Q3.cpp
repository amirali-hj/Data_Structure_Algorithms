
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int a, b, c;
    cin >> a >> b >> c;

    vector<long long> volume(a, 0);

    long long total = 0;

    for (int i = 0; i < n; i++) {
        int x1, y1, z1, x2, y2, z2;
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;

        long long area = 1LL * (y2 - y1) * (z2 - z1);

        for (int x = x1; x < x2; x++) {
            volume[x] += area;
        }

        total += area * (x2 - x1);
    }

    long long sum = 0;
    int j = 0;

    cout << fixed << setprecision(12);

    for (int i = 1; i < m; i++) {
        double target = (double)total * i / m;

        while (j < a && sum + volume[j] < target) {
            sum += volume[j];
            j++;
        }

        double pos = j;

        if (j < a && volume[j] > 0) {
            pos += (target - sum) / volume[j];
        }

        cout << pos << '\n';
    }

    return 0;
}
