// started : 03/25/22
// finished: 04/06/22
// problem : https://codeforces.com/problemset/problem/1622/C

#include <bits/stdc++.h>

#define ALL(arr) arr.begin(), arr.end()
#define ll long long
#define ld long double
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

    vector<ll> psum(n + 1);
    vector<ll> a(n + 1);
    psum[0] = 0;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }

    sort(ALL(a));

    for (int i = 1;i <= n;i++) {
        psum[i] = psum[i - 1] + a[i];
    }

    if (psum[n] <= k) {
        cout << "0" << endl;
        return;
    }

    ll ans = BIG_NUMBER;
    for (int i = 0;i < n;i++) {
        ll minVal, numer = k - psum[n - i] + psum[1];
        int denom = i + 1;

        if (numer < 0 && numer % denom != 0) {
            minVal = numer / denom - 1;
        }
        else {
            minVal = numer / denom;
        }

        ll subNum = max(0LL, a[1] - minVal);
        ans = min(ans, subNum + i);
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;

    for (int i = 0;i < t;i++) {
        solve();
    }
}
