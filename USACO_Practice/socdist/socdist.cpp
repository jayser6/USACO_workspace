#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

#define pb push_back

ifstream fin("socdist.in");
ofstream fout("socdist.out");

bool canCowsDistance(int n, long long d, vector<pair<long long, long long>> grass) {
    long long currentLocation = grass.at(0).first;
    for (int i = 0, j = 0;i < n;i++) {
        while(grass.at(j).second < currentLocation + d && i != n - 1) {
            j++;
            if (j >= grass.size()) {
                //fout << d << "doesnt work" << endl;
                return false;
            }
        }
        currentLocation = max(currentLocation + d, grass.at(j).first);
    }
    return true;
}

int main() {
    int n, m; fin >> n >> m;

    vector<pair<long long, long long>> grass(m);
    for (int i = 0;i < m;i++) {
        fin >> grass.at(i).first >> grass.at(i).second;
    }
    sort(grass.begin(), grass.end());

    long long maxD = -1, bsLow = 0, bsHigh = grass.at(m - 1).second, bsMid;
    while(bsLow <= bsHigh) {
        bsMid = (bsHigh + bsLow) / 2;
        if (canCowsDistance(n, bsMid, grass)) {
            maxD = bsMid;
            bsLow = bsMid + 1;
        }
        else {
            bsHigh = bsMid - 1;
        }
    }

    fout << maxD;
}
