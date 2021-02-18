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

int find(int l, int r) {
    cout << "? " << l << " " << r << endl;
    int in;
    cin >> in;
    return in;
}

int main() {
    int n;
    cin >> n;

    int l = 1, r=n;
    while (r-l > 1) {
        int m = find(l, r);
        char move;
        if (m == l) {
            l = m+1;
            move = 'l';
        }
        else if (m == r) {
            r = m-1;
            move = 'r';
        }
        else if (find(l, m) == m) {
            r = m-1;
            move = 'r';
        }
        else {
            l = m+1;
            move = 'l';
        }

        if (r-l > 1) {
            int mid = l + (r-l)/2;
            if (move == 'l') {
                if (find(m, mid) == m) {
                    r = mid;
                }
                else {
                    l = mid+1;
                }
            }
            else if (move == 'r') {
                if (find(mid, m) == m) {
                    l = mid;
                }
                else {
                    r = mid-1;
                }
            }
        }
    }

    if (l == r) {
        cout << "! " << l << endl;
    }
    else {
        cout << "? " << l << " " << r << endl;
        int m;
        cin >> m;
        cout << "! " << ((m == l) ? r : l) << endl;
    }
}