/*____________________________________________________________
// started : 09/13/22
// finished: 09/13/22
// problem : https://cses.fi/problemset/task/1635
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
#define PRIME32 1e9 + 7 
#define ASCII_PRIME 257
#define ALPHA_PRIME 29

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, x; cin >> n >> x;

    vector<int> coins(n);
    vector<ll> dp(x + 1, 0);
    FOR(n) {
        cin >> coins[i];

        if (coins[i] <= x)
            dp[coins[i]] = 1;
    }

    FOR(x + 1) {
        if (dp[i] > 0) {
            for (int j = 0;j < n;j++) {
                ll new_sum = i + coins[j];

                if (new_sum <= x) {
                    dp[new_sum] += dp[i];
                    dp[new_sum] %= (int)PRIME32;
                }
            }
        }
    }

    cout << dp[x];

    return 0;
}
