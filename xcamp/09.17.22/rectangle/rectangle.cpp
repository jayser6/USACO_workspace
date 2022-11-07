/*____________________________________________________________
// started : 09/26/22
// finished: 09/26/22
// problem : https://cses.fi/problemset/task/1744
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

    int a, b; cin >> a >> b;

    // fill in initial values for dp matrix
    vector<vector<ll>> dp(a + 1, vector<ll>(b + 1, BIG_NUMBER));

    for (int i = 1;i < a + 1;i++) {
        for (int j = 1;j < b + 1;j++) {
            if ((i == j) || (i == 0) || (j == 0)) {
                dp[i][j] = 0;
                continue;
            }

            /* go through the different ways to cut the rectangle */

            // horizontal 
            for (int k = 1;k < i;k++)
                dp[i][j] = min(dp[i][j], (dp[k][j] + dp[i - k][j] + 1));


            // vertical 
            for (int k = 0;k < j;k++)
                dp[i][j] = min(dp[i][j], (dp[i][k] + dp[i][j - k] + 1));
        }
    }

    cout << dp[a][b];

    return 0;
}
