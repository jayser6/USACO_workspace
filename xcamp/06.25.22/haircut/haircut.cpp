/*____________________________________________________________
// started : 06/28/22
// finished: 06/28/22
// problem : http://www.usaco.org/index.php?page=viewproblem2&cpid=1041
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
#define BIG_NUMBER (ll)1e18
#define MOD (int)1e9 + 7 

using namespace std;

void BITupdate(vector<int>& BITree, int index, int val) {
    while (index < BITree.size()) {
        BITree[index] += val;
        index += index & -index;
    }
}

int BITfindSum(vector<int>& BITree, int index) {
    int sum = 0;
    while (index > 0) {
        sum += BITree[index];
        index -= index & -index;
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("haircut.in", "r", stdin);
    freopen("haircut.out", "w", stdout);

    int n; cin >> n;

    // the hair has to be 1-indexed, so max hair length is n + 1
    vector<int> BITree(n + 2, 0);
    vector<ll> inversions(n + 2, 0);
    FOR(n) {
        int input; cin >> input;
        input++; // 1-index the hair length!!!!

        inversions[input] += i - BITfindSum(BITree, input);
        BITupdate(BITree, input, 1);
    }

    ll ans = 0;
    FOR(n) {
        ans += inversions[i];
        cout << ans << endl;
    }

    return 0;
}
