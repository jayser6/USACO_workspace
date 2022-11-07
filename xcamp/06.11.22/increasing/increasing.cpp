/*____________________________________________________________
// started : 06/12/22
// finished: 06/18/22
// problem : https://cses.fi/problemset/task/1145
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
#define u_int unsigned int
#define hashmap unordered_map
#define hashset unordered_set
#define p_queue priority_queue
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl "\n"
#define BIG_NUMBER (ll)1e18

using namespace std;

struct BITnode {
    int val;
    int depth;
    pair<int, int> range;

    BITnode* parent;
    BITnode* child1;
    BITnode* child2;

    BITnode() {
        val = 0;
        depth = -1;
        range = { -1, -1 };
    }
};

void update(BITnode& curr, int treeDepth) {
    if (curr.depth < treeDepth) {
        curr.val = max((*curr.child1).val, (*curr.child2).val);
    }

    if (curr.depth > 0) {
        update(*curr.parent, treeDepth);
    }
}

// return 0 -> not contained, 1 -> partially contained, 2 -> fully contained
int doesContain(pair<int, int> range, pair<int, int> qRange) {
    if (range.s < qRange.f || range.f > qRange.s) { // not contained at all
        return 0;
    }
    else if (range.f >= qRange.f && range.s <= qRange.s) { // fully contained
        return 2;
    }
    else { // partially contained
        return 1;
    }
}

int findMax(const BITnode& curr, const pair<int, int> qRange) {
    int contain = doesContain(curr.range, qRange);

    if (contain == 0) {
        return 0;
    }
    else if (contain == 1) {
        return max(findMax(*curr.child1, qRange), findMax(*curr.child2, qRange));
    }
    else {
        return curr.val;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<u_int> nums(n);
    FOR(n) {
        u_int input; cin >> input;
        nums[i] = input;
    }

    // coordinate compression
    vector<u_int> coord = nums;
    sort(ALL(coord));

    // making the biary index tree
    int treeSize = 0; // base size of the tree(at the lowest depth)
    int treeDepth = log2(coord.size()); // 0 to treeDepth, inclusive
    if (pow(2, treeDepth) != coord.size()) {
        treeDepth++;
    }
    treeSize = pow(2, treeDepth);

    vector<vector<BITnode>> BITree(treeDepth + 1);
    for (int i = treeDepth;i >= 0;i--) {
        BITree[i] = vector<BITnode>(pow(2, i));
        for (int j = 0;j < BITree[i].size();j++) {
            BITree[i][j].depth = i;
            if (i == treeDepth) {
                BITree[i][j].range = { j, j };
                BITree[i][j].child1 = nullptr;
                BITree[i][j].child2 = nullptr;
            }
            else {
                BITree[i][j].child1 = &BITree[i + 1][j * 2];
                BITree[i][j].child2 = &BITree[i + 1][(j * 2) + 1];
                BITree[i + 1][j * 2].parent = &BITree[i][j];
                BITree[i + 1][(j * 2) + 1].parent = &BITree[i][j];

                BITree[i][j].range = { (*BITree[i][j].child1).range.f, (*BITree[i][j].child2).range.s };
            }
        }
    }
    BITree[0][0].parent = nullptr;

    // dp and solve
    int ans = 0;
    for (u_int currVal : nums) {
        int cc = distance(coord.begin(), lower(ALL(coord), currVal)); // compressed coordinate

        // find the next answer and update the tree
        int dp = findMax(BITree[0][0], { 0, cc - 1 }) + 1;
        ans = max(dp, ans);
        BITree[treeDepth][cc].val = dp;
        update(BITree[treeDepth][cc], treeDepth);
    }

    cout << ans;

    return 0;
}
