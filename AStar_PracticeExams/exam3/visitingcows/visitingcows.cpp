// started : 12/26/21
// finished: 12/26/21

#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second

using namespace std;

int main() {
    int n, m, k, p; cin >> n >> m >> k >> p;

    vector<int> cows(k);
    for (int i = 0;i < k;i++) {
        cin >> cows.at(i);
    }

    vector<vector<int>> paths(n + 1);
    vector<vector<int>> reversePaths(n + 1);
    for (int i = 0;i < m;i++) {
        int a, b; cin >> a >> b;
        paths.at(a).pb(b);
        reversePaths.at(b).pb(a);
    }

    // calculate how long it takes each cow to get to a pasture
    vector<vector<int>> distance(k, vector<int>(n + 1, -1)); // how long it takes ith cow to visit jth pasture
    for (int i = 0;i < k;i++) {
        queue<pair<int, int>> bfs; // stores pasture location, distance
        bfs.push(mp(cows.at(i), 0));

        while (!bfs.empty()) {
            int pastureIndex = bfs.front().f;
            int currentDistance = bfs.front().s;
            bfs.pop();

            if (distance.at(i).at(pastureIndex) != -1) {
                continue;
            }

            distance.at(i).at(pastureIndex) = currentDistance;

            for (int j = 0;j < paths.at(pastureIndex).size();j++) {
                int toIndex = paths.at(pastureIndex).at(j);
                if (distance.at(i).at(toIndex) == -1) {
                    bfs.push(mp(toIndex, currentDistance + 1));
                }
            }
        }
    }
    // calculate how long it takes FJ to get to each pasture
    vector<int> FJto(n + 1, -1);

    queue<pair<int, int>> bfs; // stores pasture location, distance
    bfs.push(mp(1, 0));

    while (!bfs.empty()) {
        int pastureIndex = bfs.front().f;
        int currentDistance = bfs.front().s;
        bfs.pop();

        if (FJto.at(pastureIndex) != -1) {
            continue;
        }

        FJto.at(pastureIndex) = currentDistance;

        for (int j = 0;j < paths.at(pastureIndex).size();j++) {
            int toIndex = paths.at(pastureIndex).at(j);
            if (FJto.at(toIndex) == -1) {
                bfs.push(mp(toIndex, currentDistance + 1));
            }
        }
    }

    // calculate how long it takes FJ to return home from each pasture
    vector<int> FJfrom(n + 1, -1);

    bfs.push(mp(1, 0));
    while (!bfs.empty()) {
        int pastureIndex = bfs.front().f;
        int currentDistance = bfs.front().s;
        bfs.pop();

        if(FJfrom.at(pastureIndex) != -1) {
            continue;
        }

        FJfrom.at(pastureIndex) = currentDistance;

        for (int j = 0;j < reversePaths.at(pastureIndex).size();j++) {
            int toIndex = reversePaths.at(pastureIndex).at(j);
            if (FJfrom.at(toIndex) == -1) {
                bfs.push(mp(toIndex, currentDistance + 1));
            }
        }
    }

    // for (int i = 1;i <= n;i++) {
    //     cout << "it takes FJ " << FJfrom.at(i) << " moves to get to pasture " << i << endl;
    // }

    // find min total distance
    ll output = -1;
    for (int i = 2;i <= n;i++) {
        if (FJfrom.at(i) == -1 || FJto.at(i) == -1) {
            continue;
        }

        ll totalDistance = static_cast<ll>(FJfrom.at(i) + FJto.at(i)) * p;
        bool noBueno = false;
        for (int j = 0;j < k;j++) {
            if (distance.at(j).at(i) == -1) {
                noBueno = true;
                continue;
            }
            totalDistance += (distance.at(j).at(i));
        }

        if (noBueno) {
            continue;
        }

        if (output == -1 || totalDistance < output) {
            output = totalDistance;
        }
    }

    if (output == -1) {
        cout << "Impossible";
    }
    else {
        cout << output;
    }
}
