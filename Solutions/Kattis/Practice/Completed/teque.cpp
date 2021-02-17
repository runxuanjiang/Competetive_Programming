//Competition #:
//Problem #:
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
    ll n;
    cin >> n;

    deque<ll> one, two;
    ll size = 0;
    for (int i = 0; i < n; ++i) {
        string c;
        cin >> c;
        ll in;
        cin >> in;
        if (c == "push_back") {
            two.push_back(in);
            if (!(size % 2)) {
                one.push_back(two.front());
                two.pop_front();
            }
            ++size;
        }
        else if (c == "push_front") {
            one.push_front(in);
            if (size % 2) {
                two.push_front(one.back());
                one.pop_back();
            }
            ++size;
        }
        else if (c == "push_middle") {
            if (size % 2) {
                two.push_front(in);
            }
            else {
                one.push_back(in);
            }
            ++size;
        }
        else if (c == "get") {
            if (in < one.size()) {
                cout << one[in] << endl;
            }
            else {
                cout << two[in - one.size()] << endl;
            }
        }
    }
}