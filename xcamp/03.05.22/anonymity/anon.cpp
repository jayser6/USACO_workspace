// started : 03/07/22
// finished: 03/23/22
// problem : https://codeforces.com/problemset/problem/1641/C

#include <bits/stdc++.h>

#define ALL(arr) arr.begin(), arr.end()
#define ll long long
#define hashmap unordered_map
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl "\n"
#define BIG_NUMBER 10000001

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q; cin >> n >> q;

    vector<int> ans(n + 1, 0);
    vector<int> range(n + 1, BIG_NUMBER);
    set<int> na;

    for (int i = 1;i <= n + 1;i++) { // add n + 1 to the set just to avoid weird edge cases
        na.insert(i);
    }

    for (int query = 0;query < q;query++) {
        int t; cin >> t;

        if (t == 0) {
            int l, r, x; cin >> l >> r >> x;

            if (x == 0) {
                auto curr = na.lower_bound(l);
                int rangeCarry = BIG_NUMBER;
                while (curr != na.end() && *curr <= r) {
                    ans[*curr] = 1;
                    rangeCarry = min(rangeCarry, range[*curr]);
                    na.erase(curr);
                    curr = na.lower_bound(l);
                }

                if (curr != na.end()) { // pass the range to the patient directly right of r
                    range[*curr] = min(rangeCarry, range[*curr]);
                    auto rangeR = na.upper_bound(range[*curr]);
                    if (rangeR != na.begin() && rangeCarry < BIG_NUMBER) {
                        rangeR--;
                        if (*curr == *rangeR) {
                            ans[*curr] = 2;
                        }
                    }
                }

                // now check if the person immediately left of l is guaranteed sick
                auto leftOfL = na.lower_bound(l);
                if (leftOfL == na.end()) {
                    leftOfL--;
                    if (range[*leftOfL] < BIG_NUMBER) {
                        ans[*leftOfL] = 2;
                    } 
                }
                else {
                    int valR = *leftOfL;
                    leftOfL--;
                    int valL = *leftOfL;
                    if (range[valL] < valR) {
                        ans[*leftOfL] = 2;
                    }
                }
            }
            else {
                auto lower = na.lower_bound(l); // left side of the range
                auto upper = na.upper_bound(r); // right side of the range
                if (lower != na.end() && upper != na.begin()) {
                    upper--;
                    if (*lower == *upper) {
                        ans[*lower] = 2;
                    }
                    else {
                        range[*lower] = min(*upper, range[*lower]);
                    }
                }
            }
        }
        else {
            int j; cin >> j;

            if (ans[j] == 0) {
                cout << "N/A" << endl;
            }
            else if (ans[j] == 1) {
                cout << "NO" << endl;
            }
            else {
                cout << "YES" << endl;
            }
        }
    }

}