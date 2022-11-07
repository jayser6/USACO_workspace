/*____________________________________________________________
// started : 07/13/22
// finished: 07/15/22
// problem : https://oj.uz/problem/view/NOI18_knapsack
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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // maxWeight is S from the problem statement, can't use s as variable name
    // because macro though
    int maxW, n; cin >> maxW >> n;

    // key -> weight, e.f -> val, e.s -> cnt
    map<int, vector<pair<int, int>>> items;
    FOR(n) {
        int val, weight, cnt; cin >> val >> weight >> cnt;
        if (weight <= maxW) {
            items[weight].pb({ val, cnt });
        }
    }

    vector<vector<ll>> dp(items.size() + 1, vector<ll>(maxW + 1, -1));
    dp[0][0] = 0;
    ll ans = -1;
    int itemIndex = 1;

    for (auto& currBatch : items) {
        int itemW = currBatch.f;
        vector<pair<int, int>>& currItems = currBatch.s;
        sort(ALL(currItems), greater<pair<int, int>>());

        FOR(maxW + 1) {
            dp[itemIndex][i] = dp[itemIndex - 1][i];
            int copies = 0, wI = 0, currCnt = 0;
            ll val = 0;

            // this dp updates curr from prev, which is opposite of what I was
            // trying to do in my other solution, which is updating next from
            // curr
            while (((copies + 1) * itemW <= i) && (wI < currItems.size())) {
                copies++;
                val += currItems[wI].f;
                if (dp[itemIndex - 1][i - (copies * itemW)] != -1) {
                    dp[itemIndex][i] = max(dp[itemIndex][i], dp[itemIndex - 1][i - (copies * itemW)] + val);

                    ans = max(ans, dp[itemIndex][i]);
                }

                currCnt++;
                if (currCnt == currItems[wI].s) {
                    wI++;
                    currCnt = 0;
                }
            }
        }
        itemIndex++;
    }

    cout << ans;

    return 0;
}
