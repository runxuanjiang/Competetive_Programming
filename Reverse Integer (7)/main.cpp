#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <utility>
#include <stack>
#include <cstdint>
#include <limits>

using namespace std;


class Solution {
public:
	int reverse(int x) {
		if (x == -2147483648) return 0;
		stack<int> digits;
		unsigned int multiplier = 1;
		int ans = 0;
		bool positive = (x > 0) ? true : false;
		if (!positive) x = -1 * x;
		while (x > 0) {
			digits.push(x % 10);
			x /= 10;
		}
		while (!digits.empty()) {
			if (digits.top() > 0 && multiplier > INT32_MAX / digits.top()) return 0;
			if (ans > INT32_MAX - (digits.top() * multiplier)) return 0;
			ans += (digits.top() * multiplier);
			multiplier *= 10;
			digits.pop();
		}
		if (!positive) ans = ans * -1;
		return ans;
	}
};

int main(int argc, char** argv) {
	Solution a;
	cout << a.reverse(atoi(argv[1])) << endl;
	return 0;
}