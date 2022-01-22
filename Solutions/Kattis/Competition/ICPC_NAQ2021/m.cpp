//Competition #:
//Problem #: I
//Accepted: 

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int MOD = 1000000007;

#define fast ios::sync_with_stdio(false); cin.tie(nullptr)
#define tests int testCount; cin >> testCount; while(testCount--)

int main() {
    fast;
    vector<string> conv = {"000", "001", "010", "011", "100", "101", "110", "111"};
    for (auto &i : conv) {
        reverse(i.begin(), i.end());
    }

    tests {
        string s;
        cin >> s;


        reverse(s.begin(), s.end());
        string msg;
        for (auto i : s) {
            msg += conv[i - '0'];
        }

        while (msg.size() < 18) {
            msg.push_back('0');
        }


        
        vector<char> grid(9);

        for (int i = 0; i < 9; ++i) {
            if (msg[i] == '1') {
                grid[i] = (msg[i + 9] == '1') ? 'X' : 'O';
            }
            else {
                grid[i] = '.';
            }
        }

        vector<vector<char>> board(3, vector<char>(3));
        for (int i = 0; i < 3; ++i) {
            board[0][i] = grid[i];
            board[1][i] = grid[i+3];
            board[2][i] = grid[i+6];
        }

        bool done = false;

        for (int i = 0; i < 3; ++i) {
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && (board[i][0] == 'X' || board[i][0] == 'O')) {
                cout << board[i][0] << " wins" << endl;
                done = true;
                break;
            }
            if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && (board[0][i] == 'X' || board[0][i] == 'O')) {
                cout << board[0][i] << " wins" << endl;
                done = true;
                break;
            }
        }

        if (!done) {
            if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && (board[1][1] == 'X' || board[1][1] == 'O')) {
                cout << board[1][1] << " wins" << endl;
                done = true;
            }
        }

        if (!done) {
            if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && (board[1][1] == 'X' || board[1][1] == 'O')) {
                cout << board[1][1] << " wins" << endl;
                done = true;
            }
        }

        if (!done) {
            for (auto i : grid) {
                if (i == '.') {
                    cout << "In progress" << endl;
                    done = true;
                    break;
                }
            }
        }

        if (!done) {
            cout << "Cat's" << endl;
        }

    }
}