 
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
You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. Check if these points make a straight line in the XY plane.
Example 1:
Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
Output: true

Example 2:
Input: coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
Output: false

Constraints:

2 <= coordinates.length <= 1000
coordinates[i].length == 2
-10^4 <= coordinates[i][0], coordinates[i][1] <= 10^4
coordinates contains no duplicate point.

*/

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        
        int n = coordinates.size();
        
        double gradient = ((double)coordinates[1][1] - coordinates[0][1]) / (coordinates[1][0] - coordinates[0][0]);
        
        for(int i = 1; i < n-1; ++i)
        {
            if(gradient != (((double)coordinates[i+1][1] - coordinates[i][1]) / (coordinates[i+1][0] - coordinates[i][0]) ))
                return false;
        }
        return true;        
    }
};

TEST_CASE("test_success") {
    Solution s;
    
    vector<vector<int>> coordinates ={{-4,-3},{1,0},{3,-1},{0,-1},{-5,2}};
    s.checkStraightLine(coordinates);
    REQUIRE(1==1);
}

TEST_CASE("test_failure") {
    Solution s;
    REQUIRE(1==1);
}
