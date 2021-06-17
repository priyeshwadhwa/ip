#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>> D) {
        int m = D.size();

        int n = D[0].size();

        vector<int> dp (n+1, 0);

        for(int i = 0; i < m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if(i == 0)
                {
                    //
                    dp[j] = D[i][j-1] + dp[j-1];
                }
                else if (j-1 == 0)
                {
                    //
                    dp[j] = D[i][j-1] + dp[j];
                }
                else
                {
                    //
                    dp[j] = D[i][j-1] + max(dp[j], dp[j-1]);
                }
                
            }
        }
        return dp[n] + 1;
    }
};

int main()
{
    Solution s;
    cout << s.calculateMinimumHP({  {-2,-3,3},
                                    {-5,-10,1},
                                    {10,30,-5}
                                });
            
}