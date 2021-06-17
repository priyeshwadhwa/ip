 
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
#include "..\..\..\catch\catch.hpp"
using namespace std;
using namespace Catch;

/* 
Given two integer arrays A and B, return the maximum length of an subarray that appears in both arrays.

Example 1:

Input:
A: [1,2,3,2,1]
B: [3,2,1,4,7]
Output: 3
Explanation: 
The repeated subarray with maximum length is [3, 2, 1].
 

Note:

1 <= len(A), len(B) <= 1000
0 <= A[i], B[i] < 100
*/

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int m = A.size();
        int n = B.size();
        vector<vector<int>> dp (m+1, vector<int>(n+1,0));
        int max_len = 0;
        
        for(int i = 1 ; i <= m; ++i)
        {
            for(int j = 1; j <= n; ++j)
            {
                if(A[i-1] == B[j-1]) 
                {
                    dp[i][j] = dp[i-1][j-1] + 1;
                    max_len = max(max_len, dp[i][j]);
                }
            }
        }
        return max_len;
    }
};

TEST_CASE("test_success") {
    Solution s;
    REQUIRE(1==1);
}

TEST_CASE("test_failure") {
    Solution s;
    REQUIRE(1==1);
}
