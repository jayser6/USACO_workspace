// started : 03/25/22
// finished: 
// problem : https://codeforces.com/group/IESCWMl0hb/contest/374336/problem/C

#include <bits/stdc++.h>

#define ALL(arr) arr.begin(), arr.end()
#define ll long long
#define hashmap unordered_map
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl "\n"
#define BIG_NUMBER (ll)pow(10, 18)

using namespace std;

void solve() {
    int n; ll k; cin >> n >> k;

    vector<ll> a(n);
    ll sum = 0;
    for (int i = 0 ;i < n;i++) {
        cin >> a[i];
        sum += a[i];
    }

    if (sum <= k) {
        cout << "0" << endl;
        return;
    }

    sort(ALL(a));

    ll output = BIG_NUMBER;
    ll bsLow = k - sum + a[0], bsHigh = k / n;
    while (bsLow <= bsHigh) {
        ll bsMid = (bsLow + bsHigh) / 2;
        ll currSum = sum - a[0] + bsMid;
        ll numSteps = abs(a[0] - bsMid); 
        
        for (int i = n - 1;i >= 0 && currSum > k;i--) {
            numSteps++;
            currSum = currSum + bsMid - a[i];
        }

        if (numSteps < output) {
            output = numSteps;
            bsLow = bsMid + 1;
        }
        else {
            bsHigh = bsMid - 1;
        }
    }

    cout << output << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    for (int i = 0;i < t;i++) {
        solve();
    }
}