 
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
Given a m * n matrix mat and an integer K, return a matrix answer where each answer[i][j] is the sum of all elements mat[r][c] for i - K <= r <= i + K, j - K <= c <= j + K, and 
(r, c) is a valid position in the matrix.
 

Example 1:

Input: mat = [[1,2,3],[4,5,6],[7,8,9]], K = 1
Output: [[12,21,16],[27,45,33],[24,39,28]]
Example 2:

Input: mat = [[1,2,3],[4,5,6],[7,8,9]], K = 2
Output: [[45,45,45],[45,45,45],[45,45,45]]
 

Constraints:

m == mat.length
n == mat[i].length
1 <= m, n, K <= 100
1 <= mat[i][j] <= 100


If you need more practice with range/prefix sum, please refer to:
304. Range Sum Query 2D - Immutable
307. Range Sum Query - Mutable
308. Range Sum Query 2D - Mutable: Premium

*/

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        
        int m = mat.size();
        int n = mat[0].size();
        
        auto range_sum = vector<vector<int>> (m+1, vector<int>(n+1,0));
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                range_sum[i+1][j+1] = range_sum[i][j+1] + range_sum[i+1][j] - range_sum[i][j] + mat[i][j];
            }
        }
        
        //auto ans = vector<vector<int>> (m, vector<int>(n, 0));
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                int r1 = max(0, i-K), c1 =max(0,j-K), r2 = min(m, i+K+1) ,c2 = min(n, j+K+1);
                mat[i][j] = range_sum[r2][c2] - range_sum[r1][c2] - range_sum[r2][c1] + range_sum[r1][c1];
            }
        }
        
        return mat;
    }
};

TEST_CASE("test_success") {
    Solution s;
    vector<vector<int>> test = {{1,2,3},{4,5,6},{7,8,9}};
    int K = 1;
    s.matrixBlockSum(test, K);
    REQUIRE(1==1);
}

TEST_CASE("test_failure") {
    Solution s;
    REQUIRE(1==1);
}
