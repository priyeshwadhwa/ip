 
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

/*
Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Example 1:

Input: pattern = "abba", str = "dog cat cat dog"
Output: true
Example 2:

Input:pattern = "abba", str = "dog cat cat fish"
Output: false
Example 3:

Input: pattern = "aaaa", str = "dog cat cat dog"
Output: false
Example 4:

Input: pattern = "abba", str = "dog dog dog dog"
Output: false
Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters that may be separated by a single space.
*/

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        
        unordered_map<char, int> p2i;
        unordered_map<string, int> s2i;
        
        int n = pattern.size();
        istringstream iss(str);

        int i = 0;
        for(string word; iss>>word; i++)
        {
            if(i == n || p2i[pattern[i]] != s2i[word])
                return false;
            p2i[pattern[i]] = s2i[word] = i+1; // +1 , because by default the map puts a '0'.. So we don't want to put 0.
        }
        return i == n; // make sure we consumed the whole pattern
    }
};

TEST_CASE("test_simple_success") {
    Solution s;
    string pattern = "abba", str = "dog cat cat dog";

    REQUIRE(s.wordPattern(pattern, str) == true);
}

TEST_CASE("test_simple_failure") {
    Solution s;
    string pattern = "abaa", str = "dog cat cat dog";

    REQUIRE(s.wordPattern(pattern, str) == false);
}

TEST_CASE("test_small_pattern_failure") {
    Solution s;
    string pattern = "aba", str = "dog cat cat dog";

    REQUIRE(s.wordPattern(pattern, str) == false);
}

TEST_CASE("test_multiple_pattern_mapping to same word failure") {
    Solution s;
    string pattern = "ab", str = "dog dog";

    REQUIRE(s.wordPattern(pattern, str) == false);
}

TEST_CASE("test_long_string_failure") {
    Solution s;
    string pattern = "aba", str = "dog cat dog dog";

    REQUIRE(s.wordPattern(pattern, str) == false);
}

TEST_CASE("test_single word string failure") {
    Solution s;
    string pattern = "jquery", str = "jquery";

    REQUIRE(s.wordPattern(pattern, str) == false);
}


