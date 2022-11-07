#include <bits/stdc++.h>

#define ll long long

using namespace std;

bool customSort(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) {
        return a.first > b.first; 
    }
    return a.second > b.second; 
}

int main() {
    ifstream fin("reststops.in");
    ofstream fout("reststops.out");

    int l, n, rF, rB; fin >> l >> n >> rF >> rB;

    vector<pair<int, int>> stops(n); // position, taste
    for (int i = 0;i < n;i++) {
        fin >> stops.at(i).first >> stops.at(i).second;
    }

    sort(stops.begin(), stops.end(), customSort);

    ll taste = 0;
    int from = 0; // position of the current reststop(or starting poisiton)
    for (int i = 0;i < n;i++) {
        int to = stops.at(i).first; // position of the next reststop
        if (to <= from) { // there is a tasiter reststop after(in terms of displacement) the current reststop
            continue;
        }
        taste += static_cast<ll>(rF - rB) * (to - from) * stops.at(i).second;
        from = to;
    }

    fout << taste; 
}