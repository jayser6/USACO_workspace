// started : 12/4/21
// finished: 12/4/21

#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second

using namespace std;

int n, q;
string fence; // the fence is not 1-indexed while the pSum is, so be careful

void buildPSum(vector<int>& pSum) {
    stack<char> currentStrokes; 
    for (int i = 1; i < n + 1;i++) {
        pSum.at(i) = pSum.at(i - 1);
        while (!currentStrokes.empty() && (fence.at(i - 1) < currentStrokes.top())) {
            currentStrokes.pop();
        }
        if (currentStrokes.empty() || (fence.at(i - 1) > currentStrokes.top())) {
            currentStrokes.push(fence.at(i - 1));
            pSum.at(i)++;
        }
    }
}

int main() {
    cin >> n >> q >> fence;

    vector<int> pSumLR(n + 1);
    pSumLR.at(0) = 0;
    buildPSum(pSumLR);

    reverse(fence.begin(), fence.end());
    vector<int> pSumRL(n + 1);
    pSumRL.at(0) = 0;
    buildPSum(pSumRL);

    for (int i = 0;i < q;i++) {
        int a, b; cin >> a >> b;
        cout << (pSumLR.at(a - 1) + pSumRL.at(n - b)) << endl;
    }
}