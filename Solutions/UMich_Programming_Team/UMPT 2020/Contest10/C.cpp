//Competition #:
//Problem #: C
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
    ll score = 0;
    ll length;
    cin >> length;
    map<ll, ll> numcounts;
    for (int i = 0; i < length; ++i) {
        ll num;
        cin >> num;
        if (numcounts.find(num) == numcounts.end()) numcounts[num] = 1;
        else ++numcounts[num];
    }
    for (auto i = numcounts.begin(); i != numcounts.end(); ++i) {
        ll current = i->first * i->second;
        ll prev = 0;
        bool blocked = true;
        while (next(i) != numcounts.end() && next(i)->first == i->first + 1) {
            ++i;
            if (blocked) {
                if (current > prev + i->first*i->second) {
                    blocked = false;
                }
                else {
                    swap(current, prev);
                    current = current + i->first*i->second;
                }
            }
            else {
                blocked = true;
                prev = current;
                current = current + i->first*i->second;
            }
        }
        score += current;
    }
    cout << score;
}