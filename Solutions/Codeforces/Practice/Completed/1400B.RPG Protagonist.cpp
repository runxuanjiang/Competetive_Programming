//Competition #: Educational Codeforces Round 94
//Problem #: B

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define loop(i, e) for (; i < e; ++i)

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll p, f;
        cin >> p >> f;
        ll cnts, cntw;
        cin >> cnts >> cntw;
        ll s, w;
        cin >> s >> w;

        if (s > w) {
            swap(s, w);
            swap(cnts, cntw);
        }

        ll res = 0;
        int i = 0;
        loop(i, cntw+1) {
            if (i*w > p) break;
            ll ps = 0, pw = i, fs = 0, fw = 0;

            ps += min((p - pw*w) / s, cnts);

            fs += min(f/s, cnts - ps);
            fw += min((f-fs*s) / w, cntw-pw);

            res = max(res, pw+ps+fs+fw);
        }
        cout << res << endl;
    }
}