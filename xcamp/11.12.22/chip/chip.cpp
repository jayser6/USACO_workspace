/*____________________________________________________________
// started : 12/04/22
// finished:
// problem : https://codeforces.com/problemset/problem/1716/D
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
#define BIG_NUMBER (ll)1e18
#define BIG_PRIME (ll)999998727899999 // this number has 15 digits
#define PRIME32 (int)(1e9 + 7) 
#define ASCII_PRIME (int)257
#define ALPHA_PRIME (int)29

using namespace std;

const ll MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k; cin >> n >> k;

    vector<ll> ans(n + 1, 0);

    /* dp ans solve */

    vector<vector<ll>> dp(2, vector<ll>(n + 1, 0));
    bool finished = false;
    int steps = 0;

    dp[0][0] = 1;

    while (!finished) {
        steps++;
        finished = true;

        FOR(j, n + 1) {
            int pull_index = j - (k + steps - 1);

            if (pull_index >= 0) {
                dp[steps % 2][j] = dp[!(steps % 2)][pull_index] + dp[steps % 2][pull_index];
                dp[steps % 2][j] %= MOD;
                ans[j] += dp[steps % 2][j];
                ans[j] %= MOD;

                if (dp[steps % 2][j] > 0) {
                    finished = false;
                }
            }
        }
    }

    FORO(i, n + 1) {
        cout << ans[i] << " ";
    }

    return 0;
}