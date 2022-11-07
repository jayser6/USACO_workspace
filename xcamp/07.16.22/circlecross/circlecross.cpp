/*____________________________________________________________
// started : 07/20/22
// finished: 07/20/22
// problem : http://www.usaco.org/index.php?page=viewproblem2&cpid=719
____________________________________________________________*/

#include <bits/stdc++.h>

#define FOR(n) for (int i = 0;i < n;i++)
#define FORO(n) for (int i = 1;i < n;i++)
#define ROF(n) for (int i = n - 1;i >= 0;i--)
#define ROFO(n) for (int i = n - 1;i >= 1;i--)
#define loop() while (true) // rust woooo. () after loop bc formatting
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

int BITgetSum(vector<int>& BITree, int index) {
    int sum = 0;
    while (index > 0) {
        sum += BITree[index];
        index -= index & -index;
    }
    return sum;
}

void BITupdate(vector<int>& BITree, int index, int val) {
    while (index < BITree.size()) {
        BITree[index] += val;
        index += index & -index;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("circlecross.in", "r", stdin);
    freopen("circlecross.out", "w", stdout);

    int n; cin >> n;

    vector<pair<int, int>> cows(n + 1, { -1, -1 });
    cows[0] = { 0, 0 };
    FORO((2 * n) + 1) {
        int input; cin >> input;

        if (cows[input].f == -1) {
            cows[input].f = i;
        }
        else {
            cows[input].s = i;
        }
    }

    sort(ALL(cows));

    vector<int> BITree(2 * n + 1, 0);
    int ans = 0;
    FORO(n + 1) {
        ans += BITgetSum(BITree, cows[i].s) - BITgetSum(BITree, cows[i].f - 1);
        BITupdate(BITree, cows[i].s, 1);
    }

    cout << ans;

    return 0;
}
