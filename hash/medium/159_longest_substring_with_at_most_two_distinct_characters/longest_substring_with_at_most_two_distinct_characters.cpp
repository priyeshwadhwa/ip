 
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


/*
Given a string, find the length of the longest substring T that contains at most 2 distinct characters.
For example, Given s = “eceba”,
T is "ece" which its length is 3.
 */

/**
 * Using Sliding Window Template
 * Detail explanation about the template is here:
 * https://github.com/cherryljr/LeetCode/blob/master/Sliding%20Window%20Template.java
 *
 * Here is a similar question in LintCode (Just be different from k and two):
 * https://www.lintcode.com/problem/longest-substring-with-at-most-k-distinct-characters/description
 */


class Solution {
    public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        vector<int> count(256,0);
        int i = 0, numDistinct = 0, maxLen = 0;
        for (int j = 0; j < s.length(); j++) {
            if (count[s[j]] == 0)  // if this is a new char
                numDistinct++;
            count[s[j]]++;      //bump the char freq
            while (numDistinct > 2) {
                count[s[i]]--;
                if (count[s[i]] == 0) 
                    numDistinct--;
                i++;
            }
            maxLen = max(j - i + 1, maxLen); //get the max so far
      }
   return maxLen;
}

};

TEST_CASE("test_success") {
    Solution s;
    REQUIRE(s.lengthOfLongestSubstringTwoDistinct("aaabbbc") == 6);
}

TEST_CASE("test_failure") {
    Solution s;
    REQUIRE(1==1);
}
