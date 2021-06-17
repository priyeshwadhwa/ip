 
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


*/

class NumMatrix {
    vector<vector<int>> range_sum;
    int m, n;
public:
    NumMatrix(vector<vector<int>> matrix) {
        m = matrix.size();
        n = matrix[0].size();
        range_sum = vector<vector<int>>(m+1, vector<int>(n+1, 0));
        
        for(int i = 0; i < m ; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                range_sum[i+1][j+1] = range_sum[i][j+1] + range_sum[i+1][j] - range_sum[i][j] + matrix[i][j];
            }
        }
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        row2++; col2++;
        return range_sum[row2][col2] - range_sum[row1][col2] - range_sum[row2][col1] + range_sum[row1][col1];
    }
};


TEST_CASE("test_success") {

    //["NumMatrix","sumRegion"]
    //[[[[-4,-5]]],[0,1,0,1]]
    NumMatrix s({{-4,-5}});
    REQUIRE(s.sumRegion(0,1,0,1) == -5);
}

TEST_CASE("test_failure") {
    //NumMatrix s;
    REQUIRE(1==1);
}
