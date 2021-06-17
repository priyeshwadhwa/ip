
 
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
    int findLeastNumOfUniqueInts(vector<int> arr, int k) {
        
        unordered_map<int, int> freq;
        for(auto a : arr)
            freq[a]++;
        vector<pair<int,int>> sort_freq;
            
        for(auto f : freq)
            sort_freq.push_back({f.second, f.first});
        sort(begin(sort_freq), end(sort_freq));
        
        for(auto s = begin(sort_freq); k && s!= end(sort_freq); )
        {
            if(s->first <= k)
            {
                k-= s->first;
                s=sort_freq.erase(s);
            }
            else
                s++;
        }
        return sort_freq.size();
    }
};



TEST_CASE("test_simple_1") {
    Solution s;
    std::cout<< s.findLeastNumOfUniqueInts ({2,1,1,3,3,3}, 3);
    REQUIRE(1==1);
}