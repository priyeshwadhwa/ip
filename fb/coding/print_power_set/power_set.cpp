 
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

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        result.push_back({});
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int size = result.size();
            for (int j = 0; j < size; j++) {
                auto s = result[j];
                s.push_back(nums[i]);
                result.push_back(s);
            }
        }
        return result;
    }
}; 

TEST_CASE("test_success") {
    Solution s;
    vector<int> n{1,2,3};
    s.subsets(n);
}


TEST_CASE("test_failure") {
    Solution s;
    REQUIRE(1==1);
}
