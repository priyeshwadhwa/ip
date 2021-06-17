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
/*
Given three integer arrays arr1, arr2 and arr3 sorted in strictly increasing order,
 return a sorted array of only the integers that appeared in all three arrays.

Example 1:

Input: arr1 = [1,2,3,4,5], arr2 = [1,2,5,7,9], arr3 = [1,3,4,5,8]
Output: [1,5]
Explanation: Only 1 and 5 appeared in the three arrays.
Constraints:

1 <= arr1.length, arr2.length, arr3.length <= 1000
1 <= arr1[i], arr2[i], arr3[i] <= 2000
*/
class Solution{
    public:
        vector<int> intersection_3_way(const vector<int> &A, const vector<int> &B, const vector<int> &C)
        {
            vector<int> res;
            unordered_map<int, int> m;
            for(auto a: A) m[a]++;
            for(auto b: B) m[b]++;
            for(auto c: C) m[c]++;
            for(auto e: m)
            {
                if(e.second == 3)
                    res.push_back(e.first);
            }

            return res;
        }
};

TEST_CASE("intersection_3_way")
{
    Solution s;
    vector<int> A{10, 20, 30, 40, 50}, B{20, 25, 30, 50}, C {10, 20, 30};
    REQUIRE_THAT(s.intersection_3_way(A,B,C), Catch::Equals(std::vector<int>{20, 30} ) );
}