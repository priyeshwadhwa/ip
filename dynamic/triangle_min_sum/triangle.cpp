#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int minimumTotal_more_space(vector<vector<int>>& triangle) {
        int h = triangle.size();
        int b = triangle[h-1].size();

        vector<vector<int>> dp(h);
        for(int i = 0; i< h; ++i)
            dp[i] = vector<int>(i+1,0);

        dp[0][0] = triangle[0][0];

        for(int i=1;i<h;i++)
        {
            for(int j = 0; j < i+1; ++j)
                dp[i][j] = triangle[i][j] + min({ j==0 ? dp[i-1][j]:dp[i-1][j-1],         j==i ? dp[i-1][j-1]: dp[i-1][j]  });
        }

        return *min_element(dp[h-1].begin(), dp[h-1].end());
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int h = triangle.size();
        
        vector<int> dp (h);

        dp[0] = triangle[0][0];

        for(int i=1;i<h;i++)
        {
            for(int j=i;j>=0;--j)
            {
                dp[j] = triangle[i][j] + min({j > 0 ? dp[j-1] : std::numeric_limits<int>::max(), 
                                            j < i ? dp[j]:std::numeric_limits<int>::max() });
            }
        }
        return *min_element(dp.begin(), dp.end());
    }
};


int main()
{
    Solution s;
    //s.minimumTotal();
}