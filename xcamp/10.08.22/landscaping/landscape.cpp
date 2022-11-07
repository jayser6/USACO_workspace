/*____________________________________________________________
// started : 10/13/22
// finished: 10/15/22
// problem : http://www.usaco.org/index.php?page=viewproblem2&cpid=126
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

    freopen("landscape.in", "r", stdin);
    freopen("landscape.out", "w", stdout);

    int n, x, y, z; cin >> n >> x >> y >> z;

    vector<int> from, to;

    // in the sampe input, the vector "from" would look like 0112223333 
    FOR(n) {
        int a, b; cin >> a >> b;

        for (int j = 0;j < a;j++)
            from.pb(i);
        for (int j = 0;j < b;j++)
            to.pb(i);
    }

    // dp for edit distance
    int len1 = from.size(), len2 = to.size();
    vector<vector<int>> dp(2, vector<int>(len2 + 1));

    FOR(len2 + 1)
        dp[0][i] = i * x;

    for (int i = 1;i < len1 + 1;i++) {
        dp[i % 2][0] = i * y;

        for (int j = 1;j < len2 + 1;j++) {
            int add = dp[i % 2][j - 1] + x;
            int remove = dp[(i - 1) % 2][j] + y;
            int replace = dp[(i - 1) % 2][j - 1] + (z * abs(from[i - 1] - to[j - 1]));

            dp[i % 2][j] = min(add, min(remove, replace));
        }
    }

    cout << dp[(len1) % 2][len2];

    return 0;
}
