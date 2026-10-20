#include <iostream>
using namespace std;

void counter() {
    static int count = 0;
    count++;

    cout << "Count = " << count << endl;
}

int main() {
    int local = 10;
    const double PI = 3.14159;

    cout << "Local variable = " << local << endl;
    cout << "PI = " << PI << endl;

    counter();
    counter();
    counter();

    return 0;
}