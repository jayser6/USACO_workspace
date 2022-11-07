// started : 12/4/21
// finished: 12/5/21

#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second

using namespace std;

int main() {
    int n; cin >> n;

    vector<vector<int>> pasture(n, vector<int>(n));
    for (int i = 0;i < n;i++) {
        for (int j = 0; j < n;j++) {
            cin >> pasture.at(i).at(j);
        }
    } 

    int horizontalVal = 0, verticalVal = 0;
    for (int i = 0;i < n;i++) {
        int evenValV = 0, oddValV = 0, evenValH = 0, oddValH = 0;
        for (int j = 0;j < n;j++) {
            if (j % 2 == 0) {
                evenValV += pasture.at(j).at(i);
                evenValH += pasture.at(i).at(j);
            }
            else {
                oddValV += pasture.at(j).at(i);
                oddValH += pasture.at(i).at(j);
            }
        }
        if (oddValH > evenValH) {
            horizontalVal += oddValH;
        }
        else {
            horizontalVal += evenValH;
        }

        if (oddValV > evenValV) {
            verticalVal += oddValV;
        }
        else {
            verticalVal += evenValV;
        }
    }

    cout << max(verticalVal, horizontalVal);
}