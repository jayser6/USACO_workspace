#include <iostream>
#include <vector>
#include <algorithm>

#define pb push_back

using namespace std;  

int main() {
    int n; cin >> n;

    vector<pair<int, int>> tasks;
    for (int i = 0;i < n;i++) {
        int input1, input2; cin >> input1 >> input2;
        tasks.pb(make_pair(input1, input2));
    }

    sort(tasks.begin(), tasks.end());

    long long time = 0, reward = 0;
    for (int i = 0;i < n;i++) {
        time += tasks.at(i).first;
        reward += tasks.at(i).second - time;
    }

    cout << reward;
}