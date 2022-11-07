/*____________________________________________________________
// started : 07/11/22
// finished: 07/11/22
// problem : http://www.usaco.org/index.php?page=viewproblem2&cpid=993
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

const int MAX_T = 1000; // 1000t < t^2, t = 1000
const int MIN = -2e9;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("time.in", "r", stdin);
    freopen("time.out", "w", stdout);

    int n, m, c; cin >> n >> m >> c;

    vector<int> cities(n);
    FOR(n) {
        cin >> cities[i];
    }

    vector<vector<int>> edges(n);
    FOR(m) {
        int a, b; cin >> a >> b;
        a--; b--;

        edges[a].pb(b);
    }

    vector<vector<pair<int, int>>> dp(MAX_T + 1, vector<pair<int, int>>(n, { MIN, 0 })); // [time][city], f -> money, s -> time
    dp[0][0] = { 0, 0 };
    int ans = MIN;
    for (int i = 0;i <= MAX_T;i++) {
        for (int j = 0;j < n;j++) {
            if (dp[i][j].f == MIN) {
                continue;
            }
            if (j == 0) {
                ans = max(ans, dp[i][j].f);
            }
            for (int dest : edges[j]) {
                // money lost due to travel
                int newCost = dp[i][j].f - c * ((2 * dp[i][j].s) + 1);

                // money gained from traveling
                newCost += cities[dest];

                if (i < MAX_T) {
                    if (dp[i + 1][dest].f < newCost) {
                        dp[i + 1][dest] = { newCost, dp[i][j].s + 1 };
                    }

                }
            }
        }
    }

    cout << ans;
}
