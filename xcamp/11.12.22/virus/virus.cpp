/*____________________________________________________________
// started : 11/16/22
// finished: 11/19/22
// problem : https://codeforces.com/problemset/problem/1704/C
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

void solve() {
    int n, m; cin >> n >> m;

    vector<int> infected(m);
    FOR(m) {
        cin >> infected[i];
    }
    sort(ALL(infected));

    vector<int> gap(m);
    FORO(m) {
        gap[i - 1] = infected[i] - infected[i - 1] - 1;
    }
    gap[m - 1] = n - (infected[m - 1] - infected[0]) - 1;
    sort(ALL(gap), greater<int>());

    int output = 0;
    FOR(m) {
        if (gap[i] - 4 * i > 1) {
            output += 4 * i + 1;
        }
        else if (gap[i] - 4 * i == 1) {
            output += 4 * i;
        }
        else {
            output += gap[i];
        }
    }

    cout << output + m << endl;

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;

    while (t--)
        solve();

    return 0;
}
