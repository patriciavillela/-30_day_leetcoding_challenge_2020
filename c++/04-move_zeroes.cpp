#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*
   This time I appreciated my solution more
   than the other, because mine only loops
   once through the array, while the other
   loops through the end of the array twice.
*/

class Solution {
	public:
		// another solution
		void moveZeroes2(vector<int>& nums) {
			int counter = 0;
			for(int i = 0; i < nums.size(); i++) {
				if(nums[i] != 0) {
					nums[counter++] = nums[i];
				}
			}
			for(;counter < nums.size();counter++) {
				nums[counter]=0;
			}
		}
		// my solution
		void moveZeroes(vector<int>& nums) {
			int counter = 0;
			int x = 0;
			for(int i = 0; i < nums.size(); i++) {
				if(nums[i]!=0) {
					x=nums[counter];
					nums[counter]=nums[i];
					nums[i]=x;
					counter++;
				}
			}
		}
};

int main() {
	Solution s;
	vector<int> nums;
	nums.push_back(0);
	nums.push_back(1);
	nums.push_back(0);
	nums.push_back(3);
	nums.push_back(12);
	s.moveZeroes(nums);
}

