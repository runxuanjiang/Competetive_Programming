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

void rewind(int target, int &j, vector<pair<char, int>> &dec2enc, vector<char> &enc2dec, const string &dec) {
    while (j > target) {
        --dec2enc[dec[j] - 'a'].second;
        if (dec2enc[dec[j] - 'a'].second == 0) {
            enc2dec[dec2enc[dec[j] - 'a'].first - 'a'] = '*';
            dec2enc[dec[j] - 'a'].first = '*';
        }
        --j;
    }
}

int main() {
    fast;
    string enc, dec;
    cin >> enc >> dec;

    vector<int> counts(26, 0);
    vector<int> kmp(dec.length(), 0);
    int j = 0;
    for (int i = 1; i < kmp.size(); ++i) {
        while (dec[i] != dec[j] && j > 0) {
            j = kmp[j-1];
        }
        if (dec[i] == dec[j]) {
            ++j;
        }
        kmp[i] = j;
    }

    // vector<int> ans;

    // j = 0;
    // vector<pair<char, int>> dec2enc(26, {'*', 0});
    // vector<char> enc2dec(26, '*');
    // for (int i = 0; i < enc.size(); ++i) {
    //     if (j >= dec.length()) {
    //         ans.push_back(i - dec.length());
    //         rewind(kmp[j-1], j, dec2enc, enc2dec, dec);
    //     }
    //     else if (dec2enc[dec[j] - 'a'].first == '*' && enc2dec[enc[i] - 'a'] == '*') {
    //         dec2enc[dec[j] - 'a'] = {enc[i], 1};
    //         enc2dec[enc[i] - 'a'] = dec[j];
    //         ++j;
    //     }
    //     else if (dec2enc[dec[j] - 'a'].first == enc[i] && enc2dec[enc[i] - 'a'] == dec[j]) {
    //         ++dec2enc[dec[j] - 'a'].second;
    //         ++j;
    //     }
    //     else {
    //         rewind(kmp[j-1], j, dec2enc, enc2dec, dec);
    //     }
    //     cout << i << " " << j << endl;
    // }
    // if (j >= dec.length()) {
    //     ans.push_back(enc.length() - dec.length());
    // }

    // if (ans.size() == 1) {
    //     cout << enc.substr(ans[0], dec.length()) << endl;
    // }
    // else {
    //     cout << ans.size() << endl;
    // }
}