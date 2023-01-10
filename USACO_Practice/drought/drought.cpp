/*____________________________________________________________
// started : 01/09/23
// finished: 01/09/23
// problem : http://usaco.org/index.php?page=viewproblem2&cpid=1185
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
#define SMALL (int)INT_MIN
#define SMALLER (ll)LLONG_MIN
#define PRIME64 (ll)999998727899999 // this number has 15 digits
#define PRIME32 (int)(1e9 + 7) 
#define ASCII_PRIME (int)257
#define ALPHA_PRIME (int)29

const int MAX_N = 100, MAX_H = 1000, MOD = PRIME32;
ll dp[MAX_N][MAX_H + 1]; // TODO: 2 row optimization
ll psum[MAX_H + 1];
int hunger[MAX_N];
int bound[MAX_N]; // maximum number of picks for each cow[i], exclusive

int do_dp(int n, int end) {
    // ll dp[MAX_N][MAX_H + 1]; // TODO: 2 row optimization
    // ll psum[MAX_H + 1];

    // FOR(i, MAX_N) FOR(j, MAX_H + 1) dp[i][j] = -1;
    // fill(psum, psum + MAX_H + 1, -1);

    fill(dp[n - 2], dp[n - 2] + bound[n - 2] - end, 1);
    psum[0] = 1;
    FORO(i, bound[n - 2] - end) psum[i] = psum[i - 1] + dp[n - 2][i];

    ROF(i, n - 2) {
        FOR(j, bound[i] - end) {
            int prev = min(bound[i + 1] - 1 - end, hunger[i + 1] - end - j);
            dp[i][j] = psum[prev];
        }

        psum[0] = dp[i][0];
        FORO(j, bound[i] - end) psum[j] = (psum[j - 1] + dp[i][j]) % MOD;
    }

    int ret = psum[bound[0] - end - 1];
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    FOR(i, n) cin >> hunger[i];

    int min_bound = BIG;
    FOR(i, n - 1) {
        bound[i] = min(hunger[i], hunger[i + 1]) + 1;
        min_bound = min(min_bound, bound[i]);
    }

    if (n == 1) cout << hunger[0] + 1 << endl;
    else if (n == 2) cout << min(hunger[0], hunger[1]) + 1 << endl;
    else if (n % 2 == 1) {
        ll ans = 0;
        FOR(i, min_bound) ans = (ans + do_dp(n, i)) % MOD;
        cout << ans << endl;
    }
    else cout << do_dp(n, 0) << endl;

    return 0;
}
