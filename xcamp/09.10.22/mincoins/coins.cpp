/*____________________________________________________________
// started : 09/13/22
// finished: 09/13/22
// problem : https://cses.fi/problemset/task/1634
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

const int MAX_N = 100;
const int MAX_X = 1e6;

int coins[MAX_N];
int dp[MAX_X + 1];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, x; cin >> n >> x;

    FOR(x + 1) {
        dp[i] = PRIME32;
    }

    FOR(n) {
        cin >> coins[i];

        dp[coins[i]] = 1;
    }


    FOR(x + 1) {
        if (dp[i] > 0) {
            for (int j = 0;j < n;j++) {
                int new_sum = coins[j] + i;

                if (new_sum <= x)
                    dp[new_sum] = min(dp[new_sum], dp[i] + 1);
            }
        }
    }

    if (dp[x] == PRIME32)
        cout << -1;
    else
        cout << dp[x];

    return 0;
}
