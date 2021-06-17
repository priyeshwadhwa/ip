 
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
#include <iostream>
#define CATCH_CONFIG_MAIN
#include "..\..\catch\catch.hpp"
using namespace std;
using namespace Catch;

/*
Given n points in the plane that are all pairwise distinct, a "boomerang" is a tuple of points (i, j, k) such that the distance between i and j equals the distance between i and k (the order of the tuple matters).

Find the number of boomerangs. You may assume that n will be at most 500 and coordinates of points are all in the range [-10000, 10000] (inclusive).

Example:

Input:
[[0,0],[1,0],[2,0]]

Output:
2

Explanation:
The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]]
*/

class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {

        int res = 0;
        
        for(int i = 0; i < points.size(); ++i)
        {
            
            // dist, #num_points
            unordered_map<uint64_t, int > m;
            for(int j = 0; j < points.size(); ++j)
            {
                if(i==j) continue;

                uint64_t dist = (points[i][0] - points[j][0]) * (points[i][0] - points[j][0]) +
                                (points[i][1] - points[j][1]) * (points[i][1] - points[j][1]);
                m[dist]++;
            }
            for(auto e : m)
            {
                // two places filled with e.second . nC2
                if(e.second > 1)
                    res+= (e.second * (e.second -1));
            }
        }
        return res;
    }
};

TEST_CASE("test_") {
    Solution s;
    vector<vector<int>> points = {{0,0},{1,0},{2,0}};
    REQUIRE(s.numberOfBoomerangs(points) == 2);
}

