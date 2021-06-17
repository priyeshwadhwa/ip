 
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
Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the
 absolute difference between i and j is at most k.

Example 1:

Input: nums = [1,2,3,1], k = 3
Output: true
Example 2:

Input: nums = [1,0,1,1], k = 1
Output: true
Example 3:

Input: nums = [1,2,3,1,2,3], k = 2
Output: false
*/


class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(int i = 0; i < nums.size(); ++i)
        {
            auto f = m.find(nums[i]);
            if(f != m.end())
            {
                if(i - f->second <= k)
                    return true;
            }
            m[nums[i]] = i;
        }
        return false;
    }
};

TEST_CASE("test_1") {
    Solution s;
    vector<int> nums{1,2,3,1};
    REQUIRE(s.containsNearbyDuplicate(nums, 3)== true);
}


TEST_CASE("test_2") {
    Solution s;
    vector<int> nums{1,0,1,1};
    REQUIRE(s.containsNearbyDuplicate(nums, 1)== true);
}

TEST_CASE("test_3") {
    Solution s;
    vector<int> nums{1,0,4,1};
    REQUIRE(s.containsNearbyDuplicate(nums, 2)== false);
}

TEST_CASE("test_4") {
    Solution s;
    vector<int> nums{1,2,3,1,2,3};
    REQUIRE(s.containsNearbyDuplicate(nums, 2)== false);
}