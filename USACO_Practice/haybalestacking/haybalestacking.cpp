#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

#define pb push_back

int main() {
    int n, k; cin >> n >> k;
    
    vector<int> interval(n, 0);
    for (int i = 0;i < k;i++) {
        int in1, in2; cin >> in1 >> in2;
        interval.at(in1 - 1)++;
        interval.at(in2)--;
    }
    
    vector<int> stacks(n);
    for (int i = 0, currentHeight = 0;i < n;i++) {
        currentHeight += interval.at(i);
        stacks.at(i) = currentHeight;
    }
    sort(stacks.begin(), stacks.end());
    
    cout << stacks.at(n/2);
}