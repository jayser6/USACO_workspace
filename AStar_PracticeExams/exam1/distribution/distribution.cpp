// THIS IS A GRAPH PROBLEM

#include <bits/stdc++.h>

#define pb push_back
#define ll long long

using namespace std;

int n;
vector<vector<int>> roads;
vector<ll> subtreeVal;

void DFS(int nodeIndex, int parentIndex) {
    for (int i = 0;i < roads.at(nodeIndex).size();i++) {
        if (roads.at(nodeIndex).at(i) != parentIndex) {
            DFS(roads.at(nodeIndex).at(i), nodeIndex);
            subtreeVal.at(nodeIndex) += subtreeVal.at(roads.at(nodeIndex).at(i));
        }
    }
}

int main() {
    cin >> n;

    for (int i = 0;i < n;i++) {
        int input; cin >> input;
        subtreeVal.pb(input);
        roads.pb({});
    }

    for (int i = 0;i < n - 1;i++) {
        int input1, input2; cin >> input1 >> input2;
        input1--;
        input2--;
        roads.at(input1).pb(input2);
        roads.at(input2).pb(input1);
    }

    DFS(0, -1); // -1 indicates that field 0 is the root of the tree

    vector<int> answer;
    ll minLoad = pow(10, 9); 

    for (int i = 0;i < n;i++) {
        ll maxCurLoad = 0;
        ll load;
        int nodeVal;
        for (int j = 0;j < roads.at(i).size();j++) {
            nodeVal = subtreeVal.at(roads.at(i).at(j));
            if (nodeVal > subtreeVal.at(i)) { // roads[i][j] is the parent of node i
                load = subtreeVal.at(0) - subtreeVal.at(i);
            }
            else { 
                load = nodeVal;
            }
            maxCurLoad = max(maxCurLoad, load);
        }
        if (maxCurLoad < minLoad) {
            minLoad = maxCurLoad;
            answer.clear();
            answer.pb(i + 1);
        }
        else if (maxCurLoad == minLoad) {
            answer.pb(i + 1);
        }
    }

    for (int i = 0;i < answer.size();i++) {
        cout << answer.at(i) << " ";
    }
}