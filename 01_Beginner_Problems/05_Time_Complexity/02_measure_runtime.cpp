#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

int main() {
    int n;

    cout << "Enter n: ";
    cin >> n;

    auto start = high_resolution_clock::now();

    long long sum = 0;

    for (int i = 1; i <= n; i++) {
        sum += i;
    }

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Sum = " << sum << endl;
    cout << "Execution time: "
         << duration.count() << " microseconds" << endl;

    return 0;
}