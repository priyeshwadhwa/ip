
/** the solution below is done using DP , but it fails for some vaue of m,n 
 * s.tilingRectangle(13,11). expected 6, returns 8
 * 
 * The correct solution is done using backtracking. need to learn it.
 * 
 * 
 */

#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>

using namespace std;

class Solution {
public:
    int tilingRectangle(int n, int m) {
        if (m ==n ) return 1;
        if(m==0||n==0) return 0;
        if(m==1) return n;
        if(n==1) return m;

        vector<vector<int>> dp(n+1);
        for(auto& v: dp)
            v= vector<int>(m+1, m*n);

        for(int i = 1; i<= min(n,m); ++i)
            dp[i][i] = 1;


        for(int i = 0; i <= n; ++i) dp[i][0] = 0;
        for(int i = 0; i <= m; ++i) dp[0][i] = 0;

        for(int i = 1; i <= n; ++i) dp[i][1] = i;
        for(int i = 1; i <= m; ++i) dp[1][i] = i;


        for(int i = 2; i <= n; ++i)
        {
            for(int j = 2; j <= m; ++j)
            {
                for(int i1 = 1; i1 <= i; ++i1)
                {
                    for(int j1 = 1; j1 <= j; ++j1)
                    {
                        dp[i][j] = min({dp[i][j],
                                        dp[i1][j1] + dp[i1][j-j1] + dp[i-i1][j],
                                        dp[i1][j1] + dp[i-i1][j1] + dp[i][j-j1]
                                         });
                        cout << "dp["<<i<<"]["<<j<<"] = " <<dp[i][j] << endl;
                    }
                }
            }
        }
        return dp[n][m];
    }
};

int main()
{
    Solution s;
    //cout<< s.tilingRectangle(5,8)<< endl;
    //cout<< s.tilingRectangle(2,3) << endl;
    cout<< s.tilingRectangle(13,11) << endl;
}