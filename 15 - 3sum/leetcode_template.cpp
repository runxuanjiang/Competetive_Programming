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
    vector<vector<int>> threeSum(vector<int>& nums) {
        
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