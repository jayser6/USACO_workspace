/*____________________________________________________________
// started : 12/27/22
// finished: 12/27/22
// problem : https://codeforces.com/group/eZhSssSlea/contest/418818/problem/D
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

// 0, 1, 1, 2, 3, 5, ...
const int num_fib = 88;
vector<ll> fib(num_fib);

void solve() {
    ll n; cin >> n;

    int start = upper(ALL(fib), n) - fib.begin();
    vector<pair<int, ll>> dp(num_fib, { PRIME32, 0 });
    dp[start] = { 0, n };
    dp[start - 1] = { 0, n };

    for (int i = start;i > 0;i--) {
        if (dp[i].f == PRIME32)
            continue;

        ll dif = abs(fib[i] - dp[i].s);
        int next = upper(ALL(fib), dif) - fib.begin();

        if (dp[i].f + 1 < dp[next].f) {
            dp[next] = { dp[i].f + 1, dif };
        }
        if (dp[i].f + 1 < dp[next - 1].f) {
            dp[next - 1] = { dp[i].f + 1, dif };
        }
    }

    cout << dp[0].f << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    fib[0] = 0;
    fib[1] = 1;
    fib[2] = 1;
    for (int i = 3;i < num_fib;i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    int t; cin >> t;
    while (t--)
        solve();

    return 0;
}
