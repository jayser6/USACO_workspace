/*____________________________________________________________
// started : 10/05/22
// finished: 10/05/22
// problem : https://cses.fi/problemset/task/1653
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

string dtob(int dec, int n) {
    string bin = "";

    while (dec > 0) {
        bin = (char)(dec % 2 + 48) + bin;
        dec /= 2;
    }

    while (bin.length() < n)
        bin = '0' + bin;

    return bin;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, x; cin >> n >> x;

    vector<int> weights(n);
    FOR(n)
        cin >> weights[i];

    const int EXP = pow(2, n);
    vector<pair<int, int>> dp(EXP, { PRIME32, PRIME32 });

    dp[0] = { 0, 0 };
    FOR(EXP) {
        for (int j = 0;j < n;j++) {
            int place = n - j - 1; // the digit place(is that what it's called?)

            if (i & (1 << place))
                continue;

            int next_i = i + pow(2, place);
            int next_rides = dp[i].f + (dp[i].s + weights[j] > x);
            ll next_weight = (ll)dp[i].s + weights[j];

            if (next_weight > x)
                next_weight = weights[j];

            if (next_rides < dp[next_i].f || (next_rides == dp[next_i].f && next_weight < dp[next_i].s)) {

                dp[next_i] = { max(1, next_rides), next_weight };
            }
        }
    }

    cout << dp[EXP - 1].f;

    return 0;
}
