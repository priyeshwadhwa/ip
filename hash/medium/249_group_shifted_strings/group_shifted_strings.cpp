 
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
Given a string, we can "shift" each of its letter to its successive letter, for example: "abc" -> "bcd". We can keep "shifting" which forms the sequence: 
"abc" -> "bcd" -> ... -> "xyz".

Given a list of strings which contains only lowercase alphabets, group all strings that belong to the same shifting sequence, return:
[
  ["abc","bcd","xyz"],
  ["az","ba"],
  ["acef"],
  ["a","z"]
]
*/

// ace  bdf  
// length(s1) == length(s2)
// s1[i] = s2[i]

// Normalize the strings.. first take the diff from the first char and 'a'. 
//Then subtract diff from all chars and round them if they are falling off the bound. zyx.. 

class Solution {
    public:
    vector<vector<string>> GroupShiftedStrings(vector<string> in)
    {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> m;

        for(auto s : in)
        {
            auto bak = s;
            int diff = s[0] -'a';
            for(int i=0; i < s.length(); ++i)
            {
                if(s[i]-diff < 'a')
                {
                    s[i]=s[i]-diff + 26;
                }
                else 
                {
                    s[i]=s[i] - diff;
                }
            }
            m[s].push_back(bak);
        }

        for(auto e: m)
        {
            res.push_back(e.second);
        }

        return res;
       


    }

};

TEST_CASE("test_success") {
    Solution s;
    vector<string> in {"zyx", "cba","x","a","b", "ab"};
    s.GroupShiftedStrings(in);
}

TEST_CASE("test_failure") {
    Solution s;
    REQUIRE(1==1);
}
