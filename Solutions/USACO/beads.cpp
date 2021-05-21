/*
ID: runxuan1
TASK: beads
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
    ofstream fout("beads.out");
    ifstream fin("beads.in");

    int n;
    fin >> n;
    string beads;
    fin >> beads;

    int res = 0;
    int l = beads.length(), r = 0;
    int whites = 0;
    char color = 'w';
    int last = 0;
    while (r < beads.length() && beads[r] == 'w') {
        ++r;
    }

    int prev = r+1;


    if (r >= beads.length()) {
        fout << beads.length() << endl;
        return 0;
    }

    color = beads[r];
    while (r+1 < beads.length() && (beads[r+1] == 'w' || beads[r+1] == color)) {
        ++r;
        ++prev;
        if (beads[r] == 'w') ++whites;
        else whites = 0;
    }

    last = r+1;
    int templeft = 0;


    while (l-1 > r && (beads[l-1] == 'w' || beads[l-1] == color)) {
        --l;
        ++prev;
        if (beads[l-1] != 'w') {
            templeft = beads.length() - l;
        }
    }

    last += templeft;


    if (l == r+1) {
        fout << beads.length() << endl;
        return 0;
    }


    int limit = l;
    int prevwhites = whites;
    int count = 0;

    while (r < limit) {
        whites = 0;
        l = r+1;
        r = l;
        if (r >= limit) break;
        ++count;
        color = beads[l];
        while (r+1 < limit && (beads[r+1] == 'w' || beads[r+1] == color)) {
            ++r;
            if (beads[r] == 'w') ++whites;
            else whites = 0;
        }

        res = max(res, prev + (r-l+1));
        prev = (r-l+1) - whites + prevwhites;
        prevwhites = whites;
    }
    if (count >= 2) {
        res = max(res, prev + last);
    }
    fout << res << endl;
}