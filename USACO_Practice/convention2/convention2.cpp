#include <bits/stdc++.h>

#define ll long long

using namespace std;

struct Cow {
    int s, t;
    ll a;
};

struct SetComparator {
    bool operator() (Cow a, Cow b) const {
        return a.s < b.s;
    }
};

bool sortCows(Cow a, Cow b) {
    return a.a < b.a;
}

int main() {
    ifstream fin("convention2.in");
    ofstream fout("convention2.out");

    int n; fin >> n;
    
    vector<Cow> cows(n);
    for (int i = 0;i < n;i++) {
        fin >> cows.at(i).a >> cows.at(i).t;
        cows.at(i).s = i;
    }

    sort(cows.begin(), cows.end(), sortCows);

    set<Cow, SetComparator> waitList;
    ll longestWaitTime = 0, endTime = 0;
    int nextCow = 0, cowsMilked = 0;

    while (cowsMilked < n) {
        // get the waiting cows in waitList 
        while ((nextCow < n) && (waitList.size() == 0) || ((nextCow < n) && (cows.at(nextCow).a <= endTime))) {
            waitList.insert(cows.at(nextCow));
            nextCow++;
        }

        // milk the cow with the smallest s(smallest s = highest seniority)
        ll currTime = waitList.begin()->a; 
        if (currTime < endTime) {
            currTime = endTime; 
        }
        // update output
        if (endTime - waitList.begin()->a > longestWaitTime) {
            longestWaitTime = endTime - waitList.begin()->a;
        }
        // update endTime, cowsMilked, and waitList
        endTime = currTime + waitList.begin()->t;
        waitList.erase(waitList.begin());
        cowsMilked++;
    }

    fout << longestWaitTime;
}