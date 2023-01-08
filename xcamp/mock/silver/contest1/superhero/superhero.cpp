/*____________________________________________________________
// started : 01/07/23
// finished: 01/08/23
// problem : https://contest.xinyoudui.com/contest/19/problem/107
____________________________________________________________*/

#include <bits/stdc++.h>
using namespace std;

// #pragma GCC optimize ("Ofast")
// #pragma GCC target ("avx2")

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
#define tup tuple
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
#define SMALL (int)INT_MIN
#define SMALLER (ll)LLONG_MIN
#define PRIME64 (ll)999998727899999 // this number has 15 digits
#define PRIME32 (int)(1e9 + 7) 
#define ASCII_PRIME (int)257
#define ALPHA_PRIME (int)29

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q; cin >> n >> q;
    set<int> x;
    multiset<int> gap;
    FOR(i, n) {
        int x_i; cin >> x_i;
        x.insert(x_i);
    }

    for (auto it = x.begin();it != x.end();) {
        int curr = *it;
        it++;

        if (it != x.end()) gap.insert(*it - curr);
    }

    int tot = *x.rbegin() - *x.begin();
    cout << tot - *gap.rbegin() << endl;

    FOR(i, q) {
        int op, x_i; cin >> op >> x_i;

        if (op == 0) {
            auto it = x.find(x_i);
            if (it != x.end()) {
                auto next = ++x.find(x_i), prev = --x.find(x_i);

                bool a = next != x.end(), b = it != x.begin();
                if (a && b) {
                    auto remove = gap.find(*next - *it);
                    gap.erase(remove);
                    remove = gap.find(*it - *prev);
                    gap.erase(remove);

                    gap.insert(*next - *prev);
                }
                else if (a) {
                    auto remove = gap.find(*next - *it);
                    tot -= *next - *it;
                    gap.erase(remove);
                }
                else if (b) {
                    auto remove = gap.find(*it - *prev);
                    tot -= *it - *prev;
                    gap.erase(remove);
                }

                x.erase(x_i);
            }
        }
        else {
            auto it = x.find(x_i);
            if (it == x.end()) {
                x.insert(x_i);
                it = x.find(x_i);

                auto next = ++x.find(x_i), prev = --x.find(x_i);

                bool a = next != x.end(), b = it != x.begin();
                if (a && b) {
                    gap.insert(*next - *it);
                    gap.insert(*it - *prev);

                    auto remove = gap.find(*next - *prev);
                    gap.erase(remove);
                }
                else if (a) {
                    tot += *next - *it;
                    gap.insert(*next - *it);
                }
                else if (b) {
                    tot += *it - *prev;
                    gap.insert(*it - *prev);
                }
            }
        }

        if (gap.empty()) cout << 0 << endl;
        else cout << tot - *gap.rbegin() << endl;
    }

    return 0;
}
