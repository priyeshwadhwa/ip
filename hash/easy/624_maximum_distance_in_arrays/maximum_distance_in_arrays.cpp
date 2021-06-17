 
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


/*Given m arrays, and each array is sorted in ascending order. Now you can pick up two integers from two different arrays (each array picks one) and calculate the distance. We define the distance between two integers a and b to be their absolute difference |a-b|. Your task is to find the maximum distance.

Example 1:
Input: 
[[1,2,3],
 [4,5],
 [1,2,3]]
Output: 4
Explanation: 
One way to reach the maximum distance 4 is to pick 1 in the first or third array and pick 5 in the second array.
Note:
Each given array will have at least 1 number. There will be at least two non-empty arrays.
The total number of the integers in all the m arrays will be in the range of [2, 10000].
The integers in the m arrays will be in the range of [-10000, 10000].
*/


class Solution {
    public:
    int maxDistance(vector<vector<int>> &arr)
    {
        // save curr_min and curr_max and then iterate over the array updaing the res = max ( res, max( arr_max-curr_min, curr_max-arr_min ))
        // curr_min = min( curr_min, arr_min)
        // curr_max = max(curr_max, arr_max)

        int m = arr.size();

        int curr_min = arr[0][0], curr_max = arr[0][arr[0].size() -1];
        int res = 0;
        for(int i = 1; i < m; ++i)
        {
            res = max(res, max( abs(curr_max - arr[i][0]), abs(arr[i][arr[i].size()-1] - curr_min) ) );
            curr_min = min(curr_min, arr[i][0]);
            curr_max = max(curr_max, arr[i][arr[i].size()-1]);
        }
        return res;
    }

};

TEST_CASE("test_") {
    Solution s;
    vector<vector<int>> t = {   {4,5},
                                {-1,2,3,17},
                                {1,2,3}};
    REQUIRE(s.maxDistance(t) == 16);
}

