//Competition #: 200
//Problem #: C
//Acepted: YES

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

bool check(vector<ll> &heads, vector<ll> &tracks, ll t) {
    int done = 0;

    for (int i = 0; i < heads.size(); ++i) {
        int j = 0;
        for (; j < tracks.size() - done; ++j) {
            ll tempt = (tracks[j+done] - tracks[done]) + min(abs(tracks[j+done] - heads[i]), abs(tracks[done] - heads[i]));
            if (tempt > t) {
                break;
            }
        }
        done += j;
        if (done == tracks.size()) return true;
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> heads(n), tracks(m);
    for (int i = 0; i < n; ++i) {
        cin >> heads[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> tracks[i];
    }

    sort(tracks.begin(), tracks.end());
    sort(heads.begin(), heads.end());

    ll r = tracks.back() + heads.back() + 1;
    ll l = 0;

    while (l != r) {
        // cout << l << " " << r << endl;
        ll m = (r+l)/2;
        if (check(heads, tracks, m)) r = m;
        else l = m+1;
    }
    cout << l;
}