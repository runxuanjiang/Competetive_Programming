#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int tst = 0; tst < t; ++tst) {
        int n, m, k;
        cin >> n >> m >> k;
        long long s;
        cin >> s;
        vector<long long> P(k);
        for (int i = 0; i < k; ++i) {
            cin >> P[i];
        }
        long long ap, bp, cp, dp;
        cin >> ap >> bp >> cp >> dp;
        vector<long long> Q(k);
        for (int i = 0; i < k; ++i) {
            cin >> Q[i];
        }
        long long aq, bq, cq, dq;
        cin >> aq >> bq >> cq >> dq;

        vector<node> tree(n);
        for (int i = 0; i < n; ++i) {}
    }
}