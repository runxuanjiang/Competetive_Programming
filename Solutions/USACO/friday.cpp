/*
ID: runxuan1
TASK: friday
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
    ofstream fout("friday.out");
    ifstream fin("friday.in");
    int n;
    fin >> n;

    int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int lymonths[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int dow = 0;
    int year = 0, month = 0, day = 1;
    vector<int> res(7, 0);
    while (year < n) {
        dow = (dow + 1) % 7;
        day += 1;
        if (year % 4 == 0 && year != 0 && year != 200 && year != 300 && year != 400) {
            if (day > lymonths[month]) {
                day = 1;
                month++;
                if (month == 12) {
                    month = 0;
                    year++;
                }
            }
        }
        else {
            if (day > months[month]) {
                day = 1;
                month++;
                if (month == 12) {
                    month = 0;
                    year++;
                }
            }
        }
        if (day == 13) {
            res[dow]++;
        }
    }
    for (int i = 5; i < 12; ++i) {
        fout << res[i % 7] << ((i == 11) ? "\n" : " ");
    }
}