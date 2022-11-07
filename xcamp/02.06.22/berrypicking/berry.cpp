// started : 02/13/22
// finished: 02/13/22
// problem : http://www.usaco.org/index.php?page=viewproblem2&cpid=990

#include <bits/stdc++.h>

#define ALL(arr) arr.begin(), arr.end()
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl "\n"
#define MAX_B 1000

using namespace std;

int modVal;

bool cmp(int a, int b) {
    return (a % modVal) > (b % modVal);
}

int main() {
    ifstream fin("berries.in");
    ofstream fout("berries.out");

    int n, k; fin >> n >> k;

    vector<int> berries(n);
    for (int i = 0;i < n;i++) {
        fin >> berries[i];
    }

    int answer = 0;
    for (int i = 1;i <= MAX_B;i++) {
        int numFullBuckets = 0;
        for (int j = 0; j < n;j++) {
            numFullBuckets += berries[j] / i;
        }

        if (numFullBuckets < k / 2) {
            break;
        }

        if (numFullBuckets >= k) {
            answer = max(answer, (k / 2) * i);
            continue;
        }

        modVal = i;
        sort(ALL(berries), cmp);

        int bessVal = (numFullBuckets - (k / 2)) * i;
        for (int j = 0;(j < n) && (j + numFullBuckets < k);j++) {
            bessVal += berries[j] % modVal;
        }
        answer = max(answer, bessVal);
    }

    fout << answer;
}
