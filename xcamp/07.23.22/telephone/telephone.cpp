/*____________________________________________________________
// started : 07/26/22
// finished: 07/27/22
// problem : http://www.usaco.org/index.php?page=viewproblem2&cpid=1090
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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k; cin >> n >> k;

    vector<vector<int>> eachK(k); // the indices of each element with value k
    vector<int> cows(n);
    FOR(n) {
        cin >> cows[i];
        cows[i]--;
        eachK[cows[i]].pb(i);
    }

    // building edges
    vector<vector<int>> edges(k);
    for (int i = 0;i < k;i++) {
        for (int j = 0;j < k;j++) {
            char in; cin >> in;
            if (in == '1') {
                edges[i].pb(j);
            }
        }
    }

    // use dijkstra to get from 0 to n - 1
    int finalK = cows[n - 1];
    vector<ll> distTo(n, BIG_NUMBER);
    p_queue< pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>> > dijkstra; // distance to, cow index

    dijkstra.push(mp(0, 0));
    distTo[0] = 0;
    while (!dijkstra.empty()) {
        pair<ll, int> curr = dijkstra.top();
        dijkstra.pop();
        if (curr.f > distTo[curr.s]) {
            continue;
        }

        // travel to the next nodes
        int currK = cows[curr.s];
        for (int destK : edges[currK]) {
            if (destK == finalK) {
                distTo[n - 1] = min(curr.f + (n - 1 - curr.s), distTo[n - 1]);
                continue;
            }
            else if (eachK[destK].empty()) {
                continue;
            }

            auto forward = upper(ALL(eachK[destK]), curr.s);
            auto backward = lower(ALL(eachK[destK]), curr.s);
            if (forward != eachK[destK].end()) {
                // go to the closest cow of type k in front of curr
                ll newDist = curr.f + (*forward - curr.s);
                if (newDist < distTo[*forward]) {
                    distTo[*forward] = newDist;
                    dijkstra.push({ newDist, *forward });
                }
            }
            if (backward != eachK[destK].begin()) {
                // go to the cloest cow of type k behind curr
                backward--;
                ll newDist = curr.f + (curr.s - *backward);
                if (newDist < distTo[*backward]) {
                    distTo[*backward] = newDist;
                    dijkstra.push({ newDist, *backward });
                }
            }
        }
    }

    if (distTo[n - 1] == BIG_NUMBER) {
        cout << "-1";
    }
    else {
        cout << distTo[n - 1];
    }

    return 0;
}
