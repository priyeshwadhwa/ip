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
        vector<string> commonChars(vector<string>& A) {

            vector<int> cnt(26,INT_MAX);
            for(auto a : A)
            {
                vector<int> cnt1(26, 0);
                for(auto c : a)
                {
                    cnt1[ c - 'a']++;
                }
                for(int i =0 ;i<26;++i)
                {
                    cnt[i] = min(cnt[i],cnt1[i]);
                }
            }
            vector<string> res;
            for(int i = 0; i < 26; ++i)
            {
                while(cnt[i]-- != 0)
                {
                    res.push_back(string (1, 'a' + i));
                }
            }
            return res;
        }
        
};
TEST_CASE("some_common_chars") {
    Solution s;
    vector<string> test {"hello", "bella"};
    REQUIRE_THAT(s.commonChars(test), Contains(vector<string>{"l","l","e"}));
}

TEST_CASE("no_common_chars") {
    Solution s;
    vector<string> test {"hokko", "bella"};
    REQUIRE_THAT(s.commonChars(test), Equals(vector<string>{}));
}

TEST_CASE("one_common_char") {
    Solution s;
    vector<string> test {"kkkkk", "kkkkk"};
    REQUIRE_THAT(s.commonChars(test), Equals(vector<string>{"k","k","k","k","k"}));
}