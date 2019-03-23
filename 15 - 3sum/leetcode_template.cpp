#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <utility>
#include <iterator>

using namespace std;

//Insert code stub here
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> ans;
		vector<int> negs;
		vector<int> poss;
		bool zero;
		for (auto i : nums) {
			if (i < 0) negs.push_back(i);
			else if (i > 0) poss.push_back(i);
			else zero = true;
		}
		if (zero) {
			
		}

    }
};

int main(int argc, char** argv) {
	Solution a;
	vector<int> input;
	for (int i = 1; i < argc; ++i) {
		input.push_back(atoi(argv[i]));
	}
	vector<vector<int>> answer = a.threeSum(input);
	for (int i = 0; i < answer.size(); ++i) {
		cout << "[";
		for (int j = 0; j < answer[i].size() - 1; ++j) {
			cout << answer[i][j] << ", ";
		}
		cout << answer[i][2] << " ]" << endl;
	}
	//run code here
	return 0;
}