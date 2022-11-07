// started : 02/21/22
// finished: 02/21/22
// problem : https://codeforces.com/contest/1339/problem/B

#include <bits/stdc++.h>

#define ALL(arr) arr.begin(), arr.end()
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl "\n"

using namespace std;

void solve() {
    int n; cin >> n;
    
    vector<ll> a(n);
    for (int i = 0;i < n;i++) {
        cin >> a[i];
    }

    sort(ALL(a));
    if (n % 2 == 0) {
        for (int i = 1;i <= n / 2;i++) {
            cout << a[n / 2 + i - 1] << " " << a[n / 2 - i] << " ";
        }
    }
    else {
        cout << a[n / 2] << " ";
        for (int i = 1;i <= n / 2;i++) {
            cout << a[n / 2 + i] << " " << a[n / 2 - i] << " ";
        }
    }

    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    for (int i = 0;i < t;i++) {
        solve();
    }
}