// started : 12/1/21
// finished: 12/3/21

#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second

using namespace std; 

struct Cow {
    int index;
    ll x, y;
    Cow(int i, ll x, ll y) {
        index = i;
        this->x = x;
        this->y = y;
    }
}; 

bool comp1(Cow a, Cow b) { // for sorting N cows based on their x-value
    return a.x < b.x;
} 

bool comp2(Cow a, Cow b) { // for sorting E cows based on their y-value
    return a.y < b.y;
}

int main() {
    int n; cin >> n;

    vector<Cow> nCows; // north-facing cows
    vector<Cow> eCows; // east-facing cows
    for (int i = 0;i < n;i++) {
        char input1; ll input2, input3; cin >> input1 >> input2 >> input3;
        if (input1 == 'N') {
            nCows.pb(Cow(i, input2, input3));
        }  
        else {
            eCows.pb(Cow(i, input2, input3));
        }
    }

    sort(nCows.begin(), nCows.end(), comp1);
    sort(eCows.begin(), eCows.end(), comp2);

    // now calculate collisions between N cows and E cows. "i" will be N cows, "j" will be E cows

    // vectors that represent to which other cow(by the index) each cow stops. -1 means the cow doesn't stop
    vector<bool> nCowStop(nCows.size(), false); // did N[i] cow stop?
    vector<bool> eCowStop(eCows.size(), false); // did E[j] cow stop?
    vector<int> nCowBlame(nCows.size(), 0); // how many blames(including transitve) does N[i] cow have?
    vector<int> eCowBlame(eCows.size(), 0); // how many blames(including transitive) does E[j] cow have?

    for (int i = 0;i < nCows.size(); i++) {
        for (int j = 0; j < eCows.size();j++) {  
            if (nCowStop.at(i) || eCowStop.at(j)) {
                continue;
            }
            ll xDif = nCows.at(i).x - eCows.at(j).x, yDif = nCows.at(i).y - eCows.at(j).y;
            if ((xDif > 0) && (yDif < 0)) { // do the cows collide in the first place?
                // yes, they do collide
                if ((abs(xDif) > abs(yDif)) && !nCowStop.at(i)) {
                    // N[i] cow stops E[j] cow
                    eCowStop.at(j) = true;
                    nCowBlame.at(i) += 1 + eCowBlame.at(j);
                }
                else if ((abs(xDif) < abs(yDif)) && !eCowStop.at(j)) {
                    // E[j] cow stops N[i] cow
                    nCowStop.at(i) = true;
                    eCowBlame.at(j) += 1 + nCowBlame.at(i);
                    break;
                }
            }
        }
    }

    vector<int> output(n);
    for (int i = 0;i < nCows.size();i++) {
        output.at(nCows.at(i).index) = nCowBlame.at(i);
    }
    for (int i = 0;i < eCows.size();i++) {
        output.at(eCows.at(i).index) = eCowBlame.at(i);
    }
    
    for (int i = 0;i < n;i++) {
        cout << output.at(i) << endl;
    }
}