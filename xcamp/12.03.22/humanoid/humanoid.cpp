/*____________________________________________________________
// started : 12/10/22
// finished: 12/10/22
// problem : https://codeforces.com/problemset/problem/1759/E
____________________________________________________________*/

#include <bits/stdc++.h>

#define FOR(i, n) for (int i = 0;i < n;i++)
#define FORO(i, n) for (int i = 1;i < n;i++)
#define ROF(i, n) for (int i = n - 1;i >= 0;i--)
#define ROFO(i, n) for (int i = n - 1;i >= 1;i--)
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
#define BIG_NUMBER 1e18LL
#define BIG_PRIME 999998727899999LL // this number has 15 digits
#define PRIME32 (int)(1e9 + 7) 
#define ASCII_PRIME (int)257
#define ALPHA_PRIME (int)29

using namespace std;

ll eat(vector<int>& a, vector<ll>& psum, ll curr_val, int eat_start) {
    auto it = upper(ALL(a), curr_val - 1) - 1;
    int index = it - a.begin();

    while (index > eat_start) {
        // eat available astronauts starting from eat_start + 1
        curr_val += psum[it - a.begin()] - psum[eat_start];
        eat_start = it - a.begin();
        it = upper(ALL(a), curr_val - 1) - 1;
        index = it - a.begin();
    }

    return curr_val;
}

void solve() {
    /* input */

    int n, h; cin >> n >> h;

    vector<int> a(n + 1);
    a[0] = 0;
    FORO(i, n + 1)
        cin >> a[i];

    /* sort a and make a psum */

    vector<ll> psum(n + 1);

    psum[0] = 0;
    sort(ALL(a));

    FORO(i, n + 1)
        psum[i] = psum[i - 1] + a[i] / 2;

    /* dp */

    ll dp[n + 1][3][2]; // dp[i][j][k] = max value at least a[i] but less than a[i + 1] using j green serums and k blue serums with no astronauts available to eat
    memset(dp, -1, sizeof(dp));


    // initial states
    auto it = upper(ALL(a), h);

    if (it == a.begin()) {
        dp[0][0][0] = h;
    }
    else {
        ll initial = eat(a, psum, h, 0);
        auto initial_index = upper(ALL(a), initial) - 1;

        dp[initial_index - a.begin()][0][0] = initial;
    }

    ll ans = 0;

    FOR(i, n + 1) {
        FOR(j, 3) {
            FOR(k, 2) {
                if (dp[i][j][k] == -1)
                    continue;

                ll start_val = dp[i][j][k];
                ans = i;

                // try using the green serum
                if (j < 2) {
                    ll next_val = eat(a, psum, 2 * dp[i][j][k], i);
                    auto next_index = upper(ALL(a), next_val - 1) - 1;

                    dp[next_index - a.begin()][j + 1][k] = max(dp[next_index - a.begin()][j + 1][k], next_val);
                }

                // try using the blue serum
                if (k < 1) {
                    ll next_val = eat(a, psum, 3 * dp[i][j][k], i);
                    auto next_index = upper(ALL(a), next_val - 1) - 1;

                    dp[next_index - a.begin()][j][k + 1] = max(dp[next_index - a.begin()][j][k + 1], next_val);
                }
            }
        }
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while (t--)
        solve();

    return 0;
}
