// started : 02/16/22
// finished: 02/16/22

#include <bits/stdc++.h>

#define ALL(arr) arr.begin(), arr.end()
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl "\n"

using namespace std;

void solve(int caseNum) {
    int n; cin >> n;

    vector<int> answers;
    multiset<int> papers;
    int currAns = 0;
    for (int i = 1;i <= n;i++) {
        int c_i; cin >> c_i;

        papers.insert(c_i);

        while((distance(papers.lower_bound(currAns + 1), papers.end()) >= currAns + 1) && (currAns + 1 <= i)) {
            currAns++;
        }

        answers.pb(currAns);
    }

    cout << "Case #" << caseNum << ": ";
    for (int i = 0;i < (int)answers.size();i++) {
        cout << answers[i] << " ";
    }
    cout << endl;
}

int main() {
    int t; cin >> t;

    for (int i = 0;i < t;i++) {
        solve(i + 1);
    }
}
