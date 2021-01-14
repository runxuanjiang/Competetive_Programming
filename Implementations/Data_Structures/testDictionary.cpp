#include "Dictionary.h"

using namespace std;
int main() {
    HashTable hash;
    for (int i = 0; i < 2000; ++i) {
        if (i % 2 == 0) {
            hash[i] = i;
        }
        else hash.insert(i, i);
    }

    for (int i = 0; i < 2000; ++i) {
        cout << hash[i] << " ";
        hash.erase(i);
    }
    cout << endl;
}