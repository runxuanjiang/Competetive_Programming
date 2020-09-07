#include <bits/stdc++.h>

using namespace std;

int main() {
    string input;
    cin >> input;

    bool Astart = false, Bstart = false, Done = false;;

    unsigned Triple = 0;

    for (int i = 0; i < input.length(); ++i) {
        if (input[i] == 'A' || input[i] == 'B') {
            char origChar = input[i];
            unsigned length = 1;
            while (i + 1 < input.length() && input[i+1] != input[i] && (input[i+1] == 'A' || input[i+1] == 'B')) {
                ++i;
                ++length;
            }
            if (length == 2) {
                if (origChar == 'A') Astart = true;
                else if (origChar == 'B') Bstart = true;
            }
            else if (length == 3 || length == 4) ++ Triple;
            else if (length > 4) {
                Done = true;
                break;
            }
        }
    }

    if (Done) cout << "YES";
    else if (Triple > 1) cout << "YES";
    else if (Triple == 1 && (Astart || Bstart)) cout << "YES";
    else if (Astart && Bstart) cout << "YES";
    else cout << "NO";
}