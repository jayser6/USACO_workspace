// started : 05/07/22
// finished: 05/13/22
// problem : https://cses.fi/problemset/task/1639

#include <bits/stdc++.h>

#define ALL(arr) arr.begin(), arr.end()
#define ll long long
#define hashmap unordered_map
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl "\n"
#define BIG_NUMBER (ll)pow(10, 18)

#define FOR(n) for (int i = 0;i < n;i++)
#define FOR1(n) for (int i = 1;i < n;i++)
#define FORI(n) for (int i = 0;i <= n;i++)
#define FORI1(n) for (int i = 1;i <= n;i++)
#define ROF(n) for (int i = n - 1;i >= 0;i--)
#define ROF1(n) for (int i = n - 1;i >= 1;i--)
#define ROFI(n) for (int i = n;i >= 0;i--)
#define ROFI1(n) for (int i = n;i >= 1;i--)

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s1, s2; cin >> s1 >> s2;

    vector<vector<int>> dp(2, vector<int>(s2.size() + 1));
    for (int i = 0;i < s2.size() + 1;i++) {
        dp[0][i] = i;
    }

    bool currRow = 1; // this is the current row(either first or second row)
    int rowIdx = 1; // this keeps track of the number of rows we computed

    while (rowIdx <= s1.size()) {
        dp[currRow][0] = rowIdx;
        FORI1(s2.size()) {
            int add = dp[currRow][i - 1] + 1;
            int rep = dp[!currRow][i - 1] + !(s1.at(rowIdx - 1) == s2.at(i - 1));
            int rem = dp[!currRow][i] + 1;
            dp[currRow][i] = min(add, min(rep, rem));
        }

        currRow = !currRow;
        rowIdx++;
    }

    cout << dp[!currRow][s2.size()];
}