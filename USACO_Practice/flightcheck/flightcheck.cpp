#include <bits/stdc++.h>

#define pb push_back

using namespace std;

vector<vector<int>> paths;
vector<vector<int>> reversePaths;
vector<int> canReach;

void DFS1(int cityIndex) {
    canReach.at(cityIndex) = true;
    for (int i = 0;i < paths.at(cityIndex).size();i++) {
        if (!canReach.at(paths.at(cityIndex).at(i))) {
            DFS1(paths.at(cityIndex).at(i));
        }
    }
}

void DFS2(int cityIndex) {
    canReach.at(cityIndex) = true;
    for (int i = 0;i < reversePaths.at(cityIndex).size();i++) {
        if (!canReach.at(reversePaths.at(cityIndex).at(i))) {
            DFS2(reversePaths.at(cityIndex).at(i));
        }
    }
}

int main() {
    // get n and m from input
    int n, m; cin >> n >> m;
    
    // set inital value for canReach, path, and reversePath vectors
    for (int i = 0;i < n;i++) {
        canReach.pb(false);
        paths.pb({});
        reversePaths.pb({});
    }

    // get paths from input
    for (int i = 0;i < m;i++) {
        int input1, input2; cin >> input1 >> input2;
        // 0-index the cities
        input1--;
        input2--;

        paths.at(input1).pb(input2);
        reversePaths.at(input2).pb(input1);
    }

    // check if city 1 can reach every city
    DFS1(0);
    for (int i = 0;i < n;i++) {
        if (!canReach.at(i)) {
            cout << "NO" << endl;
            cout << "1" << " " << (i + 1);
            return 0;
        }
        // reset the elements of the canReach vector
        canReach.at(i) = false;
    }

    // check if every city can reach city 1
    DFS2(0);
    for (int i = 1;i < n;i++) {
        if (!canReach.at(i)) {
            cout << "NO" << endl;
            cout << (i + 1) << " " << "1";
            return 0;
        }
    }

    // if the main function didn't quit already, all flight routes are possible
    cout << "YES";
}