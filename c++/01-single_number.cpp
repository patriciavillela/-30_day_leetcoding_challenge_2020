#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*
   Using ios_base::sync_with_stdio(false) and cin.tie(NULL)
   removes the necessity from C++'s iostream to be synchro-
   nized with C's scanf, making it faster.
   Source: https://www.geeksforgeeks.org/fast-io-for-competitive-programming/
*/

class Solution {
public:
	// faster solution
	int singleNumber2(vector<int>& nums) {
		// explanation on top of the file
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		int res=nums[0];
		int sz=nums.size();
		// this for is faster than the one I used
		for(int i=1;i<sz;++i) res ^= nums[i];
		return res;
	}

	// my solution
	int singleNumber(vector<int>& nums) {
		int total = 0;
		for(int num : nums)
			total ^= num;
		return total;
	}
};

int main() {
	Solution s;
	vector<int> vect;
	int n = 1000000;
	while(n--) vect.push_back(1);
	cout << s.singleNumber(vect) << endl;
	//cout << s.singleNumber2(vect1) << endl;
}

