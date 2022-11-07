// started : 01/11/22
// finished: 01/16/22

#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define f first
#define s second

using namespace std;

int main() {
    int n; cin >> n;

    vector<pair<ll, ll>> friends(n); // position, speed
    for (int i = 0;i < n;i++) {
        cin >> friends[i].f;
    }
    for (int i = 0;i < n;i++) {
        cin >> friends[i].s;
    }

    sort(friends.begin(), friends.end());

    ld bsLow = 0.0, bsHigh = friends[n - 1].f + 0.0;

    ld answer = (ld)pow(10, 9); 

    while (bsLow <= bsHigh) {
        ld bsMid = (bsLow + bsHigh) / 2;

        ld lowestR = -1;
        ld largestL = friends[n - 1].f + 1.0;
        for (int i = 0;i < n;i++) {
            ld leftBound = friends[i].f - friends[i].s * bsMid; 
            ld rightBound = friends[i].f + friends[i].s * bsMid;
            if (lowestR == -1 || rightBound < lowestR) {
                lowestR = rightBound; 
            }
            if (largestL == friends[n - 1].f + 1.0 || leftBound > largestL) {
                largestL = leftBound;
            }
        }

        if (lowestR >= largestL) { // bueno
            answer = bsMid; 
            bsHigh = bsMid - 0.000001;
        }   
        else { // no bueno
            bsLow = bsMid + 0.000001;
        }
    }

    cout << fixed << setprecision(8) << answer;
}