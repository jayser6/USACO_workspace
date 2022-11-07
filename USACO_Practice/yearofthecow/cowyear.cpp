// started : 12/8/21
// finished: 12/11/21

#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second

using namespace std;

int main() {
    int n, k; cin >> n >> k;

    vector<ll> visitLocation(n + 1);
    visitLocation.at(0) = 0;
    for (int i = 1; i <= n;i++) {
        cin >> visitLocation.at(i);
    }
    sort(visitLocation.begin(), visitLocation.end());

    vector<ll> portalDistance(n);
    portalDistance.at(0) = visitLocation.at(1) / 12;
    for (int i = 1;i < n;i++) {
        portalDistance.at(i) = visitLocation.at(i + 1) / 12 - visitLocation.at(i) / 12 - 1;
        if (portalDistance.at(i) < 0) {
            portalDistance.at(i) = 0;
        }
    }
    sort(portalDistance.begin(), portalDistance.end());

    ll output = visitLocation.at(n) + (12 - visitLocation.at(n) % 12);
    for (int i = 1;i < k;i++) { // teleport k - 1 times, not including the inital tp all the way to the furthest past required
        output -= 12 * portalDistance.at(n - i);
    }

    cout << output;
}