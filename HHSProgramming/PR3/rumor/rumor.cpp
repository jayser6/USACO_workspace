#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define pb push_back

struct Character {
    bool didHear;
    vector<int> friends;
    Character() {
        didHear = false;
    }
};

bool sortCost(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}

void DFS(int index, vector<Character>& characters) {
    characters.at(index).didHear = true;
    
    for (int i = 0;i < characters.at(index).friends.size();i++) {
        if (!characters.at(characters.at(index).friends.at(i)).didHear) {
            DFS(characters.at(index).friends.at(i), characters);
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> bribeCost; // first int for cost, second int for index(later, the vector gets sorted)
    for (int i = 0;i < n;i++) {
        int input; cin >> input;
        bribeCost.pb(make_pair(input, i));
    }

    vector<Character> characters(n);
    for (int i = 0;i < m;i++) {
        int input1, input2; cin >> input1 >> input2;
        characters.at(input1 - 1).friends.pb(input2 - 1);
        characters.at(input2 - 1).friends.pb(input1 - 1);
    }

    int totalCost = 0; // output
    for (int i = 0;i < n;i++) {
        if (characters.at(i).friends.size() == 0) {
            characters.at(i).didHear = true;
            totalCost += bribeCost.at(i).first;
        }
    }

    sort(bribeCost.begin(), bribeCost.end(), sortCost);
    for (int i = 0;i < n;i++) {
        if (!characters.at(bribeCost.at(i).second).didHear) {
            totalCost += bribeCost.at(i).first;
            DFS(bribeCost.at(i).second, characters);
        }
    }
    
    cout << totalCost << endl;
}

int main() {
    int a[5] = {0, 1, 2, 3, 4};

    int t;
    cin >> t;
    for (int i = 0;i < t;i++) {
        solve();
    }
}