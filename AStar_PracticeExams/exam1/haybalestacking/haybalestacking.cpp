#include <iostream>
#include <vector>
#include <cmath>
#define pb push_back

using namespace std;

bool canStack(vector<int> haybales, int m, long long heightLimit) {
    int stackCount = 1;
    long long currentHeight = 0;
    for (int i = 0;i < haybales.size();i++) {
        if (((i == 0) || (haybales.at(i - 1) >= haybales.at(i))) && (currentHeight + haybales.at(i) <= heightLimit)) {
            currentHeight += haybales.at(i);
        }
        else { 
            stackCount++;
            currentHeight = haybales.at(i);
            if (stackCount > m) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int n, m; cin >> n >> m;
    vector<int> haybales(n);
    
    for (int i = 0;i < n;i++) {
        cin >> haybales.at(i);
    }

    long long output = -1, bsLow = 1, bsHigh = pow(10, 15), bsMid;
    while (bsLow <= bsHigh) {
        bsMid = (bsLow + bsHigh) / 2;
        if (canStack(haybales, m, bsMid)) {
            output = bsMid;
            bsHigh = bsMid - 1;
        }
        else {
            bsLow = bsMid + 1;
        }
    }
    if (output == -1) {
        cout << "IMPOSSIBLE";
        return 0;
    }
    cout << output;
}