//Competition #: 666 D2
//Problem #: E
//Acepted: YES

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ll st, r1, r2, r3, d;

ll res(vector<ll> &v, int stage, int state, vector<vector<ll>>& dp, int cleared) {

    if (cleared == v.size()) return 0;
    if (dp[stage][state] != -1) return dp[stage][state];

    //..., 0, 2, ...
    //        ^
    if (state == 0) {
        ll inst = r1 * v[stage] + r3;
        ll clear = min(r2, r1*(v[stage]+1));

        if (stage == v.size() - 1) {
            dp[stage][state] = min(inst, 2*d + clear + r1);
        }
        else {
            dp[stage][state] = min(inst + d + res(v, stage+1, 0, dp, cleared+1),
            clear + d + res(v, stage+1, 1, dp, cleared));
        }
    }
    //..., 1, 2, ...
    //        ^
    else if (state == 1) {
        ll inst = r1 * v[stage] + r3;
        ll clear = min(r2, r1*(v[stage]+1));

        dp[stage][state] = min(inst + d + res(v, stage-1, 3, dp, cleared+1),
        clear + d + res(v, stage-1, 2, dp, cleared));
    }
    //..., 1, 1, ...
    //     ^
    else if (state == 2) {
        dp[stage][state] = r1 + d + res(v, stage+1, 4, dp, cleared+1);
    }
    //..., 1, 0, ...
    //     ^
    else if (state == 3) {
        if (cleared == v.size() - 1) {
            dp[stage][state] = r1;
        }
        else {
            dp[stage][state] = r1 + d + res(v, stage+1, 5, dp, cleared+1);
        }
    }
    //..., 1, 2, ...
    //     ^
    else if (state == 4) {
        if (cleared == v.size() - 1) {
            dp[stage][state] = r1;
        }
        else {
            dp[stage][state] = r1 + d + res(v, stage+1, 0, dp, cleared+1);
        }
    }
    //..., 0, 2, ...
    //     ^
    else if (state == 5) {
        dp[stage][state] = d + res(v, stage+1, 0, dp, cleared);
    }
    // cout << stage << " " << state << " " << cleared << " " << dp[stage][state] << endl;
    return dp[stage][state];
}

int main() {
    cin >> st >> r1 >> r2 >> r3 >> d;
    vector<ll> v(st);
    for (int i = 0; i < st; ++i) {
        cin >> v[i];
    }
    vector<vector<ll>> dp(st, vector<ll>(6, -1));

    cout << res(v, 0, 0, dp, 0);

}