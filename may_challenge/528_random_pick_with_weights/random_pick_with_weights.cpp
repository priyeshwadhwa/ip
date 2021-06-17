 
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
#include "..\..\catch\catch.hpp"
using namespace std;
using namespace Catch;

/* Problem:
Given an array w of positive integers, where w[i] describes the weight of index i, write a function pickIndex which randomly picks an index in proportion to its weight.

Note:

1 <= w.length <= 10000
1 <= w[i] <= 10^5
pickIndex will be called at most 10000 times.
Example 1:

Input: 
["Solution","pickIndex"]
[[[1]],[]]
Output: [null,0]
Example 2:

Input: 
["Solution","pickIndex","pickIndex","pickIndex","pickIndex","pickIndex"]
[[[1,3]],[],[],[],[],[]]
Output: [null,0,1,1,1,0]
Explanation of Input Syntax:

The input is two lists: the subroutines called and their arguments. Solution's constructor has one argument, the array w. pickIndex has no arguments. Arguments are always wrapped with a list, even if there aren't any.
*/

class Solution {
    vector<int> weights;
    int maxval;
public:
    Solution(vector<int>& w) 
    {
        weights = vector<int>(w.size());
        weights[0] = w[0];
        for(int i = 1; i < w.size(); i++)
            weights[i] = weights[i-1] + w[i];
        maxval = weights[weights.size()-1];
    }
    
    int pickIndex() {
        
        int r = rand() % maxval;
        auto it = upper_bound(weights.begin(), weights.end(), r);
        return distance(weights.begin(), it);
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */

TEST_CASE("test_success") {
    vector<int> t {1,3};
    Solution s(t);
    
  
    s.pickIndex();
    REQUIRE(1==1);
}


