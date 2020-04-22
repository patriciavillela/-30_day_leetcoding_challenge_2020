#include <iostream>
#include <bits/stdc++.h>
#include <chrono>

using namespace std;

/*
   At this point I'm starting to question LeetCodes'
   approach to timing, because my solution is ever
   so slightly different from the "fastest" one,
   and in ways that would in theory make mine faster.
   I noticed that, submitting the same code twice,
   you can get different running times. So, I'm only
   acknowledging "faster" solutions if they present
   something different.

   The auto keyword is from the C days and states
   that the runtime should figure out the type of the
   variable.
*/

class Solution {
public:
	int maxSubArray2(vector<int>& nums) {
		auto sum=0,maxsum=INT_MIN;
		for(auto i : nums) {
			sum=max(i,sum+i);
			maxsum=max(maxsum,sum);
		}
		return maxsum;
	}
	// "my solution" (actually I needed to see
	// errichto's explanation to fix some issues
	int maxSubArray(vector<int>& nums) {
		int ans = INT_MIN;
		int a = 0;
		for(int i = 0; i < nums.size(); i++) {
			a+=nums[i];
			ans=max(ans,a);
			a=max(a,0);
		}
		return ans;
	}
};

int main() {
	Solution s;
	vector<int> nums;
	nums.push_back(-2);
	nums.push_back(1);
	nums.push_back(-3);
	nums.push_back(4);
	nums.push_back(-1);
	nums.push_back(2);
	nums.push_back(1);
	nums.push_back(-5);
	nums.push_back(4);
	cout << s.maxSubArray2(nums) << endl;
}
