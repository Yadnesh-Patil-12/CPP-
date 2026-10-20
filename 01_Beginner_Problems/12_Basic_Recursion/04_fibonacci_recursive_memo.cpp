#include <iostream>
#include <vector>
using namespace std;

long long fibonacci(int n, vector<long long>& dp) {
    if (n <= 1) return n;

    if (dp[n] != -1)
        return dp[n];

    return dp[n] = fibonacci(n - 1, dp)
                 + fibonacci(n - 2, dp);
}

int main() {
    int n;
    cout << "Enter n (0 to 92): ";
    cin >> n;

    if (n < 0 || n > 92) {
        cout << "Invalid input." << endl;
        return 0;
    }

    vector<long long> dp(n + 1, -1);

    cout << "Fibonacci number = "
         << fibonacci(n, dp) << endl;

    return 0;
}