/*
ID: runxuan1
TASK: test
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
    ofstream fout("test.out");
    ifstream fin("test.in");
    int a, b;
    fin >> a >> b;
    fout << a+b << endl;
}