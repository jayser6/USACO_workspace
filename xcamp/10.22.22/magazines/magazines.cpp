/*____________________________________________________________
// started : 12/26/22
// finished: 12/26/22
// problem : https://codeforces.com/problemset/problem/1743/C
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
    int n; cin >> n;

    string lid; cin >> lid;
    lid += "0";

    vector<int> val(n);
    FOR(i, n)
        cin >> val[i];

    vector<vector<ll>> dp(2, vector<ll>(n + 1, -1));
    dp[lid[0] - '0'][0] = 0;

    FOR(i, n) {
        if (dp[0][i] != -1) {
            if (lid[i + 1] == '1') {
                dp[0][i + 1] = max(dp[0][i + 1], dp[0][i] + val[i]);
                dp[1][i + 1] = max(dp[1][i + 1], dp[0][i]);
            }
            dp[lid[i + 1] - '0'][i + 1] = max(dp[lid[i + 1] - '0'][i + 1], dp[0][i]);
        }
        if (dp[1][i] != -1) {
            dp[lid[i + 1] - '0'][i + 1] = max(dp[lid[i + 1] - '0'][i + 1], dp[1][i] + val[i]);
        }
    }

    cout << dp[0][n] << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;

    while (t--)
        solve();

    return 0;
}
