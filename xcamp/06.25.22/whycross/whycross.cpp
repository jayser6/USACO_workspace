/*____________________________________________________________
// started : 06/26/22
// finished: 06/26/22
// problem : http://www.usaco.org/index.php?page=viewproblem2&cpid=720
____________________________________________________________*/

#include <bits/stdc++.h>

#define FOR(n) for (int i = 0;i < n;i++)
#define FORO(n) for (int i = 1;i < n;i++)
#define ROF(n) for (int i = n - 1;i >= 0;i--)
#define ROFO(n) for (int i = n - 1;i >= 1;i--)
#define loop while (true)
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

using namespace std;

ifstream fin("mincross.in");
ofstream fout("mincross.out");

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
    cin.tie(NULL);

    int n; fin >> n;

    // 1-index all the vectors for ease of implementation
    vector<int> left(n + 1), right(n + 1);
    vector<int> leftMapped(n + 1), rightMapped(n + 1);
    FORO(n + 1) {
        fin >> left[i];
        leftMapped[left[i]] = i;
    }
    FORO(n + 1) {
        fin >> right[i];
        rightMapped[right[i]] = i;
    }

    // find the number of crosses without considering any cyclic shifts
    ll crosses = 0;
    vector<int> BITree(n + 1, 0);
    FORO(n + 1) {
        crosses += (i - 1) - BITfindSum(BITree, leftMapped[right[i]]);
        BITupdate(BITree, leftMapped[right[i]], 1);
    }

    // go through the different cycles and find answer
    ll ans = crosses;
    ll leftCycle = crosses, rightCycle = crosses;
    FORO(n) {
        rightCycle += (n - leftMapped[right[i]]) - (leftMapped[right[i]] - 1);
        leftCycle += (n - rightMapped[left[i]]) - (rightMapped[left[i]] - 1);
        ans = min(ans, min(leftCycle, rightCycle));
    }

    fout << ans;

    return 0;
}
