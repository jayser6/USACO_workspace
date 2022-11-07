#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <iterator>
using namespace std;

#define pb push_back

bool sortSongs(pair<int, int> a, pair<int, int> b) { // sorts songs based on beauty, descending
    return a.second > b.second;
}

struct SetComparator {
    bool operator() (pair<int, int> a, pair<int, int> b) const {
        return a.first > b.first;
    }
};

void solve() {
    int n, k; cin >> n >> k;

    vector<pair<int, int>> songs; // length, beauty
    for (int i = 0;i < n;i++) {
        int input1, input2; cin >> input1 >> input2;
        songs.pb(make_pair(input1, input2));
    }
    sort(songs.begin(), songs.end(), sortSongs);

    long long pleasure = 0;
    long long totalLength = 0;
    set<pair<int, int>> length;
    for (int i = 0;i < n;i++) {
        length.insert(make_pair(songs.at(i).first, i));
        totalLength += songs.at(i).first;
        if (length.size() > k) {
            totalLength -= length.begin()->first;
            length.erase(length.begin());
        }
        pleasure = max(pleasure, totalLength * songs.at(i).second);
    }
    cout << pleasure << endl;
    
}

int main() {
    int t; cin >> t;
    for (int i = 0;i < t;i++) {
        solve();
    }
}