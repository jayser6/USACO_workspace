/*____________________________________________________________
// started : 11/27/22
// finished: 11/27/22
// problem : http://www.usaco.org/index.php?page=viewproblem2&cpid=791
____________________________________________________________*/

#include <bits/stdc++.h>

#define FOR(n) for (int i = 0;i < n;i++)
#define FORO(n) for (int i = 1;i < n;i++)
#define ROF(n) for (int i = n - 1;i >= 0;i--)
#define ROFO(n) for (int i = n - 1;i >= 1;i--)
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
#define BIG_NUMBER 1e18
#define BIG_PRIME 999998727899999 // this number has 15 digits
#define PRIME32 (int)(1e9 + 7) 
#define ASCII_PRIME 257
#define ALPHA_PRIME 29

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("spainting.in", "r", stdin);
    freopen("spainting.out", "w", stdout);

    int n, m, k; cin >> n >> m >> k;

    // calculate m^n
    ll M_POW_N = 1;
    FOR(n) {
        M_POW_N *= m;
        M_POW_N %= PRIME32;
    }

    // calculate the number of ways to fill n with any value from 1 to m without
    // having k equal adjacent values 
    vector<ll> dp(n + 1); // 1-indexing the dp array
    ll running_sum = 0;
    dp[0] = 1;
    FORO(n + 1) {
        if (i < k) {
            dp[i] = dp[i - 1] * m;
            dp[i] %= PRIME32;
            running_sum += dp[i];
            running_sum %= PRIME32;
            continue;
        }

        dp[i] = running_sum * (m - 1);
        dp[i] %= PRIME32;
        running_sum += dp[i] - dp[i - k + 1];
        running_sum %= PRIME32;
    }

    int ans = M_POW_N - dp[n];
    if (ans < 0)
        ans += PRIME32;

    cout << ans % PRIME32;

    return 0;
}
