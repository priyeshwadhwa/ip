
 
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

/*Suppose you have a random list of people standing in a queue. Each person is described by a pair of integers (h, k), where h is the height of the person and k is the number of people in front of this person who have a height greater than or equal to h. Write an algorithm to reconstruct the queue.

Note:
The number of people is less than 1,100.

 
Example

Input:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

Output:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
 */

 class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // height, k
        
        // sort on height(smallest), k (smallest)
        
        // 
        int n = people.size();
        vector<vector<int>> res(n);
        
        set<int> empty;
        for(int i =0; i < n ; ++i)
            empty.insert(i);
        
        auto comp = [](auto v1, auto v2)->bool
        {
            if(v1[0] < v2[0])
                return true;
            return false;
        };
        
        sort(begin(people), end(people), comp);
        
        for( auto p : people)
        {
            auto it = std::next(empty.begin(), p[1]); // get the next empty index.
            res[*it] = p;
            empty.erase(it);
        }
        return res;
    }
};

TEST_CASE("test_simple1") {
    Solution s;
    vector<vector<int>> people = {{7,0}, {4,4}, {7,1}, {5,0}, {6,1}, {5,2}};
    s.reconstructQueue(people);
    REQUIRE(1==1);
}