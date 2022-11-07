/*____________________________________________________________
// started : 09/21/22
// finished: 09/21/22
// problem : http://www.usaco.org/index.php?page=viewproblem2&cpid=839
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

bool check(vector<pair<int, int>>& cows, int w, double ratio) {
    int n = cows.size();

    int weight_left = w;
    double val_sum = 0;
    vector<pair<int, double>> bad_cows; // adjusted value of suboptimal cows

    // if (ratio < 1)
    //     cout << "bp" << endl;

    // re-adjust the value of each cow
    FOR(n) {
        double adjusted = cows[i].s - cows[i].f * ratio;

        if (adjusted >= 0) {
            weight_left -= cows[i].f;
            val_sum += adjusted;
        }
        else
            bad_cows.pb({ cows[i].f, adjusted });
    }

    if (weight_left <= 0)
        return true;

    vector<vector<double>> dp(bad_cows.size(), vector<double>(weight_left + 1, -1));
    dp[0][0] = val_sum;
    dp[0][min(weight_left, bad_cows[0].f)] = val_sum + bad_cows[0].s;

    for (int i = 1;i < bad_cows.size();i++) {
        for (int j = 0;j < weight_left + 1;j++) {
            if (dp[i - 1][j] == -1)
                continue;

            // don't take this cow
            dp[i][j] = max(dp[i - 1][j], dp[i][j]);

            // take this cow
            int new_weight = min(j + bad_cows[i].f, weight_left);
            dp[i][new_weight] = max(dp[i - 1][new_weight], max(dp[i - 1][j] + bad_cows[i].s, dp[i][new_weight]));
        }
    }

    return dp[bad_cows.size() - 1][weight_left] >= 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("talent.in", "r", stdin);
    freopen("talent.out", "w", stdout);

    int n, w; cin >> n >> w;

    vector<pair<int, int>> cows(n);
    FOR(n) {
        cin >> cows[i].f >> cows[i].s;
    }

    ll ans = -1;
    double low = 0, high = 250 * 1000 + 1;
    while (high - low >= -0.000000001) {
        double mid = (low + high) / 2;

        // double ratio = mid / 1000.0;
        if (check(cows, w, mid)) {
            ans = mid * 1000;
            low = mid + 0.00001;
        }
        else
            high = mid - 0.00001;
    }

    cout << ans;

    return 0;
}
