//Competition #:
//Problem #:
//Accepted: 

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
const int MOD = 1000000007;

#define fast ios::sync_with_stdio(false); cin.tie(nullptr)
#define tests int testCount; cin >> testCount; while(testCount--)

int main() {
    fast;
    string card;
    cin >> card;
    char rank = card[0];
    char suit = card[1];
    vector<string> cards(5);
    for (int i = 0; i < 5; ++i) {
        cin >> cards[i];
    }
    bool found = false;
    for (auto c : cards) {
        if (c[0] == rank || c[1] == suit) {
            found = true;
            break;
        }
    }
    if (found) cout << "YES";
    else cout << "NO";


}