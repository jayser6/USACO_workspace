#include <bits/stdc++.h>

#define ll long long
#define pb push_back

using namespace std;

vector<pair<ll, ll>> cowPos;
vector<vector<int>> mooNet;
vector<bool> visited;

ll minX, maxX, minY, maxY;

void floodFill(int cowIndex) {
    visited.at(cowIndex) = true;

    if (cowPos.at(cowIndex).first > maxX) {
        maxX = cowPos.at(cowIndex).first;
    }
    if (cowPos.at(cowIndex).first < minX) {
        minX = cowPos.at(cowIndex).first;
    }
    if (cowPos.at(cowIndex).second > maxY) {
        maxY = cowPos.at(cowIndex).second;
    }
    if (cowPos.at(cowIndex).second < minY) {
        minY = cowPos.at(cowIndex).second;
    }

    for (int i = 0;i < mooNet.at(cowIndex).size();i++) {
        if (!visited.at(mooNet.at(cowIndex).at(i))) {
            floodFill(mooNet.at(cowIndex).at(i));
        }
    }
}

int main() {
    ifstream fin ("fenceplan.in");
    ofstream fout ("fenceplan.out");

    int n, m; fin >> n >> m;

    for (int i = 0;i < n;i++) {
        ll input1, input2; fin >> input1 >> input2;
        cowPos.pb(make_pair(input1, input2));
        visited.pb(false);
        mooNet.pb({});
    }

    for (int i = 0;i < m;i++) {
        int input1, input2; fin >> input1 >> input2;
        mooNet.at(input1 - 1).pb(input2 - 1);
        mooNet.at(input2 - 1).pb(input1 - 1);
    }

    ll minPerimeter = pow(10, 9);
    for (int i = 0;i < n;i++) {
        if (!visited.at(i)) {
            minX = pow(10, 8) + 1, minY = pow(10, 8) + 1, maxX = 0, maxY = 0;
            floodFill(i);;
            if ((2 * (maxX - minX)) + (2 * (maxY - minY)) < minPerimeter) {
                minPerimeter = (2 * (maxX - minX)) + (2 * (maxY - minY));
            }
        }
     }

     fout << minPerimeter;
}