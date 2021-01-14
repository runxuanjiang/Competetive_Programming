#include <bits/stdc++.h>

using namespace std;

int main() {
    unsigned int numshops, numdays;
    cin >> numshops;
    vector<int> prices(numshops);
    for (unsigned i = 0; i < numshops; ++i) {
        unsigned int price;
        cin >> price;
        prices[i] = price;
    }
    sort(prices.begin(), prices.end());
    cin >> numdays;
    for (int i = 0; i < numdays; ++i) {
        unsigned long long coins;
        cin >> coins;
        auto ubound = upper_bound(prices.begin(), prices.end(), coins);
        if (ubound == prices.end()) cout << numshops << endl;
        else cout << ubound - prices.begin() << endl;
    }
}