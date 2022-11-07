// started : 01/21/22
// finished: 01/22/22
// Problem : No Time to Paint (USACO Silver) http://usaco.org/index.php?page=viewproblem2&cpid=1087

#include <bits/stdc++.h>

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

    int n, q;
    cin >> n >> q;

    string color; cin >> color;
    color = "!" + color + "!"; // 1-index the string from the front and the back

    vector<int> prefixSum(n + 2, 0), suffixSum(n + 2, 0);

    stack<char> overlap; // abcd b a
    for (int i = 1;i <= n;i++) {
        prefixSum[i] = prefixSum[i - 1];
        while (!overlap.empty() && overlap.top() > color[i]) {
            overlap.pop();
        }
        if (overlap.empty() || overlap.top() < color[i]) {
            overlap.push(color[i]);
            prefixSum[i]++;
        }
    }

    overlap = stack<char>(); // clear the stack
    for (int i = n;i >= 1;i--) {
        suffixSum[i] = suffixSum[i + 1];
        while (!overlap.empty() && overlap.top() > color[i]) {
            overlap.pop();
        }
        if (overlap.empty() || overlap.top() < color[i]) {
            overlap.push(color[i]);
            suffixSum[i]++;
        }
    }

    for (int i = 0;i < q;i++) {
        int a, b; cin >> a >> b;

        int output = prefixSum[a - 1] + suffixSum[b + 1];
        cout << output << endl;
    }
}
