// started : 02/24/22
// finished: ???
// problem : http://www.usaco.org/index.php?page=viewproblem2&cpid=714

#include <bits/stdc++.h>

#define ALL(arr) arr.begin(), arr.end()
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl "\n"

using namespace std;

ifstream fin("helpcross.in");
ofstream fout("helpcross.out");

bool cmp(pair<ll, int> a, pair<ll, int> b) {
    if (a.f == b.f) {
        return a.s > b.s;
    }

    return a.f < b.f;
}

int main() {
    int c, n; fin >> c >> n;

    vector<pair<ll, int>> points; // position, type *** type 0 -> t, type 1 -> b, type 2 -> a
    
    // these are the chickens
    for (int i = 0;i < c;i++) {
        ll t; fin >> t;
        points.pb(mp(t, 0));
    }

    // these are the cows
    for (int i = 0;i < n;i++) {
        ll a, b; fin >> a >> b;
        points.pb(mp(a, 2));
        points.pb(mp(b, 1));
    }

    sort(ALL(points), cmp);

    int output = 0;
    int cowCnt = 0;
    int cowRemove = 0;
    for (int i = 0;i < points.size();i++) {
        if ((points[i].s == 0) && (cowCnt > 0)) {
            // this point is a chicken and it can be paired with a cow
            output++;
            cowCnt--;
            cowRemove++;
        }

        if (points[i].s == 2) {
            cowCnt++;
        }
        else if (points[i].s == 1) {
            if (cowRemove == 0) {
                cowCnt--;
            }
            else {
                cowRemove--;
            }
        }
        fout << "position: " << points[i].f << ", type: " << points[i].s << endl;
        fout << "output: " << output << ", cowCnt: " << cowCnt << ", cowRemove: " << cowRemove << endl; 
    }

    fout << "answer: " << output;
}