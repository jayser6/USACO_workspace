// not complete

#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define f first
#define s second

using namespace std;

int main () {
    int n, m; cin >> n >> m;

    vector<int> sequence(n);
    vector<int> seqInv(n);
    for (int i = 0;i < n;i++) {
        cin >> sequence.at(i);
        seqInv.at(sequence.at(i) - 1) = i;
    }

    vector<int> del(m);
    for (int i = 0;i < m;i++) {
        cin >> del.at(i);
    }

    vector<pair<int, int>> pairCnt(n); // counts how many numbers are smaller to the left and greater to the right 
    pairCnt.at(0).f = 0;
    pairCnt.at(0).s = sequence.at(0) - 1;
    pairCnt.at(n - 1).f = sequence.at(n - 1) - 1;
    pairCnt.at(n - 1).s = 0;

    int totalInvPair = 0;
    
    set<int> current; 
    current.insert(sequence.at(n - 1));

    for (int i = n - 2;i >= 1;i--) {
        int smallerRight = distance(current.begin(), current.lower_bound(sequence.at(i)));
        int greaterLeft = n - sequence.at(i) - (current.size() - smallerRight);

        cout << greaterLeft << " " << smallerRight << endl;
        current.insert(sequence.at(i));

        totalInvPair += smallerRight; 
        pairCnt.at(i).f = greaterLeft;
        pairCnt.at(i).s = smallerRight;
    }

    for (int i = 0;i < m;i++) {
        cout << totalInvPair << endl;

        int num = seqInv.at(del.at(i) - 1);
        totalInvPair -= (pairCnt.at(num).f + pairCnt.at(num).s); 
    }
}