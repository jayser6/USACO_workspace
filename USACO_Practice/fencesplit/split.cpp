#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
    ifstream fin ("split.in");
    ofstream fout ("split.out");

    int n; fin >> n;
    
    vector<pair<ll, ll>> cows(n);
    for (int i = 0;i < n;i++) {
        fin >> cows.at(i).first >> cows.at(i).second;
    }
}