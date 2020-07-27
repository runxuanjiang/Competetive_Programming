#include <bits/stdc++.h>

using namespace std;

int main() {
    int trips;
    cin >> trips;
    for (int i = 0; i < trips; ++i) {
        bool unreachable = false;
        int cities, tank;
        cin >> cities >> tank;
        vector<int> cost(cities);
        for (int j = 0; j < cities; ++j) {
            cin >> cost[j];
        }
        vector<int> dp(cities);
        for (int i = 0; i < cities; ++i) {
            if (i <= tank) dp[i] = 0;
            else {
                int lc = 0;
                for (int j = 1; j <= tank; ++j) {
                    if (cost[i-j] != 0) {
                        if (lc == 0) lc = cost[i-j] + dp[i-j];
                        else lc = min(lc, cost[i-j] + dp[i-j]);
                    }
                }
                if (lc == 0) {
                    unreachable = true;
                    break;
                }
                else dp[i] = lc;
            }
        }
        if (unreachable) cout << "Case #" << i+1 << ": " << -1 << "\n";
        else cout << "Case #" << i+1 << ": " << dp.back() << "\n";
    }
}