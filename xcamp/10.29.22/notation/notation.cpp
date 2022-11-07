/*____________________________________________________________
// started : 11/04/22
// finished: 11/04/22
// problem : https://codeforces.com/problemset/problem/1730/C
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
    string str; cin >> str;

    int n = str.length();
    vector<pair<int, bool>> num(n);
    vector<bool> did_appear(10, false);

    FOR(n)
        num[i] = { str[i] - '0', false };

    did_appear[num[n - 1].f] = true;

    ROF(n - 1) {
        for (int j = 0;j < num[i].f;j++) {
            if (did_appear[j]) {
                num[i].s = true;
                break;
            }
        }
        did_appear[num[i].f] = true;
    }

    sort(ALL(num));

    FOR(n) {
        cout << min(num[i].f + num[i].s, 9);
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;

    while (t--)
        solve();

    return 0;
}
