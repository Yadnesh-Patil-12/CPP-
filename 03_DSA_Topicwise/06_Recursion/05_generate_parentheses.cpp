#include <iostream>
#include <string>
using namespace std;

void generate(int open, int close, string current, int n) {
    if ((int)current.size() == 2 * n) {
        cout << current << endl;
        return;
    }

    if (open < n)
        generate(open + 1, close, current + '(', n);

    if (close < open)
        generate(open, close + 1, current + ')', n);
}

int main() {
    int n;
    cin >> n;

    if (n < 0 || n > 12) {
        cout << "Enter n between 0 and 12." << endl;
        return 0;
    }

    generate(0, 0, "", n);

    return 0;
}