// started : 02/12/22
// finished: 02/12/22
// problem : http://www.usaco.org/index.php?page=viewproblem2&cpid=1038

#include <bits/stdc++.h>

#define ALL(arr) arr.begin(), arr.end()
#define hashmap unordered_map
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl "\n"

using namespace std;

bool canCowsDistance(int n, ll d, vector<pair<ll, ll>> grass) {
    ll currentLocation = grass.at(0).f;
    
    for (int i = 0, j = 0;i < n;i++) {
        while(grass.at(j).s < currentLocation + d && i != n - 1) {
            j++;
            if (j >= (int)grass.size()) {
                return false;
            }
        }

        currentLocation = max(currentLocation + d, grass.at(j).f);
    }

    return true;
}

int main() {
    int n, m; cin >> n >> m;

    vector<pair<ll, ll>> grass(m);
    for (int i = 0;i < m;i++) {
        cin >> grass.at(i).f >> grass.at(i).s;
    }
    sort(ALL(grass));

    ll maxD = -1, bsLow = 0, bsHigh = grass.at(m - 1).s, bsMid;
    while(bsLow <= bsHigh) {
        bsMid = (bsHigh + bsLow) / 2;
        if (canCowsDistance(n, bsMid, grass)) {
            maxD = bsMid;
            bsLow = bsMid + 1;
        }
        else {
            bsHigh = bsMid - 1;
        }
    }

    cout << maxD;
}
