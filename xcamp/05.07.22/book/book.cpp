// started : 05/07/22
// finished: 05/24/22
// problem : https://cses.fi/problemset/task/1158

#include <bits/stdc++.h>

#define FOR(n) for (int i = 0;i < n;i++)
#define FORO(n) for (int i = 1;i < n;i++) 
#define ROF(n) for (int i = n - 1;i >= 0;i--)
#define ROFO(n) for (int i = n - 1;i >= 1;i--)
#define forever while (true)
#define ALL(arr) arr.begin(), arr.end()
#define lower lower_bound
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

    int n, x; cin >> n >> x;

    vector<int> prices(n);
    vector<int> pages(n);
    for (int& input : prices) {
        cin >> input;
    }
    for (int& input : pages) {
        cin >> input;
    }

    vector<vector<int>> dp(2, vector<int>(x + 1, 0));
    bool tf = false; // tf stands for true / false
    for (int i = 0;i < n;i++) {
        tf = !tf;
        for (int j = 1;j <= x;j++) {
            dp[tf][j] = dp[!tf][j];
            if (prices[i] <= j) {
                dp[tf][j] = max(dp[tf][j], dp[!tf][j - prices[i]] + pages[i]);
            }
        }
    }

    cout << dp[tf][x];
}