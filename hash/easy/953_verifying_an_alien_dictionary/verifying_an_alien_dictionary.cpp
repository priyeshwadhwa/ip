 
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


class Solution {
public:
    bool isAlienSorted_(vector<string>& words, string order) {
        unordered_map<char,int> order_map;
        int i = 0;
        for(auto c : order)
            order_map[c] = i++;

        auto comp = [&order_map](const string& s1, const string& s2)
        {
            auto len = min(s1.length(), s2.length());
            int equal=0;
            for(int i = 0; i < len ; ++i )
            {
                if(order_map[s1[i]] > order_map[s2[i]])
                    return false;
                else if(order_map[s1[i]] == order_map[s2[i]])
                {
                    equal++;
                }
                else if(order_map[s1[i]] < order_map[s2[i]])
                    return true;
            }
            if(len==equal && s1.length() > s2.length())
                return false;

            return true;
        };

        return is_sorted(words.begin(), words.end(), comp);
    }

       bool isAlienSorted(vector<string> words, string order) {
        int mapping[26];
        for (int i = 0; i < 26; i++)
            mapping[order[i] - 'a'] = i;
        for (string &w : words)
            for (char &c : w)
                c = mapping[c - 'a'];
        return is_sorted(words.begin(), words.end());
    }
};

TEST_CASE("test_") {
    Solution s;
    vector<string> words{"orwd","ow"};
    string order{"worldabcefghijkmnpqstuvxyz"};
    REQUIRE(s.isAlienSorted(words, order) == false);
}


TEST_CASE("test_2") {
    Solution s;
    vector<string> words{"iekm","tpnhnbe"};
    string order{"loxbzapnmstkhijfcuqdewyvrg"};
    REQUIRE(s.isAlienSorted(words, order) == false);
}

TEST_CASE("string_with_null_chars_length")
{
    std::string s{"abcd"};
    s[0]='\0';
    REQUIRE(s.length() == 4);
}


