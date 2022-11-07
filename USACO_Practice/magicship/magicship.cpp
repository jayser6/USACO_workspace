#include <iostream>
#include <vector> 
#include <string>
using namespace std;

#define pb push_back

bool canReach(long long time, pair<long long, long long> destination, string s) {
    long long xWind = 0, yWind = 0;

    // distance traveled after "complete" periods
    for (int i = 0;i < s.length();i++) {
        if (s.at(i) == 'U') {
            yWind++;
        }
        else if (s.at(i) == 'D') {
            yWind--;
        }
        else if (s.at(i) == 'R') {
            xWind++;
        }
        else if (s.at(i) == 'L') {
            xWind--;
        }
    }
    xWind *= time / s.length();
    yWind *= time / s.length();

    // distance traveled afrer a remainder of the period
    for (int i = 0;i < time % s.length();i++) {
        if (s.at(i) == 'U') {
            yWind++;
        }
        else if (s.at(i) == 'D') {
            yWind--;
        }
        else if (s.at(i) == 'R') {
            xWind++;
        }
        else if (s.at(i) == 'L') {
            xWind--;
        }
    }
    
    return (abs(xWind - destination.first) + abs(yWind - destination.second)) <= time;
}

int main() {
    long long input1, input2, input3, input4;
    cin >> input1 >> input2 >> input3 >> input4;
    int n; cin >> n;
    string s; cin >> s;
    
    // difference between start and finish points
    pair<long long, long long> destination; 
    destination.first = input3 - input1; 
    destination.second = input4 - input2;

    // binary search for the quickest time to get to the destination
    long long output = -1, bsLow = 0, bsHigh = 1000000000000000000, bsMid;
    while(bsLow <= bsHigh) {
        bsMid = (bsHigh + bsLow) / 2;
        if (canReach(bsMid, destination, s)) {
            bsHigh = bsMid - 1;
            output = bsMid;
        }
        else {
            bsLow = bsMid + 1;
        }
    }

    cout << output;
}