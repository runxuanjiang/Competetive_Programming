#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <utility>
#include <stack>

using namespace std;

//Insert code stub here
class Solution {
public:
	bool isValid(string s) {
		bool ans;
		stack<char> pars; //for parentheses
		for (int i = 0; i < s.length(); ++i) {
			if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
				pars.push(s[i]);
			}
			else if (s[i] == ')') {
				if (pars.empty() || pars.top() != '(') return false;
				else pars.pop();
			}
			else if (s[i] == ']') {
				if (pars.empty() || pars.top() != '[') return false;
				else pars.pop();
			}
			else if (s[i] == '}') {
				if (pars.empty() || pars.top() != '{') return false;
				else pars.pop();
			}
		}
		if (pars.empty()) return true;
		else return false;
	}
};

int main(int argc, char** argv) {
	Solution a;
	string input = argv[1];
	if (a.isValid(input)) cout << "True";//run code here
	else cout << "False";
	return 0;
}