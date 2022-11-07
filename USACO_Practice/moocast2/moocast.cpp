#include <bits/stdc++.h>

#define pb push_back
#define ll long long

using namespace std;

vector<pair<int, int>> cowCoord;
vector<bool> didReachCow;
vector<vector<int>> cowConnect;

void DFS(int cowIndex) {
    didReachCow.at(cowIndex) = true;
    for (int i = 0;i < cowConnect.at(cowIndex).size();i++) {
        if (!didReachCow.at(cowConnect.at(cowIndex).at(i))) {
            DFS(cowConnect.at(cowIndex).at(i));
        }
    }
}

bool canReach(ll x) {
    // set up vectors for the DFS
    for (int i = 0;i < didReachCow.size();i++) {
        didReachCow.at(i) = false;
        cowConnect.at(i).clear();
        for (int j = 0;j < cowConnect.size();j++) {
            if (j == i) {
                continue;
            }
            int deltaX = abs(cowCoord.at(i).first - cowCoord.at(j).first);
            int deltaY = abs(cowCoord.at(i).second - cowCoord.at(j).second);
            ll distance = (deltaY * deltaY) + (deltaX * deltaX);
            if (distance <= x) {
                cowConnect.at(i).pb(j);
            }
        }
    }

    DFS(0);

    for (int i = 0;i < didReachCow.size();i++) {
        if (!didReachCow.at(i)) {
            return false;
        }
    }
    return true;
}

int main() {
    ifstream fin("moocast.in");
    ofstream fout("moocast.out");

    int n; fin >> n;

    for (int i = 0;i < n;i++) {
        int x, y; fin >> x >> y;
        cowCoord.pb(make_pair(x, y));
        didReachCow.pb(false);
        cowConnect.pb({});
    }

    ll bsLow = 0, bsHigh = pow(25000, 2) * 2 + 1, bsMid, lowestX = bsHigh;
    while (bsLow <= bsHigh) {
        bsMid = (bsLow + bsHigh) / 2;
        if (canReach(bsMid)) {
            lowestX = bsMid;
            bsHigh = bsMid - 1;
        }
        else {
            bsLow = bsMid + 1;
        }
    }
    fout << lowestX;
}
