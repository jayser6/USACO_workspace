/*____________________________________________________________
// started : 01/04/23
// finished:
// problem : https://codeforces.com/problemset/problem/1739/C
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

const int MAX_N = 60, MOD = 998244353;
ll a[MAX_N + 1], b[MAX_N + 1];

ll fact[MAX_N + 1], inv_mod[MAX_N + 1];

ll good_pow(ll x, ll y) {
    ll out = 1;
    x %= MOD;
    while (y) {
        if (y & 1) out = (out * x) % MOD;
        x = (x * x) % MOD;
        y >>= 1;
    }
    return out;
}

void calc_fact() {
    fact[0] = 1;
    FORO(i, MAX_N + 1) fact[i] = (fact[i - 1] * i) % MOD;
}

void inverse() {
    inv_mod[MAX_N] = good_pow(fact[MAX_N], MOD - 2);
    ROFO(i, MAX_N + 1) inv_mod[i - 1] = inv_mod[i] * i % MOD;
}

ll nCr(int n, int r) {
    if (n < r) return 0;
    ll ret = fact[n] * inv_mod[r] % MOD * inv_mod[n - r] % MOD;
    return ret;
}

void fill_dp() {
    const int d = 1; // there is always 1 configuration that reults in a draw

    a[2] = 1;
    b[2] = 0;

    a[4] = 3;
    b[4] = 2;

    for (int i = 6;i <= MAX_N;i += 2) {
        a[i] = a[i - 4] + nCr(i - 1, i / 2 - 1) + nCr(i - 4, i / 2 - 3);
        a[i] %= MOD;
        b[i] = nCr(i, i / 2) - a[i] - d;
        b[i] %= MOD;
        if (b[i] < 0) b[i] += MOD;
    }
}

void solve() {
    int n; cin >> n;
    cout << a[n] << " " << b[n] << " " << 1 << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    calc_fact();
    inverse();
    fill_dp();

    int t; cin >> t;
    while (t--) solve();

    return 0;
}
