// started : 12/01/21
// finished: 12/13/21

#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second

using namespace std;

bool cmd(pair<ll, ll> a, pair<ll, ll> b) {
    return a.s < b.s;
}

int main() {
    int n; cin >> n;

    vector<pair<ll, ll>> cowPos(n);
    for (int i = 0;i < n;i++) {
        cin >> cowPos.at(i).first >> cowPos.at(i).second;
    }

    // compress the y-values
    sort(cowPos.begin(), cowPos.end(), cmd);
    for (int i = 0;i < n;i++) {
        cowPos.at(i).s = i + 1; // 1-index the values for pre-sum
    }

    // compress the x-values
    sort(cowPos.begin(), cowPos.end());
    for (int i = 0;i < n;i++) {
        cowPos.at(i).f = i + 1; // 1-index the values for pre-sum
    }
    
    vector<vector<int>> pasture (n + 1, vector<int> (n + 1, 0));
    for (int i = 0;i < n;i++) {
        pasture.at(cowPos.at(i).s).at(cowPos.at(i).f) = 1; 
    }

    vector<vector<int>> pSum (n + 1, vector<int> (n + 1, 0));
    for (int i = 1; i < n + 1;i++) {
        for (int j = 1; j < n + 1;j++) {
            pSum.at(i).at(j) = pSum.at(i - 1).at(j) + pSum.at(i).at(j - 1) - pSum.at(i - 1).at(j - 1) + pasture.at(i).at(j); 
        }
    } 

    ll answer = n + 1;

    for (int i = 0;i < n;i++) {
        for (int j = i + 1;j < n;j++) {
            int rectLow = min(cowPos.at(i).s, cowPos.at(j).s);
            int rectHigh = max(cowPos.at(i).s, cowPos.at(j).s);
            int rectRight = cowPos.at(j).f; 
            int rectLeft = cowPos.at(i).f;

            int cowsBelow = pSum.at(rectLow).at(rectRight) - pSum.at(rectLow).at(rectLeft - 1);
            int cowsAbove = pSum.at(n).at(rectRight) - pSum.at(n).at(rectLeft - 1) - pSum.at(rectHigh - 1).at(rectRight) 
                            + pSum.at(rectHigh - 1).at(rectLeft - 1);

            answer += cowsAbove * cowsBelow;
        }
    }

    cout << answer;

}