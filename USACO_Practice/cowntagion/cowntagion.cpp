#include <bits/stdc++.h>

#define ll long long
#define pb push_back

using namespace std;

int n;
int output = 0;
vector<vector<int>> roads;
const int A_SIZE = 18;
int a[A_SIZE]; // these are the powers of 2

void DFS(int farmIndex, int parentIndex) {
    int roadCount = 0;
    int doubleCount = 0;
    for (int i = 0;i < roads.at(farmIndex).size();i++) {
        if (roads.at(farmIndex).at(i) != parentIndex) {
            roadCount++;
            DFS(roads.at(farmIndex).at(i), farmIndex);
        }
    }
    if (roadCount == 0) {
        //cout << "viruses in farm" << " " << (farmIndex + 1) << " have nowhere else to go" << endl;
        return;
    }
    doubleCount = (upper_bound(a, a + A_SIZE, roadCount) - a);
    //cout << "farm " << (farmIndex + 1) << ": number of times doubled: " << doubleCount << ", number of times traveled: " << roadCount << endl;
    output += roadCount + doubleCount;
}

int main() {
    //ifstream fin("cowntagion.in");

    cin >> n;

    for (int i = 0;i < n;i++) {
        roads.pb({});
    }

    for (int i = 0;i < n - 1;i++) {
        int input1, input2; cin >> input1 >> input2;
        input1--;
        input2--;
        roads.at(input1).pb(input2);
        roads.at(input2).pb(input1);
    }

    for (int i = 0;i < A_SIZE;i++) {
        a[i] = pow(2, i);
    }

    // DFS the tree, the root being farm = 1
    DFS(0, -1);

    cout << output;
}