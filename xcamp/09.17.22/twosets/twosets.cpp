/*____________________________________________________________
// started : 11/27/22
// finished: 11/27/22
// problem : https://cses.fi/problemset/task/1093
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

    int n; cin >> n;

    int sum = (n + 1) * n / 2;

    // edge case, where the sum is odd
    if (sum % 2 == 1) {
        cout << 0;
        return 0;
    }

    // use dp to find the number of ways reach sum / 2
    int target = sum / 2;
    vector<vector<ll>> dp(n + 1, vector<ll>(target + 1, 0));

    dp[1][0] = 1;
    for (int i = 1;i < n;i++) {
        for (int j = 0;j < target + 1;j++) {
            if (dp[i][j] == 0)
                continue;

            dp[i + 1][j] += dp[i][j]; // don't add i to the set
            dp[i + 1][j] %= PRIME32;

            // try to add i to the set
            if (i + j <= target) {
                dp[i + 1][i + j] += dp[i][j];
                dp[i + 1][i + j] %= PRIME32;
            }
        }
    }

    cout << dp[n][target];

    return 0;
}
