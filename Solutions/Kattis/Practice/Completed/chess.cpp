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
    tests {
        pair<char, int> start, end;
        cin >> start.first;
        cin >> start.second;
        cin >> end.first;
        cin >> end.second;

        if (start.first == end.first && start.second == end.second) {
            cout << 0 << " " << start.first << " " << start.second << endl;
        }
        else if (abs(start.first - end.first) == abs(start.second - end.second)) {
            cout << 1 << " " << start.first << " " << start.second << " " << end.first << " " << end.second << endl;
        }
        else if ( ((int) (start.first - 'A') + start.second - 1) % 2 == ((int) (end.first - 'A') + end.second - 1) % 2) {
            for (char i = 'A'; i <= 'H'; ++i) {
                for (int j = 1; j <= 8; ++j) {
                    if (abs(start.first - i) == abs(start.second - j) && abs(end.first - i) == abs(end.second-j)) {
                        cout << 2 << " " << start.first << " " << start.second << " " << i << " " << j << " " <<  end.first << " " << end.second << endl;
                        goto done;
                    }
                }
            }
        }
        else {
            cout << "Impossible" << endl;
        }
        done: continue;
    }
}