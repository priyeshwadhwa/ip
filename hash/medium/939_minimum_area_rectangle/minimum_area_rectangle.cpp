 
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
Given a set of points in the xy-plane, determine the minimum area of a rectangle formed from these points, with sides parallel to the x and y axes.

If there isn't any rectangle, return 0.

 

Example 1:

Input: [[1,1],[1,3],[3,1],[3,3],[2,2]]
Output: 4
Example 2:

Input: [[1,1],[1,3],[3,1],[3,3],[4,1],[4,3]]
Output: 2
 

Note:

1 <= points.length <= 500
0 <= points[i][0] <= 40000
0 <= points[i][1] <= 40000
All points are distinct.
*/

class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_map<int, set<int>> m;
        
        int res = INT_MAX;
        
        for(auto p : points)
            m[p[0]].insert(p[1]);

        for(auto i = m.begin(); i != m.end(); ++i)
        {
            for(auto j = next(i); j != m.end(); ++j)
            {
                if(i->second.size() < 2 || j->second.size() < 2) continue;
                vector<int> y;
                set_intersection(i->second.begin(), i->second.end(), j->second.begin(), j->second.end(), back_inserter(y));
                for(auto k = y.begin()+1; k < y.end(); k++)
                    res = min(res, abs(j->first - i->first) * abs(*k - *(k-1)) );
            }
        }
        return res;
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
