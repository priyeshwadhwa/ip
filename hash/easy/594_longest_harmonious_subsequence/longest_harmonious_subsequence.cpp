 
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
We define a harmounious array as an array where the difference between its maximum value and its minimum value is exactly 1.

Now, given an integer array, you need to find the length of its longest harmonious subsequence among all its possible subsequences.

Example 1:

Input: [1,3,2,2,5,2,3,7]
Output: 5
Explanation: The longest harmonious subsequence is [3,2,2,2,3].
*/

class Solution {
public:
    int findLHS_slow(vector<int>& nums) { //O(n^2)

        unordered_map<int, int> m;
        int curr_res = INT_MIN;
        for(int i = 0 ; i < nums.size(); ++i)
        {
            if(m.find(nums[i]) != m.end())
                continue;
            int high = 0 , low = 0;
            bool only_same_numbers = true;
            for(int j = i; j< nums.size(); ++j)
            {
                if(nums[i] == nums[j] - 1)
                {
                    high++; only_same_numbers = false;
                }
                else if(nums[i] == nums[j] + 1)
                {
                    low++;only_same_numbers=false;
                }
                else if(nums[i] == nums[j] )
                {
                    high++; low++;
                }
            }
            m[nums[i]] = only_same_numbers? 0 : max(high,low);
            if(curr_res < m[nums[i]])
                curr_res = m[nums[i]];
        }
        return curr_res == INT_MIN?0:curr_res;
    }


      int findLHS(vector<int>& nums) { //O(n)

        unordered_map<int, int> m;

        for(auto n: nums) m[n]++; // count the number of occurences.

        int curr_res = 0;

        for(auto e : m) // for each element in the map n.
        {
            if( m.find(e.first+1) != m.end()) // if n+1 exist in the map, We care for n+1 only i.e <n,n+1> seq, because if n-1 exists will cover <n-1, n> sequence on its turn
            {
                curr_res = max(m[e.first] + m[e.first+1], curr_res); // update the result.
            }
        }
        return curr_res;
    }
};

TEST_CASE("test_") {
    Solution s;
    vector<int> test{1,3,2,2,5,2,3,7,5,5,6,5,6};
    REQUIRE(s.findLHS(test) == 6);
}

TEST_CASE("test_same_numbers") {
    Solution s;
    vector<int> test{1,1,1,1};
    REQUIRE(s.findLHS(test) == 0);
}

TEST_CASE("test_increasing order") {
    Solution s;
    vector<int> test{1,2,3,4};
    REQUIRE(s.findLHS(test) == 2);
}

TEST_CASE("test_decreasing order") {
    Solution s;
    vector<int> test{60,59,58,57};
    REQUIRE(s.findLHS(test) == 2);
}

TEST_CASE("test_single_number") {
    Solution s;
    vector<int> test{60};
    REQUIRE(s.findLHS(test) == 0);
}


TEST_CASE("test_empty") {
    Solution s;
    vector<int> test{};
    REQUIRE(s.findLHS(test) == 0);
}