#include <iostream>
using namespace std;

class Demo {
private:
    int value;
    static int count;

public:
    Demo(int value) {
        this->value = value;
        count++;
    }

    void display() const {
        cout << "Value: " << value << endl;
    }

    static void showCount() {
        cout << "Objects created: " << count << endl;
    }

    friend void compare(const Demo& a, const Demo& b);
};

int Demo::count = 0;

void compare(const Demo& a, const Demo& b) {
    if (a.value > b.value)
        cout << "First object has greater value" << endl;
    else if (a.value < b.value)
        cout << "Second object has greater value" << endl;
    else
        cout << "Both values are equal" << endl;
}

int main() {
    Demo d1(10);
    Demo d2(20);

    d1.display();
    d2.display();

    Demo::showCount();
    compare(d1, d2);

    return 0;
}