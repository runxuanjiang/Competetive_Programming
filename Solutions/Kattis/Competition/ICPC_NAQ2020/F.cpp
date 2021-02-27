//Competition #:
//Problem #: F
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
    int n;
    cin >> n;
    string trash;
    getline(cin, trash);
    for (int i = 0; i < n; ++i) {
        string sent;
        getline(cin, sent);

        istringstream iss(sent);
        vector<string> sentence;
        string in;
        while (iss >> in) {
            sentence.push_back(in);
        }

        if (sentence.size() >= 2 && sentence[0] == "Simon" && sentence[1] == "says") {
            for (int i = 2; i < sentence.size(); ++i) {
                cout << sentence[i] << " ";
            }
            cout << endl;
        }
    }
}