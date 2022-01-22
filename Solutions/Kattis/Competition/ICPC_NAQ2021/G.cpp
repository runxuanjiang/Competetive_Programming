//Competition #:
//Problem #: G
//Accepted: 

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int MOD = 1000000007;

#define fast ios::sync_with_stdio(false); cin.tie(nullptr)
#define tests int testCount; cin >> testCount; while(testCount--)

void pentry(pair<int, int> &p) {
    if (p.first == p.second) {
        cout << p.first;
    }
    else {
        cout << p.first << "-" << p.second;
    }
}

int main() {
    fast;
    int c, w;
    cin >> c >> w;
    vector<int> e(w);
    for (int i = 0; i < w; ++i) {
        cin >> e[i];
    }

    sort(e.begin(), e.end());

    vector<pair<int, int>> errors;
    for (int i = 0; i < e.size(); ++i) {
        int start = e[i];
        while (i+1 < e.size() && e[i+1] == e[i] + 1) {
            ++i;
        }

        errors.push_back({start, e[i]});
    }

    unordered_set<int> seen(e.begin(), e.end());
    vector<pair<int, int>> correct;
    for (int i = 1; i <= c; ++i) {
        if (seen.find(i) != seen.end()) {
            continue;
        }

        int start = i;
        while (i+1 <= c && seen.find(i+1) == seen.end()) {
            ++i;
        }
        correct.push_back({start, i});
    }

    cout << "Errors: ";
    if (errors.size() == 1) {
        pentry(errors[0]);
        cout << endl;
    }
    else if (errors.size() == 2) {
        pentry(errors[0]);
        cout << " and ";
        pentry(errors[1]);
        cout << endl;
    }
    else {
        for (int i = 0; i+1 < errors.size(); ++i) {
            pentry(errors[i]);
            if (i != errors.size() - 2) {
                cout << ", ";
            }
        }
        cout << " and ";
        pentry(errors.back());
        cout << endl;
    }

    cout << "Correct: ";
    if (correct.size() == 1) {
        pentry(correct[0]);
        cout << endl;
    }
    else if (correct.size() == 2) {
        pentry(correct[0]);
        cout << " and ";
        pentry(correct[1]);
        cout << endl;
    }
    else {
        for (int i = 0; i+1 < correct.size(); ++i) {
            pentry(correct[i]);
            if (i != correct.size() - 2) {
                cout << ", ";
            }

        }
        cout << " and ";
        pentry(correct.back());
        cout << endl;
    }
}