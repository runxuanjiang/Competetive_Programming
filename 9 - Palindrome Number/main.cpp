#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <utility>

using namespace std;

//Insert code stub here
class Solution {
public:
	bool isPalindrome(int x) {
		bool ans;
		if (x < 0) return false;
		vector<int> digits;
		while (x > 0) {
			digits.push_back(x % 10);
			x /= 10;
		}
		int i = 0;
		int j = digits.size() - 1;
		while (i < j) {
			if (digits[i] != digits[j]) return false;
			++i;
			--j;
		}
		return true;
	}
};

int main(int argc, char** argv) {
	Solution a;
	int input = atoi(argv[1]);
	if (a.isPalindrome(input)) cout << "True" << endl;
	else cout << "False" << endl;
	return 0;
}