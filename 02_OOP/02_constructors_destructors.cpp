#include <iostream>
using namespace std;

class Student {
private:
    int id;

public:
    Student() {
        id = 0;
        cout << "Default constructor called" << endl;
    }

    Student(int studentId) {
        id = studentId;
        cout << "Parameterized constructor called" << endl;
    }

    void display() const {
        cout << "Student ID: " << id << endl;
    }

    ~Student() {
        cout << "Destructor called for ID: " << id << endl;
    }
};

int main() {
    Student s1;
    Student s2(101);

    s1.display();
    s2.display();

    return 0;
}