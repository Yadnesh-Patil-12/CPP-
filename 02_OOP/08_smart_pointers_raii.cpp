#include <iostream>
#include <memory>
using namespace std;

class Resource {
public:
    Resource() {
        cout << "Resource acquired" << endl;
    }

    ~Resource() {
        cout << "Resource released" << endl;
    }

    void display() const {
        cout << "Resource is being used" << endl;
    }
};

int main() {
    {
        unique_ptr<Resource> ptr = make_unique<Resource>();

        ptr->display();

        cout << "Leaving scope..." << endl;
    }

    cout << "Program finished" << endl;

    return 0;
}