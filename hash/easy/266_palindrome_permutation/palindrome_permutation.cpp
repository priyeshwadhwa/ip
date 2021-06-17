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
/*
Given a string, determine if a permutation of the string could form a palindrome.

Example 1:

Input: "code"
Output: false
Example 2:

Input: "aab"
Output: true
Example 3:

Input: "carerac"
Output: true
*/
class Solution {
    public:
        bool palindrome_permutation(string s)
        {
            unordered_map<char, int> m;
            for(auto c : s) m[c]++;
            bool odd = false;
            for(auto e : m )
            {
                if(e.second % 2 == 0)
                    continue;
                else if(odd==false)
                    odd = true;
                else
                    return false;
            }
            return true;
        }
};

TEST_CASE("non_palindrome_2oddchars") {
    Solution s;
    REQUIRE(s.palindrome_permutation("aaedddbb")==false);
}

TEST_CASE("one_char") {
    Solution s;
    REQUIRE(s.palindrome_permutation("a")==true);
}