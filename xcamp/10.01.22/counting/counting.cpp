/*____________________________________________________________
// started : 11/29/22
// finished: 11/29/22
// problem : https://cses.fi/problemset/task/2220/
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

ll calc(string num) {
    ll dp[19][10][4]; // 10 -> is_max = true, 01 -> starting_zero = true

    if (num == "0")
        return 1;

    for (int i = 0;i < 18;i++)
        for (int j = 0;j < 10;j++)
            for (int k = 0;k < 4;k++)
                dp[i][j][k] = 0;

    dp[0][0][1] = 1;
    dp[0][num[0] - '0'][2] = 1;
    FORO(num[0] - '0') {
        dp[0][i][0] = 1;
    }

    FOR(num.length() - 1) {
        for (int j = 0;j < 10;j++) {
            int digit = num[i] - '0';
            int next_digit = num[i + 1] - '0';

            for (int k = 0;k < 10 && j == 0;k++) {
                if (k == 0)
                    dp[i + 1][0][1] += dp[i][0][1];
                else
                    dp[i + 1][k][0] += dp[i][0][1];
            }

            for (int k = 0;k < 10;k++) {
                if (j != k)
                    dp[i + 1][k][0] += dp[i][j][0];
            }

            for (int k = 0;k <= next_digit - 1 && j == digit;k++) {
                if (j != k)
                    dp[i + 1][k][0] += dp[i][j][2];
            }

            if (j != next_digit && j == digit)
                dp[i + 1][next_digit][2] += dp[i][digit][2];
        }
    }

    ll output = 0;
    for (int i = 0;i < 10;i++)
        for (int j = 0;j < 4;j++)
            output += dp[num.length() - 1][i][j];

    return output;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string a, b; cin >> a >> b;

    bool should_include = true;
    FOR(a.length() - 1) {
        if (a[i] == a[i + 1])
            should_include = false;
    }

    cout << calc(b) - calc(a) + should_include;

    return 0;
}
