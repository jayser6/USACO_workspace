// started : 12/15/21
// finished: 12/30/21

#include <bits/stdc++.h>

#define ll long long
#define hashmap unordered_map
#define pb push_back
#define mp make_pair
#define f first
#define s second

using namespace std;

int main() {
    int n; cin >> n;
    
    if (n == 1) {
        cout << "0";
        return 0;
    }

    vector<pair<ll, char>> plants(n);
    for (int i = 0;i < n;i++) {
        cin >> plants.at(i).f >> plants.at(i).s;
    }

    sort(plants.begin(), plants.end());

    // find the longest area Bessie can eat to the left(and maybe including) i
    vector<pair<ll, int>> currLengthL(n); // stores the length and the index that the partition starts on
    vector<ll> longestLeft(n);
    hashmap<int, int> earliestpSum; // pSum value, earliest index the value was seen
    earliestpSum.insert(mp(0, -1));

    char before = 'C';
    ll longestBef = 0;
    for (int i = 0, sum = 0, cnt = 0;i < n;i++) {
        // check if the plant is contiguous to the plant(s) before
        if (before == plants.at(i).s) {
            cnt++;
        }
        else {
            cnt = 0;
            before = plants.at(i).s;
        }

        // update psum value
        if (plants.at(i).s == 'A') {
            sum++;
        }
        else {
            sum--;
        }

        int indexEnd1 = 300000, indexEnd2 = i - cnt;
        // calculate contiguous length and balanced(in a and b) length
        ll contLength = plants.at(i).f - plants.at(i - cnt).f;
        ll balLength = -1;
        if (earliestpSum.find(sum) != earliestpSum.end()) { // there is a balance between key and i
            balLength = plants.at(i).f - plants.at(earliestpSum.find(sum)->s + 1).f;
            indexEnd1 = earliestpSum.find(sum)->s + 1;
        }
        else { // this is the earliest occurance of such sum
            earliestpSum.insert(mp(sum, i));
        }

        // compare current length to max length and assign value to longestLeft
        currLengthL.at(i).f = max(balLength, contLength);
        currLengthL.at(i).s = min(indexEnd1, indexEnd2);
        longestBef = max(longestBef, currLengthL.at(i).f);
        if (i < n - 1) {
            longestLeft.at(i + 1) = longestBef;
        }
    }

    // calculate the longest area starting from plant i and the longest area to the right of a(possibly starting at i)
    vector<pair<ll, int>> currLengthR(n); // actual length, the end index of the partition
    vector<ll> longestRight(n);
    hashmap<int, int> latestpSum;
    latestpSum.insert(mp(0, n));

    char after = 'C';
    ll longestAfter = 0;
    for (int i = n - 1, sum = 0, cnt = 0;i >= 0;i--) {
        if (after == plants.at(i).s) {
            cnt++;
        }
        else {
            cnt = 0;
            after = plants.at(i).s;
        }

        if (plants.at(i).s == 'A') {
            sum++;
        }
        else {
            sum--;
        }

        int indexEnd1 = -1, indexEnd2 = i + cnt;
        ll contLength = plants.at(i + cnt).f - plants.at(i).f;
        ll balLength = -1;
        if (latestpSum.find(sum) != latestpSum.end()) {
            balLength = plants.at(latestpSum.find(sum)->s - 1).f - plants.at(i).f;
            indexEnd1 = latestpSum.find(sum)->s - 1;
        }
        else {
            latestpSum.insert(mp(sum, i));
        }

        currLengthR.at(i).s = max(indexEnd1, indexEnd2);
        currLengthR.at(i).f = max(balLength, contLength);
        longestAfter = max(longestAfter, currLengthR.at(i).f);
        if (i > 0) {
            longestRight.at(i - 1) = longestAfter;
        }
    }

    ll maxLength = 0;
    for (int i = 0;i < n;i++) {
        ll maxCurrLength;
        if (i == 0) { 
            // leftmost plant therefore doesnt have longestLeft.at(i - 1)
            maxCurrLength = longestRight.at(currLengthR.at(i).s) + currLengthR.at(i).f;

            // check for the case that e1 and s2 are next to each other in index
            ll otherLength = -1;
            int nextIndex = currLengthR.at(i).s + 1;
            if (nextIndex < n) {
                otherLength = plants.at(nextIndex).f - plants.at(i).f + currLengthR.at(nextIndex).f;
            }
            maxCurrLength = max(maxCurrLength, otherLength);
        }
        else if (i == n - 1) {
            // rightmost plant therefore doesn't have longestRight.at(i + 1)
            maxCurrLength = longestLeft.at(currLengthL.at(i).s) + currLengthR.at(i).f;

            ll otherLength = -1;
            int nextIndex = currLengthL.at(i).s - 1;
            if (nextIndex >= 0) {
                otherLength = plants.at(i).f - plants.at(nextIndex).f + currLengthL.at(nextIndex).f;
            }

            maxCurrLength = max(maxCurrLength, otherLength);
        }
        else {
            // any plant in between leftmost and rightmost plants
            maxCurrLength = max(longestLeft.at(currLengthL.at(i).s), longestRight.at(currLengthR.at(i).s)) 
                            + currLengthR.at(i).f;

            ll otherLength = -1;
            int nextIndex = currLengthR.at(i).s + 1;
            if (nextIndex < n) {
                otherLength = plants.at(nextIndex).f - plants.at(i).f + currLengthR.at(nextIndex).f;
            }

            maxCurrLength = max(maxCurrLength, otherLength);

            otherLength = -1;
            nextIndex = currLengthL.at(i).s - 1;
            if (nextIndex >= 0) {
                otherLength = plants.at(i).f - plants.at(nextIndex).f + currLengthL.at(nextIndex).f;
            }

            maxCurrLength = max(maxCurrLength, otherLength);
        }
        maxLength = max(maxCurrLength, maxLength);
    }

    cout << maxLength;
}