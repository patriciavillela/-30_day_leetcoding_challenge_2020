#include <iostream>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;

/*
   My solution uses a vector to store all computed numbers.
   If a number has already been computed, we have reached a
   loop, and therefore are certain that the number is not a
   Happy Number.
   The second solution uses Floyd's tortoise and hare algo-
   rithm to detect the cycle, dismissing the need for a 
   vector.
   The third solution doesn't use any of that. It takes ad-
   vantage of the fact that any number (less than 10000000,
   at least) will have a step that's single digit. Conside-
   ring this and the fact that the process is cyclical, if
   the process passes through the single digit numbers 1 or
   7, the original number is a happy number. Otherwise, it
   is not. Clever.
*/

class Solution {
public:
	// clever solution
	bool isHappy3(int n) {
		if(n<10&&(n==1||n==7))return true;
		int x,sum;
		sum=x=n;
		while(sum>9){
			sum=0;
			while(x>0) {
				sum+=(x%10)*(x%10);
				x/=10;
			}
			if(sum==1||sum==7)return true;
			x=sum;
		}
		return false;

	}
	// memory-efficient solution
	bool isHappy2(int n) {
		int slow,fast;
		slow=fast=n;
		do {
			slow = sumOfSquaresOfDigits(slow);
			fast = sumOfSquaresOfDigits(sumOfSquaresOfDigits(fast));
		} while(slow != fast);
		return (slow == 1);
	}

	// my solution
	bool isHappy(int n) {
		int orig = n;
		vector<int> nums;
		nums.push_back(n);
		while(n != 1) {
			n = sumOfSquaresOfDigits(n);
			if(find(nums.begin(),nums.end(),n)!=nums.end()) break;
			nums.push_back(n);
		}
		return n == 1;
	}
private:
	int sumOfSquaresOfDigits(int n) {
		int total = 0;
		while(n) {
			total += pow(n%10,2);
			n = n/10;
		}
		return total;
	}
};

int main() {
	Solution s;
	int n = 19;
	cout << s.isHappy(n) << endl;
}

