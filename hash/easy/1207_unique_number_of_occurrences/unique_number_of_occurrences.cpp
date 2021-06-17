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
Given an array of integers arr, write a function that returns true if and only if the number of occurrences of each value in the array is unique.

 

Example 1:

Input: arr = [1,2,2,1,1,3]
Output: true
Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.
Example 2:

Input: arr = [1,2]
Output: false
Example 3:

Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
Output: true
 

Constraints:

1 <= arr.length <= 1000
-1000 <= arr[i] <= 1000
*/
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        
        unordered_set<int> s;
        unordered_map<int, int> m;
        
        for(auto a : arr)
        {
            m[a]++;
        }
        for(auto e: m)
        {
            if(s.count(e.second))
                return false;
            s.insert(e.second);
        }
         
        return true;
    }
};

TEST_CASE("description") {
    Solution s;
    vector<int> v {-3,0,1,-3,1,1,1,-3,10,0};
    REQUIRE(s.uniqueOccurrences(v) == true);
}