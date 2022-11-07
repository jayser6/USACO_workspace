// started : 01/24/22
// finished: 01/24/22
// problem : Dance Moves (USACO Silver) http://usaco.org/index.php?page=viewproblem2&cpid=1086

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

    int n, k; cin >> n >> k;

    vector<int> firstK(n); // key: position index, element: cow index
    vector<unordered_set<int>> cowVisit(n); // key: cow index, set: all the positions that cow i visited
    for (int i = 0; i < n; i++) {
        firstK[i] = i; // each cow i starts at position i
        cowVisit[i].insert(i); // each cow visits its own starting position i
    }

    for (int i = 0;i < k;i++) {
        int a, b; cin >> a >> b;
        a--; b--;

        int cowA = firstK[a];
        int cowB = firstK[b];

        cowVisit[cowA].insert(b);
        cowVisit[cowB].insert(a);

        firstK[a] = cowB;
        firstK[b] = cowA;
    }

    vector<int> compNum(n, -1); // the component number of location i
    vector<unordered_set<int>> compAns; // all the visited location of compoennt i
    int currentComp = 0;
    for (int position = 0;position < n;position++) {
        if (compNum[position] == -1) {
            compAns.pb({});

            // DFS
            stack<int> DFS;
            bool isCycle = false;
            DFS.push(position);
            while (!DFS.empty()) {
                if (isCycle && position == DFS.top()) {
                    break;
                }
                isCycle = true;
                int currPos = DFS.top();
                DFS.pop();

                compNum[currPos] = currentComp;
                compAns[currentComp].insert(ALL(cowVisit[firstK[currPos]]));
                DFS.push(firstK[currPos]);
            }

            currentComp++;
        }
    }

    for (int i = 0;i < n;i++) {
        cout << compAns[compNum[i]].size() << endl;
    }
}
