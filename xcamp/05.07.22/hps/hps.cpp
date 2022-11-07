/*____________________________________________________________*/
// started : 05/12/22
// finished: 05/16/22
// problem : http://www.usaco.org/index.php?page=viewproblem2&cpid=694
/*____________________________________________________________*/

#include <bits/stdc++.h>

#define FOR(n) for (int i = 0;i < n;i++)
#define FORO(n) for (int i = 1;i < n;i++) 
#define ROF(n) for (int i = n - 1;i >= 0;i--)
#define ROFO(n) for (int i = n - 1;i >= 1;i--)
#define forever while (true)
#define ALL(arr) arr.begin(), arr.end()
#define lower lower_bound
#define upper upper_bound
#define ll long long
#define hashmap unordered_map
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl "\n"
#define BIG_NUMBER (ll)pow(10, 18)

using namespace std;

ifstream fin("hps.in");
ofstream fout("hps.out");

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k; fin >> n >> k;
    vector<char> moves(n);

    for (char& curr : moves) {
        fin >> curr;
    }

    const char GESTURES[3] = { 'H', 'P', 'S' };
    vector<vector<vector<int>>> dp(2, vector<vector<int>>(3, vector<int>(k + 1))); // current and next iteration, three gestures, k switches
    FOR(3) {
        dp[0][i][0] = (moves[0] == GESTURES[i]);
    }

    bool curr = 0;
    FORO(n) {
        // reset the vectors
        for (int k_ = 0;k_ < k + 1;k_++) {
            for (int u = 0;u < 3;u++) {
                dp[!curr][u][k_] = -1;
            }
        }

        for (int k_ = 0;k_ < i && k_ < (k + 1);k_++) {
            for (int u = 0;u < 3;u++) {
                for (int v = 0;v < 3;v++) {
                    int nextK = k_ + !(v == u);
                    if (nextK < (k + 1)) { // switches are still available
                        dp[!curr][v][nextK] = max(dp[!curr][v][nextK], dp[curr][u][k_] + (GESTURES[v] == moves[i]));
                    }
                }
            }
        }

        curr = !curr;
    }

    int ans = -1;
    FOR(3) {
        for (int k_ = 0;k_ < (k + 1);k_++) {
            ans = max(ans, dp[curr][i][k_]);
        }
    }

    fout << ans;
}