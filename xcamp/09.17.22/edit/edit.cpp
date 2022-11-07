/*____________________________________________________________
// started : 09/23/22
// finished: 09/23/22
// problem : https://cses.fi/problemset/task/1639
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

    string s1, s2; cin >> s1 >> s2;

    vector<vector<int>> dp(2, vector<int>(s2.size() + 1, PRIME32));

    for (int i = 0;i < s2.size() + 1;i++) {
        dp[0][i] = i;
    }

    for (int i = 1;i < s1.size() + 1;i++) {
        bool row = i % 2;
        dp[row][0] = i;
        for (int j = 1;j < s2.size() + 1;j++) {
            // add 
            int add_val = dp[row][j - 1] + 1;

            // replace 
            int rep_val = dp[!row][j - 1] + !(s1.at(i - 1) == s2.at(j - 1));

            // remove
            int rem_val = dp[!row][j] + 1;

            dp[row][j] = min(add_val, min(rep_val, rem_val));
        }
    }

    cout << dp[s1.size() % 2][s2.size()];

    return 0;
}
