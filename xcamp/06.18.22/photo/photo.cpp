/*____________________________________________________________
// started : 06/24/22
// finished: 06/24/22
// problem : http://www.usaco.org/index.php?page=viewproblem2&cpid=693
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

ifstream fin("bphoto.in");
ofstream fout("bphoto.out");

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

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.f > b.f;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; fin >> n;
    vector<pair<int, int>> cows(n);
    FOR(n) {
        fin >> cows[i].f;
        cows[i].s = i + 1;
    }
    sort(ALL(cows), cmp);

    vector<int> BITree(n + 1, 0);
    int output = 0;
    FOR(n) {
        int left = BITfindSum(BITree, cows[i].s);
        int right = i - left;
        if (max(left, right) > 2 * min(left, right)) {
            output++;
        }

        BITupdate(BITree, cows[i].s, 1);
    }

    fout << output;

    return 0;
}
