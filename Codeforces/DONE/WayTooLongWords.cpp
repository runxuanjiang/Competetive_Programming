#include <iostream>
using namespace std;

int main() {
    int w;
    cin >> w;
    for (int i = 0; i < w; ++i) {
        string word;
        cin >> word;
        if (word.length() > 10) {
            cout << word.front() << word.length() - 2 << word.back() << endl;
        }
        else cout << word << endl;
    }
}