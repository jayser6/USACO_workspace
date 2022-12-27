/*____________________________________________________________
// started : 12/26/22
// finished: 12/26/22
// problem : https://cses.fi/problemset/result/5183583/
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

const int MAX_N = 3 * 1e6;
ll fact[MAX_N + 1], inv_mod[MAX_N + 1];

ll good_pow(ll x, ll y, int mod) {
    ll out = 1; x %= mod;

    while (y) {
        if (y & 1) {
            out *= x; out %= mod;
        }
        x *= x; x %= mod;
        y >>= 1;
    }
    return out;
}

void calc_fact(ll p) {
    fact[0] = 1;
    FORO(i, MAX_N + 1) {
        fact[i] = fact[i - 1] * i % p;
    }
}

void inverse(int mod) {
    inv_mod[MAX_N] = good_pow(fact[MAX_N], mod - 2, mod);
    ROFO(i, MAX_N + 1) {
        inv_mod[i - 1] = inv_mod[i] * i % mod;
    }
}

ll nCr(int n, int r, int mod) {
    if (n < r) return 0;
    return fact[n] * inv_mod[r] % mod * inv_mod[n - r] % mod;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    calc_fact(PRIME32);
    inverse(PRIME32);

    int n, m; cin >> n >> m;
    cout << nCr(n + m - 1, n - 1, PRIME32);

    return 0;
}
