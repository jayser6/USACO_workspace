#include <bits/stdc++.h>

#define ll long long
#define p push

using namespace std;

bool sortCows(pair<ll, ll> a, pair<ll, ll> b) {
    return a.second < b.second;
}

int main() {
    int n, m; cin >> n >> m;

    vector<pair<ll, ll>> milkPeriod(n);
    for (int i = 0;i < n;i++) {
        cin >> milkPeriod.at(i).first >> milkPeriod.at(i).second;
    }

    sort(milkPeriod.begin(), milkPeriod.end(), sortCows);

    int output = 0;
    multiset<ll> endTime;
    for (int i = 0;i < n;i++) {
        if (endTime.size() < m) {
            output++;
            endTime.insert(milkPeriod.at(i).second);
        }
        else {
            if (*endTime.begin() > milkPeriod.at(i).first) {
                continue;
            }
            else {
                auto it = endTime.upper_bound(milkPeriod.at(i).first);
                it--;
                //cout << milkPeriod.at(i).first << " " << *it << endl;
                endTime.erase(it);
                endTime.insert(milkPeriod.at(i).second);
                output++;
            }
        }
    }

    cout << output;
} 