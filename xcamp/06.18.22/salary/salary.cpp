/*____________________________________________________________
// started : 06/23/22
// finished: 06/23/22
// problem : https://cses.fi/problemset/task/1144
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

void update(vector<ll>& BITree, int index, int val) {
    while (index < BITree.size()) {
        BITree[index] += val;
        index += index & -index;
    }
}

ll findSum(vector<ll>& BITree, int index) {
    ll sum = 0;
    while (index > 0) {
        sum += BITree[index];
        index -= index & -index;
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // take input and coordinate compress in advance
    int n, q; cin >> n >> q;
    vector<int> salary(n + 1);
    set<int> ccS;
    ccS.insert(0); // for 1-indexing the cc
    FORO(n + 1) {
        cin >> salary[i];
        ccS.insert(salary[i]);
    }

    vector<pair<char, pair<int, int>>> queries(q);
    for (auto& curr : queries) {
        cin >> curr.f >> curr.s.f >> curr.s.s;
        if (curr.f == '!') {
            ccS.insert(curr.s.s);
        }
    }

    vector<int> cc;
    for (int curr : ccS) {
        cc.pb(curr);
    }

    // make BITree
    vector<ll> BITree(cc.size(), 0);
    for (int curr : salary) {
        if (curr == 0) continue;
        int ccval = distance(cc.begin(), lower(ALL(cc), curr));
        update(BITree, ccval, 1);
    }

    bool empty = true;

    // solve
    for (auto currQ : queries) {
        if (currQ.f == '!') {
            int ccval = distance(cc.begin(), lower(ALL(cc), salary[currQ.s.f]));
            update(BITree, ccval, -1);

            salary[currQ.s.f] = currQ.s.s;
            ccval = distance(cc.begin(), lower(ALL(cc), currQ.s.s));
            update(BITree, ccval, 1);
        }
        else {
            empty = false;
            int a = distance(cc.begin(), lower(ALL(cc), currQ.s.f));
            int b = distance(cc.begin(), upper(ALL(cc), currQ.s.s) - 1);
            cout << (findSum(BITree, b) - findSum(BITree, a - 1)) << endl;
        }
    }

    return 0;
}
