 
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
You are playing the following Bulls and Cows game with your friend: You write down a number and ask your friend to guess what the number is. Each time your friend makes a guess, you provide a hint that indicates how many digits in said guess match your secret number exactly in both digit and position (called "bulls") and how many digits match the secret number but locate in the wrong position (called "cows"). Your friend will use successive guesses and hints to eventually derive the secret number.

Write a function to return a hint according to the secret number and friend's guess, use A to indicate the bulls and B to indicate the cows. 

Please note that both secret number and friend's guess may contain duplicate digits.

Example 1:

Input: secret = "1807", guess = "7810"

Output: "1A3B"

Explanation: 1 bull and 3 cows. The bull is 8, the cows are 0, 1 and 7.
Example 2:

Input: secret = "1123", guess = "0111"

Output: "1A1B"

Explanation: The 1st 1 in friend's guess is a bull, the 2nd or 3rd 1 is a cow.
*/


class Solution {
public:
    string getHint(string secret, string guess) {

        // secret == 1807 8 810  8 
        
        // secret == 1123 0111     

        // secret == 1923 0111   

        // first match for the bulls. remove all matches
        // 
        int s[10] = {0}, g[10] = {0};
        
        int bulls = 0, cows = 0;

        for(int i = 0; i < secret.size(); ++i)
        {
            if(secret[i] == guess[i]) 
                bulls++;
            else
            {
                s[secret[i] - '0']++;
                g[guess[i] - '0']++;
            }
            
        }

        for(int i = 0; i < 10; ++i)
        {
            cows += min(s[i], g[i]);
        }
        return to_string(bulls) + "A" + to_string(cows)+"B";
    }
};

TEST_CASE("test_") {
    Solution s;
    REQUIRE(s.getHint("1807", "7810") == "1A3B");
}

TEST_CASE("test_1") {
    Solution s;
    REQUIRE(s.getHint("1123", "0111") == "1A1B");
}


