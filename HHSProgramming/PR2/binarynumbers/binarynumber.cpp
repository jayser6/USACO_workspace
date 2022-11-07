#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <fstream>
#define pb push_back
using namespace std;

void solve() {
    string s; cin >> s;
    
    int output = 0, carry = 0, zeroCount = 0;
    for (int i = s.length() - 1;i >= 0;i--) {
        if (s.at(i) == '0') {
            zeroCount++;
        }
        if (s.at(i) == '0' && carry == 0) {
            carry = 0;
            output++;
        }
        else if (((s.at(i) == '0') && (carry == 1)) || ((s.at(i) == '1') && (carry == 0))) {
            output += 2;
            carry = 1;
        }
        else {
            output++;
            carry = 1;
        }
    }

    if (zeroCount == s.length() - 1) {
        cout << zeroCount << endl;
    }
    else {
        cout << output << endl;
    }
} 

int main() {
    int t; cin >> t;
    for (int i = 0;i < t;i++) {
        solve();
    } 
} 