 
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
Suppose Andy and Doris want to choose a restaurant for dinner, and they both have a list of favorite restaurants represented by strings.

You need to help them find out their common interest with the least list index sum. If there is a choice tie between answers, output all of them with no order requirement. You could assume there always exists an answer.

Example 1:
Input:
["Shogun", "Tapioca Express", "Burger King", "KFC"]
["Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"]
Output: ["Shogun"]
Explanation: The only restaurant they both like is "Shogun".
Example 2:
Input:
["Shogun", "Tapioca Express", "Burger King", "KFC"]
["KFC", "Shogun", "Burger King"]
Output: ["Shogun"]
Explanation: The restaurant they both like and have the least index sum is "Shogun" with index sum 1 (0+1).
Note:
The length of both lists will be in the range of [1, 1000].
The length of strings in both lists will be in the range of [1, 30].
The index is starting from 0 to the list length minus 1.
No duplicates in both lists.
*/
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> m;
        int i = 0;
        for(auto s: list1)
            m[s] = i++;
        
        int curr_min = INT_MAX;
        vector<string> res;
        for(int i = 0; i < list2.size(); ++i)
        {
            auto common_res = m.find(list2[i]);
            if(common_res!= m.end())
            {
                if(common_res->second + i < curr_min)
                {
                    res.clear();
                    res.push_back(list2[i]);
                    curr_min = i + common_res->second;
                }
                else if(common_res->second + i == curr_min)
                {
                    res.push_back(list2[i]);
                }
            }
        }
        return res;
        
    }
};

TEST_CASE("test_") {
    Solution s;
    vector<string>andy{"Shogun", "Burger King","Tapioca Express", "dd", "KFC"};
    vector<string>doris{"KFC","Burger King", "Shogun","dd"};
    REQUIRE_THAT(s.findRestaurant(andy,doris), UnorderedEquals(vector<string>{"Burger King","Shogun"}));
}

