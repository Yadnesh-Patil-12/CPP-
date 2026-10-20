#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;

    if (n < 0) {
        cout << "Square root of a negative number "
             << "is not a real number." << endl;
        return 0;
    }

    long long left = 0, right = n;
    long long answer = 0;

    while (left <= right) {
        long long mid = left + (right - left) / 2;

        if (mid == 0 || mid <= n / mid) {
            answer = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << "Floor square root: " << answer << endl;
    return 0;
}