#include <bits/stdc++.h>

using namespace std;

long long TWO = 2;

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

        long long prev1h = -1, prev2h = -1, currh = -1;
        long long prev1l = -1, prev2l = -1, currl = -1;
        long long prev1w = -1, prev2w = -1, currw = -1;
        long long ans = 1;
        long long perim = 0;

        deque<pair<long long, long long> > dq;
        
        for (int x = 0; x < n; ++x) {
            prev2h = prev1h;
            prev1h = currh;
            prev2l = prev1l;
            prev1l = currl;
            prev2w = prev1w;
            prev1w = currw;
            if (x < k) {
                currh = H[x];
                currl = L[x];
                currw = W[x];
            }
            else {
                currh = ((ah * prev2h + bh * prev1h + ch + dh) % dh) + 1;
                currl = ((al * prev2l + bl * prev1l + cl + dl) % dl) + 1;
                currw = ((aw * prev2w + bw * prev1w + cw + dw) % dw) + 1;
            }
            if (dq.empty() || currl > dq.back().second) {
                dq.push_back(make_pair(currl, currl+currw));
                perim += (2*currw + 2*currh);
            }
            else {
                for (int i = 0; i < dq.size(); ++i) {
                    if (dq[i].first > currl + currw) {
                        dq.insert(dq.begin() + i, make_pair(currl, currl+currw));
                        perim += (2*currw + 2*currh);
                        break;
                    }
                    else if (dq[i].first <= currl && dq[i].second >= currl + currw) {
                        perim += 0;
                        break;
                    }
                    else if (dq[i].first <= currl+currw && dq[i].second >= currl+currw) {
                        perim += 2*(dq[i].first - currl);
                        dq[i].first = currl;
                        break;
                    }
                    else if (currl+currw >= dq[i].second && currl <= dq[i].second) {
                        if (currl < dq[i].first) {
                            perim += 2*(dq[i].first - currl);
                            dq[i].first = currl;
                        }
                        int j = i;
                        while (j+1 < dq.size() && currl+currw >= dq[j+1].first) {
                            ++j;
                            perim += (2*(dq[j].first - dq[j-1].second) - 2*currh);
                        }
                        if (dq[j].second < currl+currw) {
                            perim += 2*(currl+currw - dq[j].second);
                        }
                        dq[i].second = max(dq[j].second, currl+currw);
                        for (int k = j; k > i; --k) {
                            dq.erase(dq.begin() + k);
                        }
                        break;
                    }
                }
            }
            perim  = perim % (long long)1000000007;
            ans = (ans * perim) % (long long)1000000007;
        }
        cout << "Case #" << test + 1 << ": " << ans << endl;
    }
}