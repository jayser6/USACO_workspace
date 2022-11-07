#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream fin("diamond.in");
    ofstream fout("diamond.out");

    int n;
    long long k; 
    fin >> n >> k; 

    vector<long long> diamonds(n);
    for (int i = 0;i < n;i++) {
        fin >> diamonds.at(i);
    }
    fin.close();

    sort(diamonds.begin(), diamonds.end());

    vector<int> caseSize(n);
    auto it = diamonds.begin();
    for (int i = 0;i < n;i++, it++) {
       caseSize.at(i) = (upper_bound(diamonds.begin(), diamonds.end(), diamonds.at(i) + k) - it);
    }

    vector<int> maxSizeTil(n);
    for (int i = n - 2, maxSize = -1;i >= 0;i--) {
        maxSize = max(maxSize, caseSize.at(i + 1));
        maxSizeTil.at(i) = maxSize;
    }

    int output = 0;
    for (int i = 0;i < n;i++) {
        output = max(output, (caseSize.at(i) + maxSizeTil.at(i + caseSize.at(i) - 1)));
    }

    fout << output;
    fout.close();
}