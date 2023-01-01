/*____________________________________________________________
// started : 01/01/23
// finished: 01/01/23
// problem : https://codeforces.com/problemset/problem/1774/D
____________________________________________________________*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")

#define debug(x) #x << ": " << x << " "
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
#define BIG (int)INT_MAX 
#define BIGGER (ll)LLONG_MAX
#define PRIME64 (ll)999998727899999 // this number has 15 digits
#define PRIME32 (int)(1e9 + 7) 
#define ASCII_PRIME (int)257
#define ALPHA_PRIME (int)29

void solve() {
    int n, m; cin >> n >> m;

    vector<vector<int>> arr(n, vector<int>(m));
    vector<int> cnt_one(n, 0);
    int sum_ones = 0;
    vector<set<int>> loc_one(m);
    FOR(i, n) {
        FOR(j, m) {
            cin >> arr[i][j];
            if (arr[i][j] == 1) {
                loc_one[j].insert(i);
                cnt_one[i]++;
                sum_ones++;
            }
        }
    }
    if (sum_ones % n != 0) {
        cout << "-1" << endl;
        return;
    }

    int avg = sum_ones / n;
    vector<tuple<int, int, int>> operations(0);
    int size = operations.size();

    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            if (cnt_one[i] >= avg) break;
            if (arr[i][j] == 0) {
                for (auto k = loc_one[j].begin(); k != loc_one[j].end();) {
                    int kp = *k;
                    if (cnt_one[kp] > avg) {
                        cnt_one[kp]--;
                        cnt_one[i]++;
                        operations.pb({ kp + 1, i + 1, j + 1 });
                        loc_one[j].erase(kp);
                        break;
                    }
                    k++;
                    loc_one[j].erase(kp);
                }
            }
        }
    }

    cout << operations.size() << endl;
    for (auto i : operations) {
        cout << get<0>(i) << " " << get<1>(i) << " " << get<2>(i) << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}
