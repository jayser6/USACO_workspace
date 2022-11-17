/*____________________________________________________________
// started : 11/16/22
// finished: 11/16/22
// problem : https://codeforces.com/problemset/problem/1709/B
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

    int n, m; cin >> n >> m;

    vector<int> a(n);
    FOR(n)
        cin >> a[i];

    vector<ll> psum_l(n, 0);
    vector<ll> psum_r(n, 0);

    FORO(n) {
        int dif = a[i] - a[i - 1];

        psum_l[i] = psum_l[i - 1];
        if (dif < 0)
            psum_l[i] += dif * -1;
    }

    ROF(n - 1) {
        int dif = a[i] - a[i + 1];

        psum_r[i] = psum_r[i + 1];
        if (dif < 0)
            psum_r[i] += dif * -1;
    }

    FOR(m) {
        int s, t; cin >> s >> t;
        s--; t--;

        if (s < t) {
            // left to right
            cout << psum_l[t] - psum_l[s] << endl;
        }
        else {
            // right to left
            cout << psum_r[t] - psum_r[s] << endl;
        }
    }

    return 0;
}
