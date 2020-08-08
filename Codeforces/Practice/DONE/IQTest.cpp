#include <bits/stdc++.h>

using namespace std;

int main() {
    int evencount = 0, oddcount=0;
    int evenpos = 0, oddpos = 0;
    int length;
    cin >> length;
    for (int i = 0; i < length; ++i) {
        int num;
        cin >> num;
        if (num % 2 == 0) {
            if (evencount == 0) {
                if (oddcount > 1) {
                    cout << i+1;
                    break;
                }
                else {
                    ++evencount;
                    evenpos = i+1;
                }
            }
            else {
                if (oddcount != 0) {
                    cout << oddpos;
                    break;
                }
                else {
                    ++evencount;
                }
            }
        }
        else {
            if (oddcount == 0) {
                if (evencount > 1) {
                    cout << i+1;
                    break;
                }
                else {
                    ++oddcount;
                    oddpos = i+1;
                }
            }
            else {
                if (evencount != 0) {
                    cout << evenpos;
                    break;
                }
                else {
                    ++oddcount;
                }
            }
        }
    }

}