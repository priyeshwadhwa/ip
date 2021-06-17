 
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
Given a list of strings words representing an English Dictionary, find the longest word in words that can be built one character at a time by other words in words. If there is more than one possible answer, return the longest word with the smallest lexicographical order.

If there is no answer, return the empty string.
Example 1:
Input: 
words = ["w","wo","wor","worl", "world"]
Output: "world"
Explanation: 
The word "world" can be built one character at a time by "w", "wo", "wor", and "worl".
Example 2:
Input: 
words = ["a", "banana", "app", "appl", "ap", "apply", "apple"]
Output: "apple"
Explanation: 
Both "apply" and "apple" can be built from other words in the dictionary. However, "apple" is lexicographically smaller than "apply".
Note:

All the strings in the input will only contain lowercase letters.
The length of words will be in the range [1, 1000].
The length of words[i] will be in the range [1, 30].
*/

class Solution {
public:
    string longestWord(vector<string>& words) {
        
        //make a trie with all the strings. 
        // search all the prefix substrings in the trie.
        // longest word that matches 
        
        
        // put all the strings in the map
        // search all the prefix substrings in the map
        // longest word that matches is our ans.
        // if samelength word is found make sure its lexicographically smaller
        
        sort(words.begin(), words.end());
        unordered_set<string> m;
        string curr_max;
        for(auto w : words)
        {
            if(w.length()==1 || m.find(w.substr(0,w.length()-1)) != m.end())
            {
                if(curr_max.length() < w.length())
                {
                    curr_max = w;
                }
                m.insert(w);
            }
        }
        return curr_max;
    }
};

TEST_CASE("test_lexi") {
    Solution s;
    vector<string> words{"a", "banana", "app", "appl", "ap", "apply", "apple"};
    REQUIRE(s.longestWord(words) == "apple");
}

TEST_CASE("test_success") {
    Solution s;
    vector<string> words{"w","wo","wor","worl", "world"};
    REQUIRE(s.longestWord(words) == "world");
}



