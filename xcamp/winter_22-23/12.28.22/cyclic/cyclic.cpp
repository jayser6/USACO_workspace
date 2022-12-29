/*____________________________________________________________
// started : 12/28/22
// finished: 12/28/22
// problem : https://codeforces.com/problemset/problem/1672/D
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

    vector<int> a(n), b(n);
    FOR(i, n) cin >> a[i];
    FOR(i, n) cin >> b[i];

    // 2p 
    int p_a = 0, p_b = 0;
    multiset<int> removed;

    while (p_b < n) {
        if (a[p_a] == b[p_b]) {
            p_a++;
            p_b++;
        }
        else {
            if (removed.count(b[p_b]) && (p_b > 0 && b[p_b] == b[p_b - 1])) {
                removed.erase(removed.find(b[p_b]));
                p_b++;
            }
            else {
                if (p_a == n) {
                    cout << "NO" << endl;
                    return;
                }
                removed.insert(a[p_a]);
                p_a++;
            }
        }
    }

    cout << "YES" << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while (t--)
        solve();

    return 0;
}
