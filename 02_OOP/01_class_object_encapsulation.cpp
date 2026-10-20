#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int marks;

public:
    void setDetails(string studentName, int studentMarks) {
        name = studentName;

        if (studentMarks >= 0 && studentMarks <= 100)
            marks = studentMarks;
        else
            marks = 0;
    }

    void display() const {
        cout << "Name: " << name << endl;
        cout << "Marks: " << marks << endl;
    }
};

int main() {
    Student s;

    string name;
    int marks;

    cout << "Enter name: ";
    getline(cin, name);

    cout << "Enter marks: ";
    cin >> marks;

    s.setDetails(name, marks);
    s.display();

    return 0;
}