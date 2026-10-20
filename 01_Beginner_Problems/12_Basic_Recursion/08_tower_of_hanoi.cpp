#include <iostream>
using namespace std;

void towerOfHanoi(int n, char source,
                  char auxiliary, char destination) {
    if (n == 0) return;

    towerOfHanoi(n - 1, source, destination, auxiliary);

    cout << "Move disk " << n << " from "
         << source << " to " << destination << endl;

    towerOfHanoi(n - 1, auxiliary, source, destination);
}

int main() {
    int n;

    cout << "Enter number of disks (1 to 20): ";
    cin >> n;

    if (n < 1 || n > 20) {
        cout << "Invalid input." << endl;
        return 0;
    }

    towerOfHanoi(n, 'A', 'B', 'C');

    return 0;
}