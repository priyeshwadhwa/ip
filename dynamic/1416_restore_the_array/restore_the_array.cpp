 
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
#include "..\..\catch\catch.hpp"
using namespace std;
using namespace Catch;

/* Problem:


*/

class Solution {
    public:

    int numberOfArrays(string s, int k) {
        vector<int> dp(s.size() + 1);
        dp[s.size()] = 1; 
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == '0')
                continue;
            for (long sz = 1, n = 0; i + sz <= s.size(); ++sz) {
                n = n * 10 + s[i + sz - 1] - '0';
                if (n > k)
                    break;
                dp[i] = (dp[i] + dp[i + sz]) % 1000000007;
            }
        }
        return dp[0];
    }

};

TEST_CASE("test_success") {
    Solution s;
    REQUIRE(s.numberOfArrays("100", 20)==8);
}

TEST_CASE("test_failure") {
    Solution s;
    REQUIRE(1==1);
}
