#include <iostream>
#include <utility>
#include <tuple>
#include <string>
using namespace std;

int main() {
    pair<int, string> p = {1, "Yadnesh"};

    cout << "Pair first: " << p.first << endl;
    cout << "Pair second: " << p.second << endl;

    tuple<int, string, double> t = {101, "Amit", 85.5};

    cout << "\nTuple ID: " << get<0>(t) << endl;
    cout << "Tuple Name: " << get<1>(t) << endl;
    cout << "Tuple Marks: " << get<2>(t) << endl;

    return 0;
}