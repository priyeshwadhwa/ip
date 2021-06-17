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
#include <iostream>
#define CATCH_CONFIG_MAIN
#include "..\..\catch\catch.hpp"
using namespace std;
using namespace Catch;

class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {

        regex search {R"(\b)"+ first + " " + second + R"( ([a-zA-Z]+)\b)"};
        vector<string> res;

        smatch sm;
        for(regex_search(text, sm, search);  sm.size() == 2;  text = text.substr(sm.position(1)) , regex_search(text, sm, search) )
        {
            res.push_back(sm.str(1));
            
        }

        return res;
    }
};

TEST_CASE("two_matches") {
    Solution s;
    string text = "we will we will rock you", first = "we", second = "will";
    REQUIRE_THAT(s.findOcurrences(text, first, second), Equals(vector<string> {"we", "rock"} ));
}

TEST_CASE("no_matches") {
    Solution s;
    string text = "we will we will rock you", first = "wee", second = "will";
    REQUIRE_THAT(s.findOcurrences(text, first, second), Equals(vector<string> {} ));
}

TEST_CASE("fail_case") {
    Solution s;
    string text = "alice is aa good girl she is a good student", first = "a", second = "good";
    REQUIRE_THAT(s.findOcurrences(text, first, second), Equals(vector<string> {"student"} ));
}
