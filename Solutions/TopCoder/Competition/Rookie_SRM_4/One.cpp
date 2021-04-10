//Competition #:
//Problem #:
//Accepted: YES

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int MOD = 1000000007;

#define fast ios::sync_with_stdio(false); cin.tie(nullptr)
#define tests int testCount; cin >> testCount; while(testCount--)

class PaintingCells{
public:
    int paint(int rows, int columns) {
        return (rows * columns + 1) / 2;
    }


};