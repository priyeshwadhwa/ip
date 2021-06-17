 
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
Given a list of daily temperatures T, return a list such that, for each day in the input, tells you how many days you would have to wait until a warmer temperature. If there is no future day for which this is possible, put 0 instead.

For example, given the list of temperatures T = [73, 74, 75, 71, 69, 72, 76, 73], your output should be [1, 1, 4, 2, 1, 1, 0, 0].

Note: The length of temperatures will be in the range [1, 30000]. Each temperature will be an integer in the range [30, 100].
*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {

        stack<int> s;
        vector<int> res(T.size());
        for(int i = T.size() - 1; i >= 0; --i)
        {
            while (!s.empty() && T[s.top()] <= T[i])
            {
                s.pop();
            }
            if(s.empty())
            {
                res[i] = 0;
            }
            else
            {
                res[i] = s.top() - i;
            }
            s.push(i);
        }
        return res;
    }

    vector<int> dailyTemperatures_using_next_array(vector<int>& T) {
        vector<int> next(101, -1);
        vector<int> res (T.size(), INT_MAX);
        for(int i = T.size() - 1; i >= 0; --i)
        {
            for(int j = T[i]+1; j <= 100; j++)
            {
                if(next[j] != -1)
                {
                    res[i]= min(res[i], next[j] - i);
                }
            }
            next[T[i]] = i;
            if(res[i]==INT_MAX) res[i] = 0;
        }
        return res;
    }

    

    vector<int> dailyTemperatures_slow(vector<int>& T) {
        
        unordered_map<int , vector<int>> m; // temp, indices map
        
        for(int i = 0; i < T.size(); ++i)
        {
            m[T[i]].push_back(i);
        }

        vector<int> res(T.size(), INT_MAX);
        for(int i = 0; i < T.size(); ++i)
        {
            for(int t = T[i]+1; t <= 100; ++t ) // for all the higher temperatures
            {
                auto f = m.find(t);
                if ( f != m.end()) // find the index that is closest to us.
                {
                    for(auto e : f->second)
                    {
                        if(e > i){
                            res[i] = min(res[i], e-i);
                            break;
                        }
                    }
                }
            }
            if(res[i] == INT_MAX) res[i]=0;
        }
        return res;
    }
};

TEST_CASE("test_success") {
    Solution s;
    vector<int> test{73, 74, 75, 71, 69, 72, 76, 73};
    REQUIRE_THAT(s.dailyTemperatures_slow(test), Equals(vector<int>{1, 1, 4, 2, 1, 1, 0, 0}));
}


TEST_CASE("test_next_success") {
    Solution s;
    vector<int> test{73, 74, 75, 71, 69, 72, 76, 73};
    REQUIRE_THAT(s.dailyTemperatures(test), Equals(vector<int>{1, 1, 4, 2, 1, 1, 0, 0}));
}

TEST_CASE("test_failure") {
    Solution s;
    REQUIRE(1==1);
}
