 
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



class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        unordered_set<int> m (nums1.begin(), nums1.end());

        vector<int> res;
        copy_if(nums2.begin(), nums2.end(), back_inserter(res),  [&m](auto e)->bool
        {
            return m.find(e)!=m.end();
        });
        return res;
    }
};

TEST_CASE("test_") {
    Solution s;
    vector<int> A{1,2,3,4,5,6,7}, B{4,5,6,7,8,9,10};
    REQUIRE_THAT(s.intersection(A,B), UnorderedEquals(vector<int>{4,5,6,7}));
}

