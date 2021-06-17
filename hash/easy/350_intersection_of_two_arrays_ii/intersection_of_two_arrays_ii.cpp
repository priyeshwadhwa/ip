 
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
Given two arrays, write a function to compute their intersection.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Note:

Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.
Follow up:

What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to nums2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
*/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_map<int, int> m;
        for(auto n: nums1) m[n]++;

        for(auto n: nums2) 
        {
            if(m[n] > 0)
            {
                res.push_back(n);
                m[n]--;
            }
        }
        return res;

    }
};

TEST_CASE("test_") {
    Solution s;
    vector<int> nums1{1,1,2,3,2,3,4,4,4}, nums2{1,1,1,2,3,4};
    REQUIRE_THAT(s.intersect(nums1,nums2), UnorderedEquals(vector<int>{1,1,2,3,4}));
}

