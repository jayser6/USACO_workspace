/*____________________________________________________________
// started : 10/07/22
// finished: 10/08/22
// problem : https://cses.fi/problemset/task/2181
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
#define BIG_NUMBER (ll)1e18
#define BIG_PRIME (ll)999998727899999 // this number has 15 digits
#define PRIME32 (int)(1e9 + 7) 
#define ASCII_PRIME (int)257
#define ALPHA_PRIME (int)29

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;

    const int POW = pow(2, n);

    // dimensions m, n, tile state; bit 1 -> the position is filled
    vector<vector<vector<ll>>> dp(m + 1, vector<vector<ll>>(n, vector<ll>(POW, 0)));
    dp[0][0][0] = 1;

    for (int i = 0;i < m + 1;i++) {
        for (int j = 0;j < n;j++) {
            // fill(ALL(dp[i][j]), 0);
            for (int k = 0;k < POW;k++) {
                // skip this state if it can't be reachec
                if (dp[i][j][k] == 0)
                    continue;

                int next_i = i + ((j + 1) / n);
                int next_j = (j + 1) % n;

                if (next_i > m)
                    break;

                // check if the current position is filled in the given 
                // tile state
                if (k >> (n - 1) == 1) {
                    // (i, j) is already filled, so move to next state without
                    // placing any tiles on this state
                    dp[next_i][next_j][(k << 1) % POW] += dp[i][j][k];
                    dp[next_i][next_j][(k << 1) % POW] %= PRIME32;
                }
                else {
                    /* (i, j) is not filled, so try placing tiles */

                    // 1x2 block(doesn't interfere with i + 1)
                    dp[next_i][next_j][(k << 1) % POW + 1] += dp[i][j][k];
                    dp[next_i][next_j][(k << 1) % POW + 1] %= PRIME32;

                    // see if 2x1 block(does interfere with i + 1) can be placed
                    if (((POW / 4) & k) != (POW / 4) && next_j > 0) {
                        // this block can be placed
                        dp[next_i][next_j][(k << 1) % POW + (POW / 2)] += dp[i][j][k];
                        dp[next_i][next_j][(k << 1) % POW + (POW / 2)] %= PRIME32;
                    }
                }

                int debug = 0;
            }
        }
    }

    cout << dp[m][0][0];

    return 0;
}

