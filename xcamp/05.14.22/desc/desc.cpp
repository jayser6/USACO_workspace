/*____________________________________________________________*/
// started : 06/08/22
// finished: 06/08/22
// problem : https://cses.fi/problemset/task/1746
/*____________________________________________________________*/

#include <bits/stdc++.h>

#define FOR(n) for (int i = 0;i < n;i++)
#define FORO(n) for (int i = 1;i < n;i++)
#define ROF(n) for (int i = n - 1;i >= 0;i--)
#define ROFO(n) for (int i = n - 1;i >= 1;i--)
#define loop while (true)
#define ALL(arr) arr.begin(), arr.end()
#define ll long long
#define hashmap unordered_map
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl "\n"
#define BIG_NUMBER (ll)pow(10, 18)

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    const ll MOD = pow(10, 9) + 7;

    int n, m; cin >> n >> m;

    vector<vector<ll>> dp(2, vector<ll>(m + 1, 0)); // the dp table is 1-indexed so the vector indices match the value of x_i
    bool curr = 0;
    FOR(n) {
        fill(ALL(dp[curr]), 0);

        int x_i; cin >> x_i;

        if (i == 0) {
            if (x_i == 0) {
                for (int j = 1;j <= m;j++) {
                    dp[curr][j] = 1;
                }
            }
            else {
                dp[curr][x_i] = 1;
            }
        }
        else {
            if (x_i == 0) {
                for (int j = 1;j <= m;j++) {
                    for (int k = max(j - 1, 1);k <= min(j + 1, m);k++) {
                        dp[curr][j] += dp[!curr][k];
                        dp[curr][j] %= MOD;
                    }
                }
            }
            else {
                for (int j = max(x_i - 1, 1);j <= min(x_i + 1, m);j++) {
                    dp[curr][x_i] += dp[!curr][j];
                    dp[curr][x_i] %= MOD;
                }
            }
        }

        // see if there should be an output
        if (i == n - 1) {
            ll ans = 0;
            if (x_i == 0) {
                for (int j = 1;j <= m;j++) {
                    ans += dp[curr][j];
                    ans %= MOD;
                }
            }
            else {
                ans = dp[curr][x_i];
            }
            cout << ans;
        }

        curr = !curr;
    }

    return 0;
}
