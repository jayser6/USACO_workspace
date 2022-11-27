/*____________________________________________________________
// started : 11/08/22
// finished:
// problem : https://codeforces.com/problemset/problem/1719/C
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
    int n, q; cin >> n >> q;

    vector<int> fighters(n);

    FOR(n)
        cin >> fighters[i];

    vector<int> simul(n * 2);


    vector<int> win_cnt(n, 0);
    int index = 0;

    while (simul[index] != n) {
        if (simul[index] > simul[index + 1]) {
            // same winner

            simul[index + n] = simul[index + 1];
            simul[index + 1] = simul[index];
        }
        else {
            // new winner

            simul[index + n] = simul[index];
        }

        index++;
    }

    FOR(q) {
        int fi, k; cin >> fi >> k;

        if (fi == n) {
            cout << k - index;
        }
        else {

        }
    }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while (t--)
        solve();

    return 0;
}
