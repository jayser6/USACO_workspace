/*____________________________________________________________
// started : 10/15/22
// finished: 10/16/22
// problem : http://www.usaco.org/index.php?page=viewproblem2&cpid=99
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

    freopen("umbrella.in", "r", stdin);
    freopen("umbrella.out", "w", stdout);

    int n, m; cin >> n >> m;

    vector<int> cows(n);
    vector<int> umb(m + 1); // umb[0] is irrelevant   
    FOR(n)
        cin >> cows[i];

    FORO(m + 1)
        cin >> umb[i];

    // umb[1] would represent the minimum cost to cover at least a width of 1
    ROF(m)
        umb[i] = min(umb[i], umb[i + 1]);

    vector<int> dp(n + 1, PRIME32);
    dp[0] = 0;

    sort(ALL(cows));

    FORO(n + 1) {
        for (int j = 0;j < i;j++)
            dp[i] = min(dp[i], dp[j] + umb[cows[i - 1] - cows[j] + 1]);
    }

    cout << dp[n];

    return 0;
}
