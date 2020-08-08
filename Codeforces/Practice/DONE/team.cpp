#include <bits/stdc++.h>

using namespace std;

int main() {
    int problems;
    int solved_problems = 0;
    cin >> problems;
    for (int i = 0; i < problems; ++i) {
        int count = 0;
        int solved;
        for (int j = 0; j < 3; ++j) {
            cin >> solved;
            if (solved) ++count;
        }
        if (count >= 2) ++solved_problems;
    }
    cout << solved_problems;
}