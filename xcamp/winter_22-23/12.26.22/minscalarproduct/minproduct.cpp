/*____________________________________________________________
// started : 12/26/22
// finished: 12/26/22
// problem : https://codingcompetitions.withgoogle.com/codejam/round/00000000004330f6/0000000000432f33
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

void solve(int t) {
    int n; cin >> n;
    vector<int> v1(n), v2(n);
    FOR(i, n) cin >> v1[i];
    FOR(i, n) cin >> v2[i];

    sort(ALL(v1));
    sort(ALL(v2));

    ll ans = 0;
    FOR(i, n)
        ans += (ll)v1[i] * v2[n - i - 1];

    cout << "Case #" << t << ": " << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;

    FORO(i, t + 1)
        solve(i);

    return 0;
}
