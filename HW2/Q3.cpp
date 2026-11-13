
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

long long calculateVolume(int pice_of_shokolat, vector<long long>& box) {
    long long hajm = 0;

    for (int i = 0; i < pice_of_shokolat; i++) {
        int x1, y1, z1, x2, y2, z2;
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;

        long long area = 1LL * (y2 - y1) * (z2 - z1);

        for (int x = x1; x < x2; x++) {
            box[x] += area;
        }

        hajm += area * (x2 - x1);
    }

    return hajm;
}

void findCuts(const vector<long long>& box, long long hajm,
              int tol, int num_of_person) {

    long long sum = 0;
    int j = 0;

    cout << fixed << setprecision(12);

    for (int i = 1; i < num_of_person; i++) {
        double target = (double)hajm * i / num_of_person;

        while (j < tol && sum + box[j] < target) {
            sum += box[j];
            j++;
        }

        double pos = j;

        if (j < tol && box[j] > 0) {
            pos += (target - sum) / box[j];
        }

        cout << pos << '\n';
    }
}

int main() {
    int pice_of_shokolat, num_of_person;
    cin >> pice_of_shokolat >> num_of_person;

    int tol, arz, ertefa;
    cin >> tol >> arz >> ertefa;

    vector<long long> box(tol, 0);

    long long hajm = calculateVolume(pice_of_shokolat, box);

    findCuts(box, hajm, tol, num_of_person);

    return 0;
}
