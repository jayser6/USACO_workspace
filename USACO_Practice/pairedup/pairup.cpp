#include <bits/stdc++.h>

#define ll long long

using namespace std;

bool sortCows(pair<ll, ll> a, pair<ll, ll> b) {
    return a.second < b.second;
}

int main() {
    ifstream fin("pairup.in");
    ofstream fout("pairup.out");

    int n; fin >> n;

    vector<pair<ll, ll>> cows(n);
    for (int i = 0;i < n;i++) {
        fin >> cows.at(i).first >> cows.at(i).second;
    }   

    sort(cows.begin(), cows.end(), sortCows);

    ll longestTime = 0;
    int leftIndex = 0, rightIndex = n - 1;
    while (leftIndex < rightIndex) {
        longestTime = max(longestTime, cows.at(leftIndex).second + cows.at(rightIndex).second);
        if (cows.at(leftIndex).first > cows.at(rightIndex).first) {
            cows.at(leftIndex).first -= cows.at(rightIndex).first;
            rightIndex--;
        }
        else if (cows.at(leftIndex).first < cows.at(rightIndex).first) {
            cows.at(rightIndex).first -= cows.at(leftIndex).first;
            leftIndex++;
        }
        else {
            rightIndex--;
            leftIndex++;
        }
    }
    if (leftIndex == rightIndex) {
        longestTime = max(longestTime, cows.at(leftIndex).second + cows.at(rightIndex).second);
    }

    fout << longestTime;
}