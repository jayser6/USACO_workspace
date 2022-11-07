/*____________________________________________________________
// started : 07/13/22
// finished:
// problem : https://oj.uz/problem/view/NOI18_knapsack and file:///C:/Users/jayse/Downloads/statement_en.pdf
//
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
#define BIG_NUMBER 1e18
#define BIG_PRIME 999998727899999 // this number has 15 digits
#define PRIME32 1e9 + 7 
#define ASCII_PRIME 257
#define ALPHA_PRIME 29

using namespace std;

struct DP {
    ll val;

    // the prevW of the previous item that we landed on the dp state with, the
    // index of the item in the vector, the number of specific items already
    // bought
    int prevW, wIndex, cnt;

    DP() {
        val = -1;
        prevW = -1;
    }
    DP(ll val, int prevW, int wIndex, int cnt) {
        this->val = val;
        this->prevW = prevW;
        this->wIndex = wIndex;
        this->cnt = cnt;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // maxWeight is S from the problem statement, can't use s as variable name
    // because macro though
    int maxWeight, n; cin >> maxWeight >> n;

    // key -> prevW, e.f -> val, e.s -> cnt. Sorted in descending order
    map<int, vector<pair<int, int>>, greater<int>> items;
    FOR(n) {
        int val, prevW, cnt; cin >> val >> prevW >> cnt;
        if (prevW <= maxWeight) {
            items[prevW].pb({ val, cnt });
        }
    }

    vector<DP> dp(maxWeight + 1);
    for (auto& curr : items) {
        sort(ALL(curr.s), greater<pair<int, int>>());
        dp[curr.f] = DP(curr.s[0].f, curr.f, 0, 1);
    }

    for (int basketW = 0;basketW <= maxWeight;basketW++) {
        if (dp[basketW].val == -1) {
            // skip since this state cannot be reached anyways
            continue;
        }

        // transition 
        for (auto& currItem : items) {
            int newWeight = basketW + currItem.f;
            if ((currItem.f > dp[basketW].prevW) || (newWeight > maxWeight)) {
                continue;
            }
            else if (currItem.f == dp[basketW].prevW) {
                if (dp[basketW].cnt < currItem.s[dp[basketW].wIndex].s) {
                    // more of this particular item can be added
                    ll newVal = dp[basketW].val + currItem.s[dp[basketW].wIndex].f;
                    if ((newVal > dp[newWeight].val) && (currItem.f > dp[newWeight].prevW)) {
                        dp[newWeight] = DP(newVal, currItem.f, dp[basketW].wIndex, dp[basketW].cnt + 1);
                    }
                }
                else if (dp[basketW].wIndex < currItem.s.size() - 1) {
                    // an item with the same prevW can be added
                    ll newVal = dp[basketW].val + currItem.s[dp[basketW].wIndex + 1].f;
                    if ((newVal > dp[newWeight].val) && (currItem.f > dp[newWeight].prevW)) {
                        dp[newWeight] = DP(newVal, currItem.f, dp[basketW].wIndex + 1, 1);
                    }
                }
            }
            else {
                ll newVal = dp[basketW].val + currItem.s[0].f;
                if ((newVal > dp[newWeight].val) && (currItem.f > dp[newWeight].prevW)) {
                    dp[newWeight] = DP(newVal, currItem.f, 0, 1);
                }
            }
        }
    }

    ll ans = 0;
    FOR(maxWeight + 1) {
        ans = max(ans, dp[i].val);
    }
    cout << ans;

    return 0;
}
