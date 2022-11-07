/*____________________________________________________________
// started : 09/27/22
// finished: 09/27/22
// problem : https://cses.fi/problemset/task/1097
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

    int n; cin >> n;

    ll sum = 0;
    vector<int> cards(n);
    FOR(n) {
        cin >> cards[i];
        sum += cards[i];
    }

    // edge cases
    if (n == 1) {
        cout << cards[0];
        return 0;
    }
    else if (n == 2) {
        cout << max(cards[0], cards[1]);
        return 0;
    }

    // dp[i][j], i represents b - a + 1, where [a, b] is a closed interval. dp
    // stores the difference beteween the two players' scores, assuming optimal
    // moves

    // base case
    vector<vector<ll>> dp(n + 1);
    FOR(n - 1) {
        dp[2].pb(abs(cards[i] - cards[i + 1]));
    }

    // calculate dp
    for (int l = 3;l <= n;l++) {
        for (int i = 0;i < dp[l - 1].size() - 1;i++) {
            // calculate the new max dp value
            ll new_val1 = cards[i + l - 1] - dp[l - 1][i];
            ll new_val2 = cards[i] - dp[l - 1][i + 1];

            dp[l].pb(max(new_val1, new_val2));
        }
    }

    // calculate answer
    cout << (sum + dp[n][0]) / 2;

    return 0;
}
