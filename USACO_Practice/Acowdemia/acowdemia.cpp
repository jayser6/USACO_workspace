/*____________________________________________________________
// started : 06/12/22
// finished: 06/12/22
// problem : http://www.usaco.org/index.php?page=viewproblem2&cpid=1136&lang=en
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

// ifstream fin("acowdemia.in");

bool canWrite(vector<int>& papers, const int& k, const int& l, const int& h_index) {
    ll addNeeded = 0;
    int addCnt = 0;
    int maxDif = 0;
    const int n = papers.size();
    for (int i = n - 1;i >= n - h_index;i--) {
        if (papers[i] < h_index) {
            maxDif = max(maxDif, h_index - papers[i]);
            addNeeded += (h_index - papers[i]);
            addCnt++;
        }
    }

    if (addCnt > 0 && l == 0) {
        return false;
    }
    if (addCnt == 0) {
        return true;
    }
    if (addCnt <= l) {
        return maxDif <= k;
    }

    int numPapersNeeded;
    if (addNeeded % addCnt == 0) {
        numPapersNeeded = addNeeded / l;
    }
    else {
        numPapersNeeded = (addNeeded / l) + 1;
    }

    return max(numPapersNeeded, maxDif) <= k;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, l; cin >> n >> k >> l;
    vector<int> papers(n);
    for (int& paper : papers) {
        cin >> paper;
    }

    sort(ALL(papers));
    int ans = 0;
    int bsLow = 0, bsHigh = n;
    while (bsLow <= bsHigh) {
        int bsMid = (bsLow + bsHigh) / 2;

        if (canWrite(papers, k, l, bsMid)) {
            ans = bsMid;
            bsLow = bsMid + 1;
        }
        else {
            bsHigh = bsMid - 1;
        }
    }

    cout << ans;

    return 0;
}
