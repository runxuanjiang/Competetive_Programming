//Competition #:
//Problem #: A
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
    string n;
    cin >> n;
    unordered_set<char> seen;
    for (auto i : n) {
        seen.insert(i);
    }

    if (seen.size() == 10) {
        cout << "Impossible" << endl;
        return 0;
    }

    string res1 = n, res2 = n;
    vector<char> unseen;
    for (int i = 0; i <= 9; ++i) {
        if (seen.find('0' + i) == seen.end()) {
            unseen.push_back('0' + i);
        }
    }

    if (unseen.size() == 1 && unseen[0] == '0') {
        cout << 0 << endl;
        return 0;
    }

    if (n == "1") {
        cout << "0 2" << endl;
        return 0;
    }


    for (int i = 0; i < res1.size(); ++i) {
        if (i == 0) {
            bool found = false;
            for (int j = 1; j <= 9; ++j) {
                if (seen.find('0' + j) == seen.end() && '0' + j > res1[i]) {
                    found = true;
                    res1[i] = '0' + j;
                    break;
                }
            }
            if (!found) {
                res1[i] = unseen.front();
                res1.insert(res1.begin(), unseen.front());
                if (res1.front() == '0') {
                    res1.front() = unseen[1];
                }
                ++i;
            }
        }
        else {
            res1[i] = unseen.front();
        }
    }

    for (int i = 0; i < res2.size(); ++i) {
        if (i == 0) {
            bool found = false;
            for (int j = 9; j >= 1; --j) {
                if (seen.find('0' + j) == seen.end() && '0' + j < res2[i]) {
                    found = true;
                    res2[i] = '0' + j;
                    break;
                }
            }
            if (!found) {
                res2 = res2.substr(1);
                res2[i] = unseen.back();
            }
        }
        else {
            res2[i] = unseen.back();
        }
    }

    if (!res2.empty() && stoll(res1) - stoll(n) == stoll(n) - stoll(res2)) {
        cout << res2 << " " << res1 << endl;
    }
    else if (res2.empty() || stoll(res1) - stoll(n) < stoll(n) - stoll(res2)) {
        cout << res1 << endl;
    }
    else {
        cout << res2 << endl;
    }


}