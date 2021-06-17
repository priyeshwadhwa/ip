 
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
Given two sentences words1, words2 (each represented as an array of strings), and a list of similar word pairs pairs, determine if two sentences are similar.
For example, "great acting skills" and "fine drama talent" are similar, if the similar word pairs are pairs = [["great", "fine"], ["acting","drama"], ["skills","talent"]].
Note that the similarity relation is not transitive. For example, if "great" and "fine" are similar, and "fine" and "good" are similar, "great" and "good" are not necessarily similar.
However, similarity is symmetric. For example, "great" and "fine" being similar is the same as "fine" and "great" being similar.
Also, a word is always similar with itself. For example, the sentences words1 = ["great"], words2 = ["great"], pairs = [] are similar, even though there are no specified similar word pairs.
Finally, sentences can only be similar if they have the same number of words. So a sentence like words1 = ["great"] can never be similar to words2 = ["doubleplus","good"].
Note:

The length of words1 and words2 will not exceed 1000.
The length of pairs will not exceed 2000.
The length of each pairs[i] will be 2.
The length of each words[i] and pairs[i][j] will be in the range [1, 20].
*/

class Solution {
    public:
    bool isSimilar(vector<string> &words1, vector<string> &words2, vector<pair<string, string>> &match)
    {
        int w1_len = words1.size();
        int w2_len = words2.size();
        if(w1_len != w2_len)
            return false;

        unordered_map<string, string> m;
        for(auto e : match)
        {
            m[e.first]=e.second;
            //m[e.second]=e.first;
        }


        for(int i = 0; i < w1_len; i++)
        {
            auto w1 = words1[i], w2 = words2[i];
            if(m[w1] != w2 && w1!=w2 && m[w2]!=w1)
            {
                return false;
            }
        }
        
        return true;
    }

};

TEST_CASE("test_") {
    Solution s;
    vector<string> w1{"great", "acting", "skills"} , w2{"great", "drama", "talent"};
    vector<pair<string, string>> match  { {"great", "fine"}, {"acting","drama"}, {"skills","talent"}  };
    REQUIRE(s.isSimilar(w1, w2, match) == true);
}


TEST_CASE("test_nomatch") {
    Solution s;
    vector<string> w1{"great", "acting", "skills"} , w2{"fine", "drama", "talent"};
    vector<pair<string, string>> match  { {"great", "super"}, {"acting","drama"}, {"skills","talent"}  };
    REQUIRE(s.isSimilar(w1, w2, match) == false);
}
