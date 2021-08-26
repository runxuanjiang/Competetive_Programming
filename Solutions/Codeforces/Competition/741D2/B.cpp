//Competition #:
//Problem #: B
//Accepted: 

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int MOD = 1000000007;

#define fast ios::sync_with_stdio(false); cin.tie(nullptr)
#define tests int testCount; cin >> testCount; while(testCount--)

bool isPrime(char a, char b) {
    string num = string() + a + b;
    int n = stoi(num);
    for (int i = 2; i < 11; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    fast;
    tests {
        int k;
        cin >> k;
        string n;
        cin >> n;

        bool done = false;


        for (auto i : n) {
            if (i == '1') {
                cout << 1 << endl;
                cout << i << endl;
                done = true;
                break;
            }
            else if (i == '4') {
                cout << 1 << endl;
                cout << i << endl;
                done = true;
                break;
            }
            else if (i == '6') {
                cout << 1 << endl;
                cout << i << endl;
                done = true;
                break;
            }
            else if (i == '8') {
                cout << 1 << endl;
                cout << i << endl;
                done = true;
                break;
            }
            else if (i == '9') {
                cout << 1 << endl;
                cout << i << endl;
                done = true;
                break;
            }
        }

        if (!done) {
            for (int i = 0; i < n.size(); ++i) {
                for (int j = i+1; j < n.size(); ++j) {
                    if (!isPrime(n[i], n[j])) {
                        cout << 2 << endl;
                        cout << n[i] << n[j] << endl;
                        done = true;
                        break;
                    }
                }
                if (done) {
                    break;
                }
            }
        }
    }
}