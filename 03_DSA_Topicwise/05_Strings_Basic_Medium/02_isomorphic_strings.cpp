#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    if (s.size() != t.size()) {
        cout << "Not isomorphic" << endl;
        return 0;
    }

    vector<int> mapS(256, -1);
    vector<int> mapT(256, -1);

    for (int i = 0; i < (int)s.size(); i++) {
        unsigned char a = s[i];
        unsigned char b = t[i];

        if (mapS[a] != -1 && mapS[a] != b) {
            cout << "Not isomorphic" << endl;
            return 0;
        }

        if (mapT[b] != -1 && mapT[b] != a) {
            cout << "Not isomorphic" << endl;
            return 0;
        }

        mapS[a] = b;
        mapT[b] = a;
    }

    cout << "Isomorphic strings" << endl;
    return 0;
}