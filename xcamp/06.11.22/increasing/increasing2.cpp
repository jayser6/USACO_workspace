/*____________________________________________________________
// started : 06/19/22
// finished: 06/19/22
// problem : https://cses.fi/problemset/task/1145
// note    : Solution using the linear array implementation of segment tree. Refer to this
             link later if confused
             https://www.geeksforgeeks.org/segment-tree-set-1-sum-of-given-range/

             I can also use a struct to store the range and the value of a node
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

int mid(int a, int b) { return (a + b) / 2; }

// stI -> segment tree index, stS -> segment tree range start, 
// stE -> segment tree range end

// this is unnecessary for this question; values in seg tree are all 0 initially
int stMake(vector<int>& st, vector<int>& arr, int stI, int stS, int stE) {
    // check if the current node is a leaf node
    if (stS == stE) {
        st[stI] = arr[stS];
        return st[stI];
    }

    st[stI] = max(stMake(st, arr, (stI * 2) + 1, stS, mid(stS, stE)), stMake(st, arr, (stI * 2) + 2, mid(stS, stE) + 1, stE));
    return st[stI];
}

int stFindMax(vector<int>& st, int stI, int stS, int stE, int qS, int qE) {
    if ((stE < qS) || (stS > qE)) { // not contained at all
        return 0;
    }
    else if ((stS >= qS) && (stE <= qE)) { // fully contained
        return st[stI];
    }
    else { // partially contained
        return max(stFindMax(st, (stI * 2) + 1, stS, mid(stS, stE), qS, qE), stFindMax(st, (stI * 2) + 2, mid(stS, stE) + 1, stE, qS, qE));
    }
}

// update starts from the root of the tree
int stUpdate(vector<int>& st, int stI, int stS, int stE, int updateI, int updateVal) {
    if ((updateI < stS) || (updateI > stE)) { // not contained at all
        return st[stI];
    }
    else if (stS == stE) { // reached the bottom of the segment tree
        st[stI] = updateVal;
        return st[stI];
    }
    else { // partially contained
        st[stI] = max(stUpdate(st, (stI * 2) + 1, stS, mid(stS, stE), updateI, updateVal), stUpdate(st, (stI * 2) + 2, mid(stS, stE) + 1, stE, updateI, updateVal));
        return st[stI];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<int> nums(n);
    for (int& input : nums) {
        cin >> input;
    }

    // coordinate compression
    vector<int> ccMap = nums;
    sort(ALL(ccMap));

    // build min segment tree
    int stDepth = ceil(log2(n));
    int stSize = pow(2, stDepth + 1) - 1;

    vector<int> st(stSize, 0);
    // stMake(st, nums, 0, 0, n - 1);

    // dp and solve
    int ans = 0;
    FOR(n) {
        // find coordinate compressed value
        int ccVal = distance(ccMap.begin(), lower(ALL(ccMap), nums[i]));

        // find next answer and update the tree
        int dp = stFindMax(st, 0, 0, n - 1, 0, ccVal - 1) + 1;
        ans = max(dp, ans);
        stUpdate(st, 0, 0, n - 1, ccVal, dp);
    }

    cout << ans;

    return 0;
}
