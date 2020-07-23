#include <bits/stdc++.h>

using namespace std;

int main() {
    unsigned long long score = 0;
    unsigned length;
    cin >> length;
    map<unsigned long long, unsigned> numcounts;
    for (unsigned i = 0; i < length; ++i) {
        unsigned long long num;
        cin >> num;
        if (numcounts.find(num) == numcounts.end()) numcounts[num] = 1;
        else ++numcounts[num];
    }
    for (auto i = numcounts.begin(); i != numcounts.end(); ++i) {
        unsigned long long current = i->first * i->second;
        unsigned long long prev = 0;
        bool blocked = true;
        while (next(i) != numcounts.end() && next(i)->first == i->first + 1) {
            ++i;
            if (blocked) {
                if (current > prev + i->first*i->second) {
                    blocked = false;
                }
                else {
                    swap(current, prev);
                    current = current + i->first*i->second;\
                }
            }
            else {
                blocked = true;
                prev = current;
                current = current + i->first*i->second;
            }
        }
        score += current;
    }
    cout << score;
}