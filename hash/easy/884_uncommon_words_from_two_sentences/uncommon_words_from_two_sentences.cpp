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
    vector<string> uncommonFromSentences(string A, string B) {
        
        unordered_map<string, int> m;
        istringstream iss(A+" "+B);
        string t;
        while(iss >> t) m[t]++;
        // smatch sm;
        // regex re{R"(\w+)"};
        // for( regex_search(A, sm, re); sm.size() == 1; A = sm.suffix(), regex_search(A,sm,re) ) 
        // {
        //     m[sm.str()]++;
        // }
        // for( regex_search(B, sm, re); sm.size() == 1; B = sm.suffix(), regex_search(B,sm,re) ) 
        // {
        //     m[sm.str()]++;
        // }
        vector<string> res;

        for(auto e :m)
        {
            if(e.second == 1 )
                res.push_back(e.first);
        }
        return res;
    }
};

TEST_CASE("description") {
    Solution s;
    string A = "this apple is sweet", B = "this apple is sour";
    REQUIRE_THAT(s.uncommonFromSentences(A,B), Equals(vector<string>{"sweet", "sour"} ) );
}



TEST_CASE("no_match") {
    Solution s;
    string A = "this apple is sweet", B = "this apple is sweet";
    REQUIRE_THAT(s.uncommonFromSentences(A,B), Equals(vector<string>{} ) );
}

// TEST_CASE("full_match") {
//     Solution s;
//     string A = "this apple is sweet", B = "thes applee iss sweett";
//     REQUIRE_THAT(s.uncommonFromSentences(A,B), Equals(vector<string>{} ) );
// }