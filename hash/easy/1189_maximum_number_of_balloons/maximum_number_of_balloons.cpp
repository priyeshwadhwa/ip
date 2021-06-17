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

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> m;
        for(auto c : text)
            m[c]++;
        
        return min({ m['b'], m['a'], m['l']/2, m['o']/2, m['n'] });
    }
};


TEST_CASE("balloons2") {
    Solution s;
    REQUIRE(s.maxNumberOfBalloons("balloonxxddnoollab")==2);
}

TEST_CASE("balloons1") {
    Solution s;
    REQUIRE(s.maxNumberOfBalloons("balloonxxddnoolla")==1);
}

TEST_CASE("balloons0") {
    Solution s;
    REQUIRE(s.maxNumberOfBalloons("alloonxxddnoolla")==0);
}