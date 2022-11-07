/*____________________________________________________________
// started : 09/29/22
// finished: 09/29/22
// problem : https://cses.fi/problemset/task/1140
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

    multimap<int, pair<int, int>> points;
    FOR(n) {
        int a, b, p; cin >> a >> b >> p;

        // the .s.s of a is -1 just to distinguish start from end 
        points.insert({ a, { b, -1 } });
        points.insert({ b, { a, p } });
    }

    vector<ll> dp = { 0 };
    map<int, int> cc;
    int index = 0;
    int prev_coor = -1;

    cc[0] = 0;

    for (auto curr : points) {
        // see if this point is a new coordinate
        if (prev_coor != curr.f) {
            index++;
            prev_coor = curr.f;
            cc[curr.f] = index;
            dp.pb(dp[index - 1]);
        }

        // is the point an endpoint or a startpoint?
        if (curr.s.s != -1) {
            int cc_start = cc[curr.s.f];
            int pay = curr.s.s;

            dp[index] = max(dp[index], dp[cc_start - 1] + pay);
        }
    }

    cout << dp[dp.size() - 1];

    return 0;
}
