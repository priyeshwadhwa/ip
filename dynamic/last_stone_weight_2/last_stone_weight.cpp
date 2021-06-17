

#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>

using namespace std;

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {

        int sum = std::accumulate(stones.begin(), stones.end(), 0);

        int target = sum/2;

        vector<int> dp(target+1, 0);
        
        for(auto stone :  stones)
        {
            for(int w = target; w >= 0; --w )
            {
                if (w - stone >= 0)
                    dp[w] = max(stone + dp[w-stone], dp[w]);
            }
        }

//Can't use this because it makes same weight to be used multiple times.
        for(int i=0; i <= target; i++)
        {
            for(auto stone:stones)
            {
                if(i-stone >=0)
                    dp[i] = max(stone+dp[i-stone], dp[i]);
                    cout << i << ' ' << dp[i] << endl;
            }
        }

        return sum - 2*dp[target];



        
    }
};

int main()
{
    Solution s;
    vector<int> v{31,26,33,21,40};//{1,3,4,3,5,4}; //2,7,4,1,8,1};
    cout << s.lastStoneWeightII(v);
}
