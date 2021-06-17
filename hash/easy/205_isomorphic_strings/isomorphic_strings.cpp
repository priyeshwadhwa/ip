 
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
Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

Example 1:

Input: s = "egg", t = "add"
Output: true
Example 2:

Input: s = "foo", t = "bar"
Output: false
Example 3:

Input: s = "paper", t = "title"
Output: true
Note:
You may assume both s and t have the same length.
*/

class Solution {
public:


        /// This is incorrect code we have mapping that goes only one way.. we need to take care of other side too.
        // Test case : ab aa . a->a b->a all good.
    bool isIsomorphic(string s, string t) {

        unordered_map<char, char> m; // map char in s to char in t.
        int n = s.size();
        for(int i=0; i< n ; ++i)
        {
            auto f = m.find(s[i]);
            if( f != m.end())
            {
                if(f->second != t[i]) return false;
            }
            else
            {
                m[s[i]] = t[i];
            }
        }
        return true;
    }



/*
The idea is that we need to map a char to another one, for example, "egg" and "add", we need to constract the mapping 'e' -> 'a' and 'g' -> 'd'. 
Instead of directly mapping 'e' to 'a', another way is to mark them with same value, for example, 'e' -> 1, 'a'-> 1, and 'g' -> 2, 'd' -> 2, this works same.

So we use two arrays here m1 and m2, initialized space is 256 (Since the whole ASCII size is 256, 128 also works here). 
Traverse the character of both s and t on the same position, if their mapping values in m1 and m2 are different, means they are not mapping correctly, returen false; 
else we construct the mapping, since m1 and m2 are both initialized as 0, we want to use a new value when i == 0, so i + 1 works here.
*/
    bool isIsomorphic_without_map(string s, string t) {
        int m1[128] = {0}, m2[128] = {0}, n = s.size();
        for (int i = 0; i < n; ++i) {
            if (m1[s[i]] != m2[t[i]]) return false;
            m1[s[i]] = i+1;
            m2[t[i]] = i+1;
        }
        return true;
    }

};

TEST_CASE("test_") {
    Solution s;
    REQUIRE(s.isIsomorphic_without_map("egg","add") == true);
}

TEST_CASE("test_1") {
    Solution s;
    REQUIRE(s.isIsomorphic_without_map("title","paper") == true);
}
TEST_CASE("test_false") {
    Solution s;
    REQUIRE(s.isIsomorphic_without_map("ab","aa") == false);
}