#include <iostream>
using namespace std;

void solve() {                        
    int isGreater[3][3] = {{-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}};

    for (int i = 0;i < 3;i++) {
        string input; cin >> input;
        char coin1 = input.at(0), coin2 = input.at(2);
        if (input.at(1) == '>') {
            isGreater[coin1 - 65][coin2 - 65] = 1;
            isGreater[coin2 - 65][coin1 - 65] = 0;
        } 
        else {
            isGreater[coin1 - 65][coin2 - 65] = 0;
            isGreater[coin2 - 65][coin1 - 65] = 1;
        }     
    }
    string output = "Impossible";
    if (isGreater[0][1] && isGreater[0][2]) {
        if (isGreater[1][2]) {
            output = "CBA";
        }
        else {
            output = "BCA";
        }
    }
    else if (isGreater[1][0] && isGreater[1][2]) {
        if (isGreater[0][2]) {
            output = "CAB";
        }
        else {
            output = "ACB";
        }
    }
    else if (isGreater[2][0] && isGreater[2][1]) {
        if (isGreater[0][1]) {
            output = "BAC";
        }
        else {
            output = "ABC";
        }
    }
    cout << output << endl;
}

int main() {
    int t; cin >> t;
    for (int i = 0;i < t;i++) {
        solve();
    }
}