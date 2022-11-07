/*____________________________________________________________
// started : 06/01/22
// finished: 06/01/22
// problem : http://www.usaco.org/index.php?page=viewproblem2&cpid=945
____________________________________________________________*/

// think of this as creating groups; same group = same net size

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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("snakes.in", "r", stdin);
    freopen("snakes.out", "w", stdout);

    int n, k; cin >> n >> k;

    vector<int> snakes(n);
    for (int& currSnake : snakes) {
        cin >> currSnake;
    }

    vector<vector<ll>> dp(2, vector<ll>(n));
    { // calculate the total waste if Bessie doesn't swap nets
        int sum = 0;
        int largest = -1;
        FOR(n) {
            sum += snakes[i];
            largest = max(largest, snakes[i]);

            dp[false][i] = (largest * (i + 1)) - sum;
        }
    }

    bool curr = false;
    for (int i = 0;i < k;i++) {
        curr = !curr;

        // reset the array so that the min() function works as intended
        for (int j = 0;j < n;j++) {
            dp[curr][j] = BIG_NUMBER;
        }

        for (int j = i + 1;j < n;j++) {
            int sum = 0; // only keeps track of the running sum
            int largest = -1;
            for (int l = j;l < n;l++) {
                largest = max(largest, snakes[l]);
                sum += snakes[l];

                dp[curr][l] = min(dp[!curr][j - 1] + (largest * (l - j + 1)) - sum, dp[curr][l]);
            }
        }
    }

    cout << dp[curr][n - 1];
}
