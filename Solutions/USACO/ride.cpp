/*
ID: runxuan1
TASK: ride
LANG: C++
*/

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
    ofstream fout("ride.out");
    ifstream fin("ride.in");
    int mod = 47;
    string a, b;
    fin >> a >> b;
    int x = 1, y = 1;
    for (auto i : a) {
        x = (x * (int)(i - 'A' + 1)) % mod;
    }
    for (auto i : b) {
        y = (y * (int) (i - 'A' + 1)) % mod;
    }

    if (x == y) {
        fout << "GO\n";
    }
    else {
        fout << "STAY\n";
    }

    
}