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

class ChemicalMixing{
public:
    double closestBlend(vector<int> volume, vector<int> solute, int minVolume, double desiredStrength) {
        vector<bitset<1001>> possible(5001);
        for (int i = 0; i < volume.size(); ++i) {
            for (int j = 5000; j >= 0; --j) {
                possible[j+volume[i]] |= (possible[j] << solute[i]);
            }
            possible[volume[i]][solute[i]] = 1;
        }

        ld res = 1000;
        for (int i = minVolume; i < 5001; ++i) {
            for (int j = 0; j < 1001; ++j) {
                if (possible[i][j]) {
                    cout << j << " " << i << endl;
                    res = min(res, abs((ld) j / (ld) i - desiredStrength));
                }
            }
        }
        return res;
    }
};