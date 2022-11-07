/*____________________________________________________________
// started : 10/29/22
// finished: 11/02/22
// problem : http://www.usaco.org/index.php?page=viewproblem2&cpid=598
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

ll calc_dist(pair<int, int> a, pair<int, int> b) {
    return (ll)(a.f - b.f) * (a.f - b.f) + (ll)(a.s - b.s) * (a.s - b.s);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("radio.in", "r", stdin);
    freopen("radio.out", "w", stdout);

    int n, m; cin >> n >> m;

    int fx, fy, bx, by; cin >> fx >> fy >> bx >> by;
    string f_path, b_path; cin >> f_path >> b_path;

    f_path = '0' + f_path;
    b_path = '0' + b_path;

    vector<pair<int, int>> fpos(n + 1), bpos(m + 1);

    fpos[0] = { fy, fx };
    bpos[0] = { by, bx };

    FORO(n + 1) {
        fpos[i] = { fpos[i - 1].f, fpos[i - 1].s };

        if (f_path[i] == 'N')
            fpos[i].f++;
        else if (f_path[i] == 'S')
            fpos[i].f--;
        else if (f_path[i] == 'E')
            fpos[i].s++;
        else if (f_path[i] == 'W')
            fpos[i].s--;
    }

    FORO(m + 1) {
        bpos[i] = { bpos[i - 1].f, bpos[i - 1].s };

        if (b_path[i] == 'N')
            bpos[i].f++;
        else if (b_path[i] == 'S')
            bpos[i].f--;
        else if (b_path[i] == 'E')
            bpos[i].s++;
        else if (b_path[i] == 'W')
            bpos[i].s--;
    }

    vector<vector<ll>> dp(2, vector<ll>(m + 1, BIG_NUMBER));

    dp[0][0] = 0;

    for (int i = 0;i < n;i++) {
        fill(ALL(dp[(i + 1) % 2]), BIG_NUMBER);
        for (int j = 0;j < m;j++) {
            ll next = dp[i % 2][j] + calc_dist(fpos[i + 1], bpos[j + 1]);
            dp[(i + 1) % 2][j + 1] = min(dp[(i + 1) % 2][j + 1], next);

            next = dp[i % 2][j] + calc_dist(fpos[i + 1], bpos[j]);
            dp[(i + 1) % 2][j] = min(dp[(i + 1) % 2][j], next);

            next = dp[i % 2][j] + calc_dist(fpos[i], bpos[j + 1]);
            dp[i % 2][j + 1] = min(dp[i % 2][j + 1], next);
        }
    }

    cout << dp[n % 2][m];

    return 0;
}

