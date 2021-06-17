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
#include <iostream>
#define CATCH_CONFIG_MAIN
#include "..\..\catch\catch.hpp"
using namespace std;
using namespace Catch;


/*
Given an array of integers A, return the largest integer that only occurs once. If no integer occurs once, return -1.

Example 1:
Input: [5,7,3,9,4,9,8,3,1]
Output: 8
Explanation:
The maximum integer in the array is 9 but it is repeated. The number 8 occurs only once, so it’s the answer.

Example 2:
Input: [9,9,8,8]
Output: -1

Explanation:
There is no number that occurs only once.

Note:
1 <= A.length <= 2000
0 <= A[i] <= 1000

*/
class Solution {
    public:
        int largest_unique(vector<int>& nums)
        {
            multiset<int> m;
            for(auto n : nums)
            {
                m.insert(n);
            }
            int res = -1;
            for(auto n : nums)
            {
                if(m.count(n) == 1)
                {
                    res = max(res, n);
                }
            }
            return res;
        }
        
};

TEST_CASE("no_unique_largest") {
    Solution s;
    vector<int> test {9,9,8,8};
    REQUIRE(s.largest_unique(test) == -1);
}

TEST_CASE("one_unique_largest") {
    Solution s;
    vector<int> test {9,9,8,8,19};
    REQUIRE(s.largest_unique(test) == 19);
}

TEST_CASE("many_unique_largest") {
    Solution s;
    vector<int> test {9,9,8,8,17,14,19};
    REQUIRE(s.largest_unique(test) == 19);
}
