/*____________________________________________________________
// started : 07/04/22
// finished: 07/04/22
// problem : https://codeforces.com/contest/1699/problem/B
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
#define mp make_pair
#define f first
#define s second
#define endl "\n"
#define BIG_NUMBER (ll)1e18
#define MOD (int)1e9 + 7 

using namespace std;

void solve() {
    int n, m; cin >> n >> m;

    int rowcnt = 1;
    int colcnt = 1;
    bool bit = 0;
    bool lastBit;
    for (int i = 0;i < n;i++) {
        lastBit = bit;
        for (int j = 0;j < m;j++) {
            if (rowcnt == 0) {
                bit = !bit;
            }
            cout << bit << " ";
            rowcnt++;
            rowcnt %= 2;
        }
        cout << endl;
        colcnt++;
        colcnt %= 2;
        if (colcnt == 0) {
            bit = !lastBit;
        }
        else {
            bit = lastBit;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
