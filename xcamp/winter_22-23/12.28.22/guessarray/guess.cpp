/*____________________________________________________________
// started : 12/28/22
// finished: 12/28/22
// problem : https://codeforces.com/problemset/problem/727/C
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

int main() {
    int n; cin >> n;

    vector<ll> sum(n);
    FOR(i, n - 1) {
        cout << "? 1 " << i + 2 << endl;
        fflush(stdout);
        cin >> sum[i];
    }
    cout << "? 2 3" << endl;
    fflush(stdout);
    cin >> sum[n - 1];

    vector<int> ans(n);
    ans[0] = (int)(0.5 * (sum[0] + sum[1] - sum[n - 1] + 0.0));
    FORO(i, n) {
        ans[i] = sum[i - 1] - ans[0];
    }

    cout << "! ";
    FOR(i, n) {
        cout << ans[i] << " ";
    }

}
