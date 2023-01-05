/*____________________________________________________________
// started : 01/05/23
// finished: 01/05/23
// problem : https://codeforces.com/problemset/problem/1719/C
____________________________________________________________*/

#include <bits/stdc++.h>
using namespace std;

// #pragma GCC optimize ("Ofast")
// #pragma GCC target ("avx2")

#define debug(x) #x << ": " << x << " "
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
#define tup tuple
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
#define BIG (int)INT_MAX 
#define BIGGER (ll)LLONG_MAX
#define PRIME64 (ll)999998727899999 // this number has 15 digits
#define PRIME32 (int)(1e9 + 7) 
#define ASCII_PRIME (int)257
#define ALPHA_PRIME (int)29

const int MAX_N = 1e5;
int a[MAX_N];
pair<int, int> r[MAX_N]; // { first win, last win }, both inclusive

void solve() {
    int n, q; cin >> n >> q;

    FOR(i, n) {
        cin >> a[i];
        r[i] = { -1, -1 };
    }

    int front = 0;
    r[front] = { 1, -1 };

    FORO(i, n) {
        if (a[i] > a[front]) {
            front = i;
            r[front] = { i, i };
        }
        else r[front].s = i;
    }

    FOR(q_i, q) {
        int i, k; cin >> i >> k;
        i--;

        if (r[i].s == -1 || r[i].f > k) cout << 0 << endl;
        else if (a[i] == n) cout << k - r[i].f + 1 << endl;
        else cout << min(r[i].s, k) - r[i].f + 1 << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}
