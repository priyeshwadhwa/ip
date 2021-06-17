
 
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

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        //sliding window.. will not work. because of negative numbers
        // i , j, 
        //sum < k-> sum+=nums[j] 
        // sum ==k . ans++;
        // sum >k  sum-=nums[i] i++
        
        // prefix sum.: save the prefix sums in a map.. and for new num. see if sum exists in prefix sum-map
        
        unordered_map<int,int> prefix_sum;
        prefix_sum[0] = 1;
        int sum = 0;
        int result = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            sum += nums[i];
            if(prefix_sum.find(sum-k) != prefix_sum.end())
                result += prefix_sum[sum-k];
            prefix_sum[sum]++;
        }
        return result;
    }
};

TEST_CASE("test_success") {
    Solution s;
    vector<int> n{1,1,1};
    s.subarraySum(n,2);
}


TEST_CASE("test_failure") {
    Solution s;
    REQUIRE(1==1);
}

