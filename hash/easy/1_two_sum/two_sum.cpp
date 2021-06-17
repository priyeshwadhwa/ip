 
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
#include "../../../catch/catch.hpp"
using namespace std;
using namespace Catch;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m; // num, index_in_array
        
        int i = 0;
        for(auto n: nums)
        {
            m[n]=i++;
        }
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(m.find(target-nums[i]) != m.end() && m[target-nums[i]] != i)
            {
                return {i, m[target-nums[i]]};
            }
        }
        return {};
    }
};

TEST_CASE("test_") {
    Solution s;
    vector<int> test{1,4,5,6};
    REQUIRE_THAT(s.twoSum(test, 9), UnorderedEquals(vector<int>{1,2}));
}

TEST_CASE("test_sum_6_by_adding_same_number") {
    Solution s;
    vector<int> test{3,5,1};
    REQUIRE_THAT(s.twoSum(test, 6), UnorderedEquals(vector<int>{1,2}));
}


