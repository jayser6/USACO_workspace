#include <bits/stdc++.h>

using namespace std;

int main() {
    string a, b; cin >> a >> b;

    if (a == "0" || b == "0") {
        cout << "0";
        return 0;
    }

    const int MAX_LENGTH = a.length() + b.length();

    // reverse the order so the digits match up with the index
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    vector<int> product(MAX_LENGTH, 0);

    for (int i = 0;i < b.length();i++) {
        int dig1 = b.at(i) - 48, dig2;
        int carry = 0, tempProd;
        for (int j = 0;j < a.length();j++) {
            dig2 = a.at(j) - 48;
            tempProd = dig2 * dig1 + carry + product.at(i + j); 
            product.at(i + j) = tempProd % 10;
            carry = tempProd / 10;
        }
        product.at(i + a.length()) = carry;
    }

    for (int i = MAX_LENGTH - 1;i >= 0;i--) {
        if (product.at(i) == 0 && i == MAX_LENGTH - 1) {
            continue;
        }
        cout << product.at(i);
    }
    
}