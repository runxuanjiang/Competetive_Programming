#include <bits/stdc++.h>

using namespace std;

long long TWO = 2;

struct qEntry{
    long long end;
    long long height;
    long long p;

    qEntry(long long a, long long b, long long c) {
        end = a;
        height = b;
        p = c;
    }
};

class compare{
public:
    bool operator()(qEntry &a, qEntry &b) {
        if (a.height < b.height) return true;
        return false;
    }
};

int main() {
    int t;
    cin >> t;
    for (int test = 0; test < t; ++test) {
        int n, k;
        cin >> n >> k;
        long long w;
        cin >> w;
        long long al, bl, cl, dl, ah, bh, ch, dh;
        vector<long long> L(k);
        vector<long long> H(k);
        for (int i = 0; i < k; ++i) {
            cin >> L[i];
        }
        cin >> al >> bl >> cl >> dl;
        for (int i = 0; i < k; ++i) {
            cin >> H[i];
        }
        cin >> ah >> bh >> ch >> dh;

        long long prev1h = -1, prev2h = -1, currh = -1;
        long long prev1l = -1, prev2l = -1, currl = -1;
        long long ans = 1;
        long long perim = 0;

        priority_queue<qEntry, vector<qEntry>, compare> pq;
        
        for (int i = 0; i < n; ++i) {
            if (i >= 2) {
                prev2h = prev1h;
                prev1h = currh;
                prev2l = prev1l;
                prev1l = currl;
            }
            else if (i == 1) {
                prev1h = currh;
                prev1l = currl;
            }
            if (i < k) {
                currh = H[i];
                currl = L[i];
            }
            else {
                currh = ((ah * prev2h + bh * prev1h + ch + dh) % dh) + 1;
                currl = ((al * prev2l + bl * prev1l + cl + dl) % dl) + 1;
            }
            while (!pq.empty() && pq.top().end < currl) {
                pq.pop();
            }
            if (pq.empty()) {
                perim += TWO*w + TWO*currh;
            }
            else if (currl == pq.top().end) {
                if (currh > pq.top().height) {
                    perim = pq.top().p + (TWO*w + TWO*(currh -pq.top().height));
                }
                else {
                    perim = pq.top().p + (TWO*w);
                }
            }
            else if (currl < pq.top().end) {
                if (currh > pq.top().height) {
                    perim = pq.top().p +  (TWO*(currh - pq.top().height) + TWO*(currl + w - pq.top().end));
                }
                else {
                    perim = pq.top().p +  (TWO*(currl + w -pq.top().end));
                }
            }
            qEntry add(currl + w, currh, perim);
            pq.push(add);
            perim  = perim % (long long)1000000007;
            ans = (ans * perim) % (long long)1000000007;
        }
        cout << "Case #" << test + 1 << ": " << ans << endl;
    }
}