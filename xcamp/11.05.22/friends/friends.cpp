/*____________________________________________________________
// started : 11/08/22
// finished: 11/08/22
// problem : https://codeforces.com/problemset/problem/1729/D
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
    /* input */

    int n; cin >> n;
    vector<int> x(n), y(n);

    FOR(n)
        cin >> x[i];
    FOR(n)
        cin >> y[i];

    /* find y - x for each person and sort it */

    vector<int> dif(n);

    FOR(n)
        dif[i] = y[i] - x[i];

    sort(ALL(dif));

    /* find the first person with the least y - x that can be paired */

    int ans = 0;
    int a = 0, b = n - 1;

    while (a <= b) {
        if (dif[a] >= 0) {
            ans += (b - a + 1) / 2;
            break;
        }
        else {
            int match = dif[a] * -1;

            if (dif[b] >= match) {
                ans++;
                a++;
                b--;
            }
            else
                a++;
        }

        int debug = 0;
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int k; cin >> k;

    while (k--)
        solve();

    return 0;
}
