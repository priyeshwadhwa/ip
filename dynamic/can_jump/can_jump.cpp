
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canJump_dynamic(vector<int> nums) {
        int n = nums.size();
        if (n == 0 ) return false;
        
        vector<bool> dp(n, false);
        dp[n-1] = true;
        
        for(int i = n-2; i >= 0; --i)
        {
            if(i+nums[i] >= n-1)
            {
                dp[i] = true; 
                continue;
            }
            int farthest = min(i+nums[i], n-1);
            for(int j = i; j <= farthest; ++j)
                if(dp[j] == true){
                    dp[i] = true;
                    continue;
                }
        }
        return dp[0];
    }

    bool canJump(vector<int> nums) {
        int n = nums.size();
        if (n == 0 ) return false;
        
        int i = 0;
        while(i<n)
        {
            if(i+nums[i] >= n-1)
                return true;

            if(nums[i] == 0 )
                return false;

            auto start = nums.begin() + i + 1;
            auto end = nums.begin() + i + nums[i] + 1;
            auto it = max_element(start, end );
            i = it - nums.begin();
        }
        return false;
    }
};

int main()
{
    Solution s;
    cout<< s.canJump({1,1,1,0});
}