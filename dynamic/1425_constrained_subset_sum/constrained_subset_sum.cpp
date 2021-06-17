 
#include <algorithm>
#include <numeric>
#include <vector>
#include <queue>
#include <list>
#include <tuple>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <regex>
#include <string>
#include <sstream>
#include <iostream>

#define CATCH_CONFIG_MAIN
#include "..\..\catch\catch.hpp"
using namespace std;
using namespace Catch;

/* Problem:

Given an integer array nums and an integer k, return the maximum sum of a non-empty subset of that array such that for every two consecutive integers in the subset, nums[i] and nums[j], where i < j, the condition j - i <= k is satisfied.

A subset of an array is obtained by deleting some number of elements (can be zero) from the array, leaving the remaining elements in their original order.

 

Example 1:

Input: nums = [10,2,-10,5,20], k = 2
Output: 37
Explanation: The subset is [10, 2, 5, 20].
Example 2:

Input: nums = [-1,-2,-3], k = 1
Output: -1
Explanation: The subset must be non-empty, so we choose the largest number.
Example 3:

Input: nums = [10,-2,-10,-5,20], k = 2
Output: 23
Explanation: The subset is [10, -2, -5, 20].
 

Constraints:

1 <= k <= nums.length <= 10^5
-10^4 <= nums[i] <= 10^4

*/

class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n);
        int res = INT_MIN;
        
        deque<int> q;
        
        
        for(int i = 0; i < n; ++i)
        {
            dp[i] = max (nums[i], nums[i] + (q.empty() ? 0 : q.front() ));
            
            res = max(dp[i], res);
            
            while(!q.empty() && q.back() < dp[i]) 
                q.pop_back();
            
            q.push_back(dp[i]);
            
            if(i >= k && !q.empty() && dp[i-k]==q.front())
                q.pop_front();
        }
        return res;
    }
};

TEST_CASE("test_success") {
    Solution s;
    vector<int> nums {10,2,-10,5,20};
    REQUIRE(s.constrainedSubsetSum(nums, 2) == 37);
}

TEST_CASE("test_failure") {
    Solution s;
    REQUIRE(1==1);
}
