/*____________________________________________________________
// started : 09/29/22
// finished: 09/29/22
// problem : https://cses.fi/problemset/task/1145
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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    // stores the smallest ending element in any LIS of length i
    vector<int> dp(n + 1, PRIME32);
    dp[0] = 0;

    // get input and update dp
    FOR(n) {
        int a; cin >> a;

        // find the biggest ending element that is less than a
        auto bs = lower(ALL(dp), a);
        int index = bs - dp.begin();

        if (a < dp[index])
            dp[index] = a;
    }

    ROF(n + 1) {
        if (dp[i] != PRIME32) {
            cout << i;
            return 0;
        }
    }

    return 0;
}
