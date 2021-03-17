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

class ShootingGame {
public:
    double findProbability(int p) {
        double pAlice = (double) p / 1000000;
        return (pAlice >= 0.5) ? -1 : pAlice / (1 - pAlice);
    }
};
