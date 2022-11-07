/*____________________________________________________________*/
// started : 06/03/22
// finished: 06/03/22
// problem : http://www.usaco.org/index.php?page=viewproblem2&cpid=766
/*____________________________________________________________*/

#include <bits/stdc++.h>

#define FOR(n) for (int i = 0;i < n;i++)
#define FORO(n) for (int i = 1;i < n;i++)
#define ROF(n) for (int i = n - 1;i >= 0;i--)
#define ROFO(n) for (int i = n - 1;i >= 1;i--)
#define forever while (true)
#define ALL(arr) arr.begin(), arr.end()
#define ll long long
#define hashmap unordered_map
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl "\n"
#define BIG_NUMBER (ll)pow(10, 18)

using namespace std;

ifstream fin("barnpainting.in");
ofstream fout("barnpainting.out");

vector<vector<int>> edges;
vector<vector<ll>> dp;

void dfs(int currNode, int color, int parent) {
    if (dp[color][currNode] != -1) { return; }

    ll numWays = 1;
    for (int dest : edges[currNode]) {
        if (dest == parent) { continue; }

        ll sum = 0;
        for (int i = 0;i < 3;i++) {
            if (i == color) { continue; }

            dfs(dest, i, currNode);
            ll subsum = dp[i][dest];
            sum += subsum;
        }
        numWays *= sum;
        numWays %= ((ll)pow(10, 9) + 7);
    }
    dp[color][currNode] = numWays;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k; fin >> n >> k;

    edges = vector<vector<int>>(n);
    FOR(n - 1) {
        int a, b; fin >> a >> b;
        a--; b--;

        edges[a].pb(b);
        edges[b].pb(a);
    }

    dp = vector<vector<ll>>(3, vector<ll>(n, -1));
    FOR(k) {
        int barn, color; fin >> barn >> color;
        barn--; color--; // color goes from 0 to 2

        for (int j = 0;j < 3;j++) {
            if (j == color) { continue; }
            dp[j][barn] = 0;
        }
    }

    ll ans = 0;
    FOR(3) {
        dfs(0, i, -1);
        ans += dp[i][0];
    }

    fout << ans % ((ll)pow(10, 9) + 7);
}
