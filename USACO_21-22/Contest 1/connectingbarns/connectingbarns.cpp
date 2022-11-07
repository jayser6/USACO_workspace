// started : 12/19/21
// finished: 1/6/21

#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define mp make_pair
#define f first 
#define s second

using namespace std;

void solve() {
    int n, m; cin >> n >> m;

    vector<int> whichComp(n + 1, -1); // which component does barn i belong to?
    vector<vector<int>> edges(n + 1); // 1-index

    for (int i = 0;i < m;i++) {
        int a, b; cin >> a >> b;
        edges.at(a).pb(b);
        edges.at(b).pb(a);
    }

    // floodfill
    int compNumber = 0; // number of connected components
    for (int i = 1;i <= n;i++) {
        if (whichComp.at(i) == -1) {
            whichComp.at(i) = compNumber;

            stack<int> floodfill; 
            floodfill.push(i);
            while (!floodfill.empty()) {
                int index = floodfill.top();
                floodfill.pop();

                for (int destination : edges.at(index)) {
                    if (whichComp.at(destination) != compNumber) {
                        whichComp.at(destination) = compNumber;
                        floodfill.push(destination);
                    }
                }    
            }

            compNumber++;
        }
    }

    if (whichComp.at(1) == whichComp.at(n)) {
        cout << "0" << endl;
        return;
    }

    vector<vector<int>> connectedComps(compNumber);
    for (int i = 1;i <= n;i++) {
        connectedComps.at(whichComp.at(i)).pb(i);
    }

    int nComp = whichComp.at(n);

    ll costBefore;
    ll minCost = 1e12;

    // first try to directly connect component with barn 1 with component with barn n
    for (int i = 0;i < connectedComps.at(0).size();i++) {
        auto it = upper_bound(connectedComps.at(nComp).begin(), connectedComps.at(nComp).end(), connectedComps.at(0).at(i));
        int dist = n + 1;
        if (it != connectedComps.at(nComp).end()) {
            dist = min(dist, *it - connectedComps.at(0).at(i));
        } 
        if (it != connectedComps.at(nComp).begin()) {
            dist = min(dist, connectedComps.at(0).at(i) - *(it - 1));
        }

        if (dist % 2 == 0) {
            minCost = min(minCost, 2 * (ll)(dist / 2) * (dist/2));
        }
        else {
            minCost = min(minCost, (ll)(dist / 2) * (dist / 2) + (ll)(dist / 2 + 1)) * (dist / 2 + 1);
        }
    }

    costBefore = minCost;

    // now try to connect the component with barn 1 and component with barn n via another component
    for (int i = 1;i < compNumber;i++) {
        if (i == nComp) {
            continue;
        }

        int dist1 = n + 1, dist2 = n + 1;

        for (int node : connectedComps.at(i)) {
            auto it1 = upper_bound(connectedComps.at(0).begin(), connectedComps.at(0).end(), node);
            if (it1 != connectedComps.at(0).end()) {
                dist1 = min(dist1, *it1 - node);
            }
            if (it1 != connectedComps.at(0).begin()) {
                dist1 = min(dist1, node - *(it1 - 1));
            }

            auto it2 = upper_bound(connectedComps.at(nComp).begin(), connectedComps.at(nComp).end(), node);
            if (it2 != connectedComps.at(nComp).end()) {
                dist2 = min(dist2, *it2 - node);
            }
            if (it2 != connectedComps.at(nComp).begin()) {
                dist2 = min(dist2, node - *(it2 - 1));
            }
        }

        minCost = min(minCost, (ll)dist1 * dist1 + (ll)dist2 *  dist2);
    }

    cout << minCost << endl;
}

int main() {
    int t; cin >> t;

    for (int i = 0;i < t;i++) {
        solve();
    }
}