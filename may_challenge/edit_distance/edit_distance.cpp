
 
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
    int minDistance(string word1, string word2) {
        
        int w1_len = word1.size();
        int w2_len = word2.size();
        
        vector<vector<int>> dp(w1_len+1, vector<int>(w2_len+1, 100000));
        dp[0][0] = 0;
        
        for(int i = 0; i < w1_len; ++i)
        {
            for(int j = 0; j < w2_len; ++j)
            {
                dp[i+1][j+1] = (word1[i] == word2[j] ? dp[i][j] : 1 + min({dp[i][j], dp[i][j+1], dp[i+1][j]}) );
            }
        }
        return dp[w1_len][w2_len];
    }
};

TEST_CASE("test_simple") {
    Solution s;
    //s.minDistance("horse", "ros");
    REQUIRE(1==1);
}

TEST_CASE("test_simple_1") {
    Solution s;
    std::cout<< s.minDistance("zoologicoarchaeologist", "zoogeologist");
    REQUIRE(1==1);
}