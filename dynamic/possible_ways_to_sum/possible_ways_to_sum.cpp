#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int> nums, int S) {

        vector<int>dp (2001, 0);

        return findTargetSumWaysUtil(nums, S, 0, dp);
    }

    int findTargetSumWaysUtil(vector<int>& nums, int S, int idx, vector<int>& dp) {

        int count = 0;
        if(S==0) return 1;
        for(int i = idx; i < nums.size(); ++i)
        {
            count += findTargetSumWaysUtil(nums, S-nums[i], i+1, dp) + 
            findTargetSumWaysUtil(nums, S+nums[i], i+1, dp);
        }
        return count;
    }
};

int main()
{
    Solution s;
    cout << s.findTargetSumWays({1,1,1,1}, 3);
}