 
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


*/

class Solution {
public:
    int countTriplets(vector<int> arr) {
        int n = arr.size();
        int count = 0;
        int a = 0, b = 0;
        for(int i = 0; i < n; i++)
        {
            a = 0;
            for(int j = i+1; j < n ; ++j)
            {
                b = 0;
                a ^= arr[j-1];
                for(int k = j; k < n; k++)
                {
                    b ^= arr[k];
                    if(b==a) count++;
                  
                }
            }
        }
        return count;
    }
};

TEST_CASE("test_success") {
    Solution s;
    s.countTriplets({1,1,1,1,1});
    REQUIRE(1==1);
}

TEST_CASE("test_failure") {
    Solution s;
    REQUIRE(1==1);
}
