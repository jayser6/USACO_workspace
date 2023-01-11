/*____________________________________________________________
// started : 01/10/23
// finished: 01/10/23
// problem : http://www.usaco.org/index.php?page=viewproblem2&cpid=622
____________________________________________________________*/

#include <bits/stdc++.h>
using namespace std;

// #pragma GCC optimize ("Ofast")
// #pragma GCC target ("avx2")

#define debug(x) #x << ": " << x << " "
#define FOR(i, n) for (int i = 0;i < n;i++)
#define FORO(i, n) for (int i = 1;i < n;i++)
#define ROF(i, n) for (int i = n - 1;i >= 0;i--)
#define ROFO(i, n) for (int i = n - 1;i >= 1;i--)
#define loop while (true) // rust woooo
#define eqmin(a, b) a = min(a, b)
#define eqmax(a, b) a = max(a, b)
#define ALL(arr) arr.begin(), arr.end()
#define lower lower_bound 
#define upper upper_bound
#define ll long long
#define uint unsigned int
#define tup tuple
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
#define BIG (int)INT_MAX 
#define BIGGER (ll)LLONG_MAX
#define SMALL (int)INT_MIN
#define SMALLER (ll)LLONG_MIN
#define PRIME64 (ll)999998727899999 // this number has 15 digits
#define PRIME32 (int)(1e9 + 7) 
#define ASCII_PRIME (int)257
#define ALPHA_PRIME (int)29

const int MAX_N = 100, MAX_K = 7;
ll dp[MAX_N][MAX_N][MAX_N][MAX_K]; // fixed first open barn, curr barn, previous open barn, # of open barns
int room[MAX_N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("cbarn2.in", "r", stdin);
    freopen("cbarn2.out", "w", stdout);

    int n, k; cin >> n >> k;
    FOR(i, n) cin >> room[i];

    FOR(i, n) FOR(j, n) FOR(l, n) FOR(w, k + 1) dp[i][j][l][w] = BIGGER;

    ll ans = BIGGER;

    // first, fix the first open barn
    FOR(i, n) {
        dp[i][i][i][1] = 0;
        for (int j = i;j % n != (i - 1 + n) % n;j++) {
            int jc = j % n, jn = (j + 1) % n;
            FOR(l, n) FORO(w, k + 1) {
                if (dp[i][jc][l][w] == BIGGER) continue;

                eqmin(dp[i][jn][l][w], dp[i][jc][l][w] + room[jn] * (j + 1 - l));
                if (w < k) eqmin(dp[i][jn][jn][w + 1], dp[i][jc][l][w]);
            }
        }

        FOR(j, n) eqmin(ans, dp[i][(i - 1 + n) % n][j][k]);
    }

    cout << ans;

    return 0;
}
