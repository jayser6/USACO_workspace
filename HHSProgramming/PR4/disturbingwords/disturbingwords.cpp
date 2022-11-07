#include <iostream>
#include<string>
using namespace std;

void solve() {
    string word; cin >> word;

    int lowerCount = 0, upperCount = 0;
    for (int i = 0;i < word.length();i++) {
        if (islower(word.at(i))) {
            lowerCount++;
        }
        else {
            upperCount++;
        }
    }

    for (int i = 0;i < word.length();i++) {
        if (lowerCount >= upperCount) {
            cout << static_cast<char>(tolower(word.at(i)));
        }
        else {
            cout << static_cast<char>(toupper(word.at(i)));
        }
    }

    cout << endl;
}

int main () {
    int t; cin >> t;
    for (int i = 0;i < t;i++) {
        solve();
    }
}