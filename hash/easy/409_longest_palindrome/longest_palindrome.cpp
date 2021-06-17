 
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
Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.

Note:
Assume the length of given string will not exceed 1,010.

Example:

Input:
"abccccdd"

Output:
7

Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.
*/

class Solution {
public:
    int longestPalindrome(string s) {
        int m[128] = {0}; // use a map to store the char count
        for(auto c : s)
            m[c]++;

        int sum = 0;
        int odd_count = 0;
        for(int i = 0; i < 128; ++i)
        {
            if(m[i]!=0) 
            {
                if( m[i]%2 == 0)//even occurences goes in totally.
                    sum += m[i];
                else {
                    sum += m[i]-1; // odd occurences goes 1 less.
                    odd_count++;
                }
            }
        }
        return sum + (odd_count>0?1:0); // for odd occurences, we can take 1 more char for the center
    }
};

TEST_CASE("test_") {
    Solution s;
    
    REQUIRE(s.longestPalindrome("aabbccddeeABCDfff")==13);
}

//abccccdd
TEST_CASE("test_abccccdd") {
    Solution s;
    
    REQUIRE(s.longestPalindrome("abccccdd")==7);
}

TEST_CASE("test_bb") {
    Solution s;
    
    REQUIRE(s.longestPalindrome("bb")==2);
}


TEST_CASE("test_long_string") {
    Solution s;
    
    REQUIRE(s.longestPalindrome("civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth")==983);
}

TEST_CASE("test_single_char") {
    Solution s;
    
    REQUIRE(s.longestPalindrome("a")==1);
}