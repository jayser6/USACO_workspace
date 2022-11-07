// started : 12/19/21
// finished: 12/29/21

#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second

using namespace std;

int main() {
    int k, m, n; cin >> k >> m >> n;
    
    vector<pair<ll, ll>> position; // position.s = -1 means that there is a cow on that position, not a patch
    for (int i = 0;i < k;i++) {
        ll input1, input2; cin >> input1 >> input2;
        position.pb(mp(input1, input2));
    }
    for (int i = 0;i < m;i++) {
        ll input; cin >> input;
        position.pb(mp(input, -1));
    }

    sort(position.begin(), position.end());

    // divide the numberline into partitions who's endpoints are FN's cows
    vector<ll> tastePerCow; // max taste one cow can get within a partition
    int leftBound = -1;
    ll totalTaste = 0;
    for (int i = 0;i < m + k;i++) {
        if ((position.at(i).s == -1)) {
            if (i == 0 && leftBound == -1) { // the leftmost element is a cow, not a patch
                leftBound = 0;
                continue;
            }
            else if (leftBound == -1) {
                tastePerCow.pb(totalTaste);
                leftBound = i;
                totalTaste = 0;
                continue;
            }

            // calculate the max taste value a single cow can take within the partition
            ll currentTaste = 0, maxTaste = -1;
            ll totalLength = 0;
            if (leftBound == -1) {
                totalLength = position.at(i).f;
            }
            else {
                totalLength = position.at(i).f - position.at(leftBound).f; 
            }
            for (int start = leftBound + 1, end = leftBound;start < i;start++) {
                while ((end + 1 < i) && (2 * (position.at(end + 1).f - position.at(start).f) < totalLength)) {
                    currentTaste += position.at(++end).s;
                }
                maxTaste = max(maxTaste, currentTaste);
                currentTaste -= position.at(start).s;
            }

            // cout << "max taste: " << maxTaste << ", " << "total taste: " << totalTaste << endl;

            // push back max tastiness from one cow and the remaining tastiness value from the remaining cows
            tastePerCow.pb(maxTaste);
            tastePerCow.pb(totalTaste - maxTaste);

            // update variables for next partition
            totalTaste = 0;
            leftBound = i;
        }
        else {
            totalTaste += position.at(i).s;
            if (i == m + k - 1) {
                tastePerCow.pb(totalTaste);
            }
        }
    }

    // for (int i = 0;i < tastePerCow.size();i++) {
    //     cout << tastePerCow.at(i) << endl;
    // }

    sort(tastePerCow.begin(), tastePerCow.end());

    ll output = 0;
    for (int i = 0;i < n;i++) {
        output += tastePerCow.at(tastePerCow.size() - 1 - i);
    }

    cout << output;
}