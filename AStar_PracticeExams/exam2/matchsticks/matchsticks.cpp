// started : 12/18/21
// finished: 12/18/21

#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second

using namespace std;

// input
int m, n;

// the nodes(joints) are 1-indexed
vector<vector<int>> path (1001); 
vector<int> nodeState (1001); // element: 0 -> node not yet checked, 1 -> node has all heads, 2 -> node has all tails

// all the matches
vector<pair<int, int>> matches (10000);

bool returnVal;

void dfs(int index, int direction, int a, int b) { // direction of the parent: 1 -> head, 2 -> tail 
    if (direction == 1) {
        nodeState.at(index) = 2;
    }
    else {
        nodeState.at(index) = 1;
    }

    for (int i = 0;i < path.at(index).size();i++) {
        int destination = path.at(index).at(i);

        // check if the particular match is removed
        if ((index == a || destination == a) && (index == b || destination == b)) {
            continue; 
        }

        // check if the node was already visited
        if (nodeState.at(destination) == 0) {
            //cout << "dfs going to: " << destination << endl;
            dfs(destination, nodeState.at(index), a, b);
        }
        else if (nodeState.at(destination) == nodeState.at(index)) {
            returnVal = false;
            return;
        }
    }
}

bool isBeautiful(int a, int b) { // a and b describes the path(match) that is being removed
    returnVal = true;
    fill(nodeState.begin(), nodeState.end(), 0);

    for (int i = 1; i <= n;i++) {
        if (nodeState.at(i) == 0) {
            //cout << "dfs starting at: " << i << endl;
            dfs(i, 1, a, b);
        }
    }

    return returnVal;
}

int main() {
    cin >> m >> n;

    // get the input
    for (int i = 0;i < m;i++) {
        cin >> matches.at(i).f >> matches.at(i).s; 

        path.at(matches.at(i).f).pb(matches.at(i).s);
        path.at(matches.at(i).s).pb(matches.at(i).f);
    }

    // first check if the artwork can be beautiful without removing any matchsticks
    if (isBeautiful(-1, -1)) {
        cout << "MOO";
        return 0;
    }

    // now check how many ways the artwork can become beautiful after removing one matchstick
    int output = 0;
    for (int i = 0;i < m;i++) {
        if (isBeautiful(matches.at(i).f, matches.at(i).s)) {
            output++;
        }
    }

    if (output == 0) {
        cout << "MOO MOO";
        return 0;
    }
    cout << output;
}