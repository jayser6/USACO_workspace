// started : 02/12/22
// finished: 02/13/22
// problem : https://codeforces.com/contest/702/problem/C

#include <bits/stdc++.h>

#define ALL(arr) arr.begin(), arr.end()
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl "\n"

using namespace std;

int n, m;
vector<ll> cities;
vector<ll> towers;

bool canPower(ll r) {
    int cityIndex = 0;

    for (int i = 0;i < m;i++) {
        ll leftBound = towers[i] - r;
        ll rightBound = towers[i] + r;

        while (cityIndex < n && cities[cityIndex] >= leftBound && cities[cityIndex] <= rightBound) {
            cityIndex++;
        }
    }

    if (cityIndex < n) {
        return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    cities = vector<ll>(n);
    towers = vector<ll>(m);

    for (int i = 0;i < n;i++) {
        cin >> cities[i];
    }

    for (int i = 0;i < m;i++) {
        cin >> towers[i];
    }

    sort(ALL(cities));
    sort(ALL(towers));

    ll bsLow = 0, bsHigh = (ll)pow(10, 12);
    ll minR = -1;
    while (bsLow <= bsHigh) {
        ll bsMid = (bsHigh + bsLow) / 2;

        if (canPower(bsMid)) {
            minR = bsMid;
            bsHigh = bsMid - 1;
        }
        else {
            bsLow = bsMid + 1;
        }
    }

    cout << minR;
}
