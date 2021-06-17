 
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
    int distributeCandies(vector<int>& candies) {
        return min( unordered_set<int>(candies.begin(),candies.end()).size(), candies.size()/2 );
    }
};


TEST_CASE("test_unique_equal_distribution") {
    Solution s;
    vector<int> candies{1,1,2,2,3,3};
    REQUIRE(s.distributeCandies(candies) == 3);
}


TEST_CASE("test_all_unique_candies") {
    Solution s;
    vector<int> candies{1,2,3,4};
    REQUIRE(s.distributeCandies(candies) == 2);
}

TEST_CASE("test_many_unique_candies") {
    Solution s;
    vector<int> candies{1,1,1,2,2,2,3,3,3,4,4,4};
    REQUIRE(s.distributeCandies(candies) == 4);
}

TEST_CASE("test_single_kind") {
    Solution s;
    vector<int> candies{1,1,1,1,1};
    REQUIRE(s.distributeCandies(candies) == 1);
}


