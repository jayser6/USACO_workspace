#include <bits/stdc++.h>

#define pb push_back
#define ll long long

using namespace std;

vector<int> cows;
vector<vector<pair<int, ll>>> wormHoles;
vector<bool> visited;
ll smallestHole;

bool sortCows(ll holeLimit) { 
    visited.clear();
}

void DFS() {

}

int main() {
    ifstream fin("wormsort.in");
    ofstream fout("wormsort.out");

    int n, m;
    fin >> n >> m;

    bool noSort = true;
    
    for (int i = 0;i < n;i++) {
        int input; fin >> input;
        cows.pb(input - 1);
        visited.pb(false);
        if (cows.at(i) != i) {
            noSort = false;
        }
    }

    if (noSort) {
        fout << "-1";
        return 0;
    }

    for (int i = 0;i < n;i++) {
        wormHoles.pb({});
    }

    vector<ll> width(m);

    for (int i = 0;i < m;i++) {
        int a, b; ll w; fin >> a >> b >> w;
        wormHoles.at(a).pb(make_pair(b,w));
        wormHoles.at(b).pb(make_pair(a,w));
        width.at(i) = w;
    }

    sort(width.begin(), width.end());

    ll bsLow = 0, bsHigh = m, bsMid, output = 0;
    while (bsLow <= bsHigh) {
        bsMid = (bsLow + bsHigh) / 2;
        if (sortCows(width.at(bsMid))) {
            output = bsMid;
            bsLow = bsMid + 1;
        }
        else {
            bsHigh = bsMid - 1;
        }
    }

    fout << output;

}