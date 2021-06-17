 
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
Find the minimum length word from a given dictionary words, which has all the letters from the string licensePlate. Such a word is said to complete the given string licensePlate

Here, for letters we ignore case. For example, "P" on the licensePlate still matches "p" on the word.

It is guaranteed an answer exists. If there are multiple answers, return the one that occurs first in the array.

The license plate might have the same letter occurring multiple times. For example, given a licensePlate of "PP", the word "pair" does not complete the licensePlate, but the word "supper" does.

Example 1:
Input: licensePlate = "1s3 PSt", words = ["step", "steps", "stripe", "stepple"]
Output: "steps"
Explanation: The smallest length word that contains the letters "S", "P", "S", and "T".
Note that the answer is not "step", because the letter "s" must occur in the word twice.
Also note that we ignored case for the purposes of comparing whether a letter exists in the word.
Example 2:
Input: licensePlate = "1s3 456", words = ["looks", "pest", "stew", "show"]
Output: "pest"
Explanation: There are 3 smallest length words that contains the letters "s".
We return the one that occurred first.
Note:
licensePlate will be a string with length in range [1, 7].
licensePlate will contain digits, spaces, or letters (uppercase or lowercase).
words will have a length in the range [10, 1000].
Every words[i] will consist of lowercase letters, and have length in range [1, 15].
*/

class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {

        vector<int> m(26,0);
        for(auto c:licensePlate)
        {
            if(std::isalpha(c))
                m[tolower(c)-'a']++;
        }

        int curr_len = INT_MAX;
        string res;

        for(auto w : words)
        {
            if(w.length() >= curr_len)
                continue;
            
            vector<int> n(26,0);
            for(auto c: w) 
                n[tolower(c)-'a']++;
            
            bool match = true;
            for(int i = 0; i < 26; i++)
            {
                if(n[i] < m[i])
                {
                    match = false;
                    break;
                }
            }
            if(match)
            {
                res=w;
                curr_len = w.length();
            }
        }
        return res;
    }
};

TEST_CASE("test_") {
    Solution s;
    string licensePlate = "1s3 PSt";
    vector<string> words {"step", "steps", "stripe", "stepple"};
    REQUIRE(s.shortestCompletingWord(licensePlate, words) == "steps");
}

