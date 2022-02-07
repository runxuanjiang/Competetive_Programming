//Competition #:
//Problem #: H
//Accepted: 

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int MOD = 1000000007;

#define fast ios::sync_with_stdio(false); cin.tie(nullptr)
#define tests int testCount; cin >> testCount; while(testCount--)

int main() {
    fast;

    cout << setprecision(10);

    int n;
    cin >> n;

    vector<ld> ex = {0}, ex2 = {0};

    for (int i = 0; i < n; ++i) {
        char command;
        cin >> command;

        if (command == 'I') {
            ld ti;
            cin >> ti;
            ld mu = (ex[ex.size() - 1] - ex[ex.size() - 1 - ti]) / ti;
            ld mu2 = (ex2[ex2.size() - 1] - ex2[ex2.size() - 1 - ti]) / ti;
            ld stdev = sqrt(mu2 - mu*mu) / sqrt(ti);
            cout << mu - 2 * stdev << " " << mu + 2 * stdev << endl;
        }
        else if (command == 'R') {
            ld x;
            cin >> x;
            ex.push_back(ex.back() + x);
            ex2.push_back(ex2.back() + x*x);
        }
    }
}