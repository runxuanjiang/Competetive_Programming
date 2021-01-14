#include <bits/stdc++.h>

using namespace std;

struct Seg{
    long long s;
    long long e;
    long long h;
    long long lh;
    long long rh;

    Seg(long long a, long long b, long long c, long long d, long long e) 
        : s(a), e(b), h(c), lh(d), rh(e) { }
};

long long TWO = 2;
long long MOD = 1000000007;

int main() {
    int t;
    cin >> t;
    for (int test = 0; test < t; ++test) {
        int n, k;
        cin >> n >> k;
        long long al, bl, cl, dl, ah, bh, ch, dh, aw, bw, cw, dw;
        vector<long long> L(k);
        vector<long long> H(k);
        vector<long long> W(k);
        for (int i = 0; i < k; ++i) {
            cin >> L[i];
        }
        cin >> al >> bl >> cl >> dl;
        for (int i = 0; i < k; ++i) {
            cin >> W[i];
        }
        cin >> aw >> bw >> cw >> dw;
        for (int i = 0; i < k; ++i) {
            cin >> H[i];
        }
        cin >> ah >> bh >> ch >> dh;

        long long prev1h = -1, prev2h = -1, h = -1;
        long long prev1l = -1, prev2l = -1, s = -1;
        long long prev1w = -1, prev2w = -1, w = -1;
        long long ans = 1;
        long long perim = 0;

        deque<Seg> dq;
        
        for (int x = 0; x < n; ++x) {
            prev2h = prev1h;
            prev1h = h;
            prev2l = prev1l;
            prev1l = s;
            prev2w = prev1w;
            prev1w = w;
            if (x < k) {
                h = H[x];
                s = L[x];
                w = W[x];
            }
            else {
                h = ((ah * prev2h + bh * prev1h + ch + dh) % dh) + 1;
                s = ((al * prev2l + bl * prev1l + cl + dl) % dl) + 1;
                w = ((aw * prev2w + bw * prev1w + cw + dw) % dw) + 1;
            }
            long long e = s+w;

            if (dq.empty() || dq.back().e < e) {
                dq.push_back(Seg(s, e, h, 0, 0));
                perim += (2*w + 2*h);
            }
            for (int i = 0; i < dq.size(); ++i) {
                if (dq[i].s > e) {
                    dq.insert(dq.begin() + i, Seg(s, e, h, 0, 0));
                    perim += (2*w+2*h);
                    break;
                }
                if (dq[i].s < s && dq[i].e > e) {
                    if (h > dq[i].h) {
                        perim += (2*(h - dq[i].h));
                        dq.insert(dq.begin() + (i+1), Seg(e, dq[i].e, dq[i].h, h, dq[i].rh));
                        dq.insert(dq.begin() + (i+1), Seg(s, e, h, dq[i].h, dq[i].h));
                        dq[i].e = s;
                        dq[i].rh = h;
                    }
                }
                else if (dq[i].s <= e && )
                else if (!(dq[i].e < s)) {
                    if (dq[i].s > s) {
                        perim += (2*(dq[i].s - s) + 2*(h - min(h, dq[i].h)));
                        dq.insert(dq.begin() + i, Seg(s, dq[i].s, h, 0, dq[i].h));
                    }
                    else if (dq[i].s <= s) {
                        if (h > dq[i].h) {

                        }
                    }
                    else if (dq[i].s == S) {

                    }
                }
            }

            perim  = perim % MOD;
            perim = (perim + MOD) % MOD;
            ans = (ans * perim) % MOD;
        }
        cout << "Case #" << test + 1 << ": " << ans << endl;
    }
}