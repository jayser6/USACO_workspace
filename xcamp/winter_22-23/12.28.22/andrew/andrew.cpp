/*____________________________________________________________
// started : 12/28/22
// finished: 12/28/22
// problem : https://codeforces.com/problemset/problem/1637/C
____________________________________________________________*/

#include <bits/stdc++.h>

#define FOR(i, n) for (int i = 0;i < n;i++)
#define FORO(i, n) for (int i = 1;i < n;i++)
#define ROF(i, n) for (int i = n - 1;i >= 0;i--)
#define ROFO(i, n) for (int i = n - 1;i >= 1;i--)
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
#define BIG_INT64 (ll)1e18
#define PRIME64 (ll)999998727899999 // this number has 15 digits
#define PRIME32 (int)(1e9 + 7) 
#define ASCII_PRIME (int)257
#define ALPHA_PRIME (int)29

using namespace std;

void solve() {
    int n; cin >> n;

    vector<int> rocks(n);
    FOR(i, n)
        cin >> rocks[i];

    ll ans = 0;
    ll rocks_right = 0;
    ll odds_left = 0;
    FORO(i, n - 1) {
        if (rocks[i] % 2 == 1 && rocks_right > 0) {
            rocks[i]++;
            rocks_right--;
        }

        ll scatter = rocks[i] / 2;

        if (odds_left > 0 && scatter > 0) {
            scatter += odds_left;
            odds_left = 0;
            if (rocks[i] % 2 == 1) {
                scatter++;
                rocks[i]++;
            }
        }

        if (rocks[i] % 2 == 1) {
            odds_left++;
        }

        ans += scatter;
        rocks_right += scatter;
    }

    if (odds_left > 0)
        cout << -1 << endl;
    else
        cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while (t--)
        solve();

    return 0;
}
