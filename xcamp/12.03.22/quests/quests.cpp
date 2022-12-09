/*____________________________________________________________
// started : 12/09/22
// finished: 12/09/22
// problem : https://codeforces.com/contest/1760/problem/F
____________________________________________________________*/

#include <bits/stdc++.h>

#define FOR(i, n) for (int i = 0;i < n;i++)
#define FORO(i, n) for (int i = 1;i < n;i++)
#define ROF(i, n) for (int i = n - 1;i >= 0;i--)
#define ROFO(i, n) for (int i = n - 1;i >= 1;i--)
#define loop while (true) // rust woooo
#define ALL(arr) arr.begin(), arr.end()
#define lower lower_bound 
#define upper upper_bound
#define ll long long
#define uint unsigned int
#define hashmap unordered_map
#define hashset unordered_set
#define p_queue priority_queue
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define mp make_pair    
#define f first
#define s second
#define endl "\n"
#define BIG_NUMBER 1e18LL
#define BIG_PRIME 999998727899999LL // this number has 15 digits
#define PRIME32 (int)(1e9 + 7) 
#define ASCII_PRIME (int)257
#define ALPHA_PRIME (int)29

using namespace std;

void solve() {
    int n, d;
    ll c; cin >> n >> c >> d;

    vector<int> a(n);
    FOR(i, n)
        cin >> a[i];

    sort(ALL(a), greater<int>());

    /* check for edgecases */

    if (accumulate(a.begin(), a.begin() + min(n, d), 0LL) >= c) {
        cout << "Infinity" << endl;
        return;
    }
    else if ((ll)a[0] * d < c) {
        cout << "Impossible" << endl;
        return;
    }

    /* binary search for the answer */

    int l = 0, r = d + 1, ans = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        ll sum = 0;

        for (int i = 0;i < d;i++) {
            if (i % (mid + 1) >= n)
                continue;

            sum += a[i % (mid + 1)];
        }

        if (sum >= c) {
            ans = mid;
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }

    cout << ans << endl;

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;

    while (t--)
        solve();

    return 0;
}
