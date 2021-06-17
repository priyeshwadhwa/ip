 
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
    vector<int> powerfulIntegers1(int x, int y, int bound) {
        // save the powers for the bigger number in sorted order
        // set max_upper 
        // for each x^i power of other num. start from the max_upper bound 
        // check if x^i + upper_bound to 0 put the sum if its not already in the set;
        // if the sum is higher reduce the upper_bound
        
        //special case 1 

        if(bound < 2) return {};
        
        
        vector<int> p{1};
        if(x>y)swap(x,y);
        for(int pow = x; pow <= bound && x != 1; pow *= x )
        {
            p.push_back(pow);
        }
        
        unordered_set<int> res{2};
        int upper_limit = p.size() - 1;
        
        for(int pow = 1; pow <= bound && y != 1; pow *= y )
        {
            for(int i = upper_limit; i>=0 ; --i)
            {
                int sum = pow + p[i];
                if(sum <= bound)
                {
                    res.insert(sum);
                }
                else
                {
                    upper_limit--;
                }
            }            
        }
        return {res.begin(), res.end()};
    }
    vector<int> powerfulIntegers(int x, int y, int bound) {

        unordered_set<int> s;
        for(int i = 1; i <= bound; i *= x)
        {
            for(int j = 1; i + j <= bound; j *= y)
            {
                s.insert(i+j);
                if(y==1) break;
            }
            if(x==1) 
                break;
        }
        return {s.begin(), s.end()};
    }

};

TEST_CASE("test_x1y1b10") {
    Solution s;

    REQUIRE_THAT(s.powerfulIntegers(1,1,10), UnorderedEquals(vector<int>{2}));
}

TEST_CASE("test_x1y1b1") {
    Solution s;

    REQUIRE_THAT(s.powerfulIntegers(1,1,1), UnorderedEquals(vector<int>{}));
}

TEST_CASE("test_x2y1b10") {
    Solution s;

    REQUIRE_THAT(s.powerfulIntegers(2,1,10), UnorderedEquals(vector<int>{2,3,5,9}));
}


TEST_CASE("test_x2y3b10") {
    Solution s;

    REQUIRE_THAT(s.powerfulIntegers(2,3,10), UnorderedEquals(vector<int>{2,3,4,5,7,9,10}));
}



TEST_CASE("test_x3y5b15") {
    Solution s;

    REQUIRE_THAT(s.powerfulIntegers(3,5,15), UnorderedEquals(vector<int>{2,4,6,8,10,14}));
}

