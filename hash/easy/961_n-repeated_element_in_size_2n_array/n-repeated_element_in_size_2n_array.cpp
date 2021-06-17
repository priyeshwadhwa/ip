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
In a array A of size 2N, there are N+1 unique elements, and exactly one of these elements is repeated N times.

Return the element repeated N times.

 

Example 1:

Input: [1,2,3,3]
Output: 3
Example 2:

Input: [2,1,2,5,3,2]
Output: 2
Example 3:

Input: [5,1,5,2,5,3,5,4]
Output: 5
 

Note:

4 <= A.length <= 10000
0 <= A[i] < 10000
A.length is even
*/
class Solution {
public:
    int repeatedNTimes(vector<int> A) {
        
        unordered_set<int> s;
        for(auto a: A)
        {
            if(s.count(a))
                return a;
            s.insert(a);
        }
        return 0;
    }
};

TEST_CASE("description") {
    Solution s;
    REQUIRE(s.repeatedNTimes({1,1,3,4}) == 1);
}