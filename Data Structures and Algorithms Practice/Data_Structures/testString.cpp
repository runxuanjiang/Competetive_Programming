#include "String.h"

using namespace std;
int main() {
    String test = "Hello World!";
    cout << test << endl;
    cout << test.length() << endl;
    for (int i = 0; i < test.length(); ++i) {
        cout << test[i];
    }
    cout << endl;
    test.erase(0, 6);
    cout << test << endl;
    test.erase(2, 4);
    test += "w, Awesome!";
    cout << test << endl;
    test += ' ';
    String test2 = test;
    cout << test2 << endl;
    test += test;
    cout << test << endl;
    cout << test.substr(0, 4) << endl;

}