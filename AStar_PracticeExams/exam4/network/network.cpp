#include <bits/stdc++.h>

#define FOR(n) for (int i = 0;i < n;i++)
#define FORO(n) for (int i = 1;i < n;i++)
#define ROF(n) for (int i = n - 1;i >= 0;i--)
#define ROFO(n) for (int i = n - 1;i >= 1;i--)
#define forever while (true)
#define ALL(arr) arr.begin(), arr.end()
#define lower lower_bound
#define upper upper_bound
#define ll long long
#define hashmap unordered_map
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl "\n"
#define BIG_NUMBER (ll)pow(10, 18)

using namespace std;;

string getOutput(const vector<vector<bool>>& bits) {
    string output = "";
    for (int i = 0;i < bits.size();i++) {
        for (int j = 0;j < bits.size();j++) {
            output += bits[i][j] + 48;
        }
    }
    return output;
}

void flipBit(int r, int c, vector<vector<bool>>& bits) {
    bits[r][c] = !bits[r][c];
}

bool isGood(const vector<vector<bool>>& bits) {
    for (int i = 0;i < bits.size();i++) {
        int colSum = 0;
        int rowSum = 0;
        for (int j = 0;j < bits.size();j++) {
            if (bits[i][j]) {
                rowSum++;
            }
            if (bits[j][i]) {
                colSum++;
            }
        }

        if (rowSum % 2) {
            return false;
        }
        if (colSum % 2) {
            return false;
        }
    }
    return true;
}

void allSub(int curr, set<string>& output, const vector<int>& wrongRow, const vector<int>& wrongCol, vector<vector<bool>>& bits) {
    if (curr == max(wrongRow.size(), wrongCol.size())) {
        if (isGood(bits)) {
            output.insert(getOutput(bits));
        }
        return;
    }

    if (wrongRow.size() > wrongCol.size()) {
        for (int i = 0;i < bits.size();i++) {
            flipBit(wrongRow[curr], i, bits);
            allSub(curr + 1, output, wrongRow, wrongCol, bits);
            flipBit(wrongRow[curr], i, bits);
        }
    }
    else {
        for (int i = 0;i < bits.size();i++) {
            flipBit(i, wrongCol[curr], bits);
            allSub(curr + 1, output, wrongRow, wrongCol, bits);
            flipBit(i, wrongCol[curr], bits);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<vector<bool>> bits(n, vector<bool>(n));
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            char in; cin >> in;
            bits[i][j] = in - 48;
        }
    }

    vector<int> wrongRow;
    vector<int> wrongCol;
    for (int i = 0;i < n;i++) {
        int colSum = 0;
        int rowSum = 0;
        for (int j = 0;j < n;j++) {
            if (bits[i][j]) {
                rowSum++;
            }
            if (bits[j][i]) {
                colSum++;
            }
        }

        if (rowSum % 2) {
            wrongRow.pb(i);
        }
        if (colSum % 2) {
            wrongCol.pb(i);
        }
    }

    if (wrongRow.size() == wrongCol.size() && (wrongRow.size() == 0 || wrongRow.size() == 1)) {
        cout << "ACK" << endl;
        cout << wrongRow.size() << endl;
        if (wrongRow.size() == 0) {
            cout << getOutput(bits);
        }
        else {
            flipBit(wrongRow[0], wrongCol[0], bits);
            cout << getOutput(bits);
            flipBit(wrongRow[0], wrongCol[0], bits);
        }
    }
    else {
        cout << "NACK" << endl;
        cout << max(wrongCol.size(), wrongRow.size()) << endl;

        set<string> output;
        allSub(0, output, wrongRow, wrongCol, bits);
        cout << output.size() << endl;
        if (output.size() <= 10) {
            for (auto it = output.begin();it != output.end();it++) {
                cout << *it << endl;
            }
        }
    }
}
