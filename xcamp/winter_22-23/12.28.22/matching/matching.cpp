/*____________________________________________________________
// started : 12/28/22
// finished: 12/29/22
// problem : https://codeforces.com/problemset/problem/1630/A
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
#define BIG_INT64 (ll)1e18
#define PRIME64 (ll)999998727899999 // this number has 15 digits
#define PRIME32 (int)(1e9 + 7) 
#define ASCII_PRIME (int)257
#define ALPHA_PRIME (int)29

using namespace std;

void solve() {
    int n, k; cin >> n >> k;

    if (k == 0) {
        FOR(i, n / 2) {
            cout << i << " " << n - 1 - i << endl;
        }
    }
    else if (k == n - 1) {
        if (n == 4) {
            cout << "-1" << endl;
        }
        else {
            cout << n - 1 << " " << n - 2 << endl;
            cout << n - 4 << " 0" << endl;
            cout << "1 3" << endl;

            for (int i = 2;i < n / 2;i++) {
                if (i != 3) {
                    cout << i << " " << n - i - 1 << endl;
                }
            }
        }
    }
    else {
        cout << "0 " << n - 1 - k << endl;
        cout << k << " " << n - 1 << endl;;

        for (int i = 1;i < n / 2;i++) {
            if (i != k && i != n - 1 - k) {
                cout << i << " " << n - i - 1 << endl;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while (t--)
        solve();

    return 0;
}
