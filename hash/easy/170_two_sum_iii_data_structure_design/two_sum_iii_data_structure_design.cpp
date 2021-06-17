 
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
Design and implement a TwoSum class. It should support the following operations: add and find.

add - Add the number to an internal data structure.
find - Find if there exists any pair of numbers which sum is equal to the value.
For example,

add(1); 
add(3); 
add(5);
find(4) -> true
find(7) -> false
*/

class TwoSum {
    unordered_set<int> m_store;
    public:
        void add(int n)
        {
            m_store.insert(n);
        }

        bool find(int n)
        {
            for(auto it = m_store.begin(); it!=m_store.end(); it++)
            {
                auto f = m_store.find(n - *it);
                if (f != m_store.end() && f != it)
                {
                    return true;
                }
            }
            return false;
        }
};

TEST_CASE("test_") {
    TwoSum s;
    s.add(3);
    
    REQUIRE(s.find(6) == false);
}

TEST_CASE("test_two_ways") {
    TwoSum s;
    s.add(3);
    s.add(2);
    s.add(4);
    
    REQUIRE(s.find(6) == true);
}
