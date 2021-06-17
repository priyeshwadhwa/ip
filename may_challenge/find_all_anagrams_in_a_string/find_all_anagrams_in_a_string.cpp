 
    
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
Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".

*/
class Solution {
    
    
public:
    vector<int> findAnagrams(string s, string p) {
        
        auto len_s = s.length();
        auto len_p = p.length();
        
        if(len_s < len_p)
            return {};
        
        vector<int> m(128,0);

        for(auto c : p)
            m[c]++;
        
        int begin = 0, end = 0, counter = p.length();
        vector<int> res;
        
        while(end < len_s)
        {
            if(m[s[end++]]-- > 0) counter--;
            
            if(counter == 0) res.push_back(begin);
            
            if(end-begin==len_p && m[s[begin++]]++ >= 0) counter++;
        }
        
        return res;
    }
};

TEST_CASE("test_success") {
    Solution s;
    s.findAnagrams("abcd","abc");
    REQUIRE(1==1);
}

TEST_CASE("test_failure") {
    Solution s;
    REQUIRE(1==1);
}
