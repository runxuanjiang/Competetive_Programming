//Competition #:
//Problem #: D
//Accepted: 

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int MOD = 1000000007;

#define fast ios::sync_with_stdio(false); cin.tie(nullptr)
#define tests int testCount; cin >> testCount; while(testCount--)

void updateSets(ll i, const string &s, set<ll> &doubleLefts, set<ll> &doubleRights, set<ll> &inverts, bool remove=false) {
    if (s[i] == '(') {
        if (s[i+1] == '(') {
            if (remove) {
                doubleLefts.erase(i);
            }
            else {
                doubleLefts.insert(i);
            }

        }
    }
    else {
        if (s[i+1] == '(') {
            if (remove) {
                inverts.erase(i);
            }
            else {
                inverts.insert(i);
            }
        }
        else {
            if (remove) {
                doubleRights.erase(i);
            }
            else {
                doubleRights.insert(i);
            }

        }
    }
}

int main() {
    fast;
    ll n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    set<ll> doubleLefts;
    set<ll> doubleRights;
    set<ll> inverts;

    if (n % 2 == 0) {
        for (int i = 0; i < n; i += 2) {
            updateSets(i, s, doubleLefts, doubleRights, inverts);
        }
    }
    

    for (int i = 0; i < q; ++i) {
        ll idx;
        cin >> idx;
        --idx;

        ll affectedIdx = (idx % 2 == 0) ? idx : idx-1;
        updateSets(affectedIdx, s, doubleLefts, doubleRights, inverts, true);
        s[idx] = (s[idx] == '(') ? ')' : '(';
        // cerr << s << endl;
        updateSets(affectedIdx, s, doubleLefts, doubleRights, inverts);

        // cerr << "doubleLefts: ";
        // for (auto i : doubleLefts) {
        //     cerr << i << " ";
        // }
        // cerr << endl;
        // cerr << "doubleRights: ";
        // for (auto i : doubleRights) {
        //     cerr << i << " ";
        // }
        // cerr << endl;
        // cerr << "inverts: ";
        // for (auto i : inverts) {
        //     cerr << i << " ";
        // }
        // cerr << endl;


        if (n % 2 == 0) {
            if (doubleLefts.empty() ^ doubleRights.empty()) {
                cout << "NO" << endl;
                continue;
            }
            if (!doubleLefts.empty()) {
                ll firstDoubleLeft = *doubleLefts.begin();
                ll lastDoubleLeft = *(--doubleLefts.end());
                ll firstDoubleRight = *doubleRights.begin();
                ll lastDoubleRight = *(--doubleRights.end());
                if (firstDoubleLeft > firstDoubleRight) {
                    cout << "NO" << endl;
                    continue;
                }
                if (lastDoubleRight < lastDoubleLeft) {
                    cout << "NO" << endl;
                    continue;
                }
            }
            if (!inverts.empty()) {
                if (doubleLefts.empty()) {
                    cout << "NO" << endl;
                    continue;
                }
                else if (doubleRights.empty()) {
                    cout << "NO" << endl;
                    continue;
                }
                else {
                    ll firstDoubleLeft = *doubleLefts.begin();
                    ll lastDoubleRight = *(--doubleRights.end());
                    ll firstInvert = *inverts.begin();
                    ll lastInvert = *(--inverts.end());
                    if (firstDoubleLeft > firstInvert) {
                        cout << "NO" << endl;
                        continue;
                    }
                    else if (lastDoubleRight < lastInvert) {
                        cout << "NO" << endl;
                        continue;
                    }

                }
            }
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }

    }
}