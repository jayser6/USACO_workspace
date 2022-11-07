// started : 01/09/22
// finished: 01/12/22

#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second

using namespace std;

int main() {
    int n; cin >> n;

    vector<vector<ll>> pSum1(n, vector<ll>(n)); // number of contiguous cells >= 100 from left to right  
    vector<vector<ll>> pSum2(n, vector<ll>(n)); // number of contiguous cells > 100 from left to right

    int val1 = 0, val2 = 0;
    for (int i = 0;i < n;i++) {
        val1 = 0;
        val2 = 0;
        for (int j = 0;j < n;j++) {
            int taste; cin >> taste;

            if (taste > 100) {
                val2++;
            }
            else {
                val2 = 0;
            }

            if (taste >= 100) {
                val1++;
            }
            else {
                val1 = 0;
            }
            pSum1[i][j] = val1;
            pSum2[i][j] = val2;
        }
    }

    ll totalVal1 = 0, totalVal2 = 0;
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            int k = i;
            ll minWidth = 501; 
            while (k < n && pSum1[k][j] != 0) {
                minWidth = min(minWidth, pSum1[k][j]);
                totalVal1 += minWidth; 
                k++;
            }

            k = i;
            minWidth = 501;
            while (k < n && pSum2[k][j] != 0) {
                minWidth = min(minWidth, pSum2[k][j]);
                totalVal2 += minWidth;
                k++;
            }
        }
    }

    cout << totalVal1 - totalVal2;
}