 
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
A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

Write a function to determine if a number is strobogrammatic. The number is represented as a string.

Example 1:

Input: "69"
Output: true
Example 2:

Input: "88"
Output: true
Example 3:

Input: "962"
Output: false
*/

//1 8 96

class Solution {
    public:
    bool isStobogrammatic(string s)
    {
        unordered_map<char, char> m {{'0','0'}, {'1','1'}, {'6','9'}, {'8','8'},{'9','6'}};
        int i = 0;
        int j = s.length()-1;
        while(i <= j) // the = here takes care of case when single char is passed.
        {
            auto r = m.find(s[i]);
            if( r != m.end() &&  r->second == s[j] )
            {
                i++;j--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }

};

TEST_CASE("test_818") {
    Solution s;
    REQUIRE(s.isStobogrammatic("818")==true);
}

TEST_CASE("test_1") {
    Solution s;
    REQUIRE(s.isStobogrammatic("1")==true);
}
TEST_CASE("test_2") {
    Solution s;
    REQUIRE(s.isStobogrammatic("2")==false);
}

TEST_CASE("test_69") {
    Solution s;
    REQUIRE(s.isStobogrammatic("69")==true);
}

TEST_CASE("test_189609681") {
    Solution s;
    REQUIRE(s.isStobogrammatic("189609681")==true);
}

