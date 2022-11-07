/*____________________________________________________________
// started : 09/16/22
// finished: 09/16/22
// problem : https://xjoi.net/contest/5020/problem/4
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

bool in_bound(int n, int y, int x) {
    return (0 <= y) && (y < n) && (0 <= x) && (x < n);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;

    freopen("paths.in", "r", stdin);

    // vector<vector<char>> grid(n, vector<char>(m));
    vector<vector<bool>> is_trap(n, vector<bool>(n, false));
    FOR(m) {
        int y, x; cin >> y >> x;
        y--; x--;

        is_trap[y][x] = true;
    }

    if (is_trap[0][0] || is_trap[n - 1][n - 1]) {
        cout << 0;
        return 0;
    }

    vector<vector<ll>> dp(n, vector<ll>(n, 0));
    pair<int, int> moves[] = { { 0, 1 }, { 1, 0 } };

    dp[0][0] = 1;
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            if (is_trap[i][j])
                continue;
            for (pair<int, int> curr_move : moves) {
                int new_y = curr_move.f + i;
                int new_x = curr_move.s + j;

                if (in_bound(n, new_y, new_x)) {
                    dp[new_y][new_x] += dp[i][j];
                    dp[new_y][new_x] %= (int)PRIME32;
                }
            }
        }
    }

    cout << dp[n - 1][n - 1];

    return 0;
}
