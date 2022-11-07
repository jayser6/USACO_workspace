// started : 01/28/22
// finished: 02/28/22
// problem : http://www.usaco.org/index.php?page=viewproblem2&cpid=1183

#include <bits/stdc++.h>

#define ALL(arr) arr.begin(), arr.end()
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl "\n"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    
    vector<int> heights(n);
    for (int i = 0;i < n;i++) {
        cin >> heights[i];
    }

    ll ans = 0;
    stack<pair<int, int>> prevCow; // height, index
    for (int i = 0;i < n;i++) {
        while (!prevCow.empty()) {
            int topHeight = prevCow.top().f; 
            int topIndex = prevCow.top().s;

            ans += (i - topIndex + 1);

            if (topHeight < heights[i]) {
                prevCow.pop();
            }
            else {
                break;
            }
        }
        prevCow.push(mp(heights[i], i));
    }

    cout << ans;
}
