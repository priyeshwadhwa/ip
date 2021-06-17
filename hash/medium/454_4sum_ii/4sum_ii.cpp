 
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

/* 

*/

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        
        unordered_map<int, int> AB;
        int result=0;
        for(auto &a : A)
        {
            for(auto &b: B)
            {
                AB[a+b]++;
            }
        }
        
        for(auto &c : C)
        {
            for(auto&d : D)
            {
                result += AB[0-c-d];
            }
        }

        return result;
        
    }
};

TEST_CASE("test_success") {
    Solution s;
    
    vector<int> A = {0, 1, -1}, 
                B = {-1,1, 0}, 
                C = {0, 0, 1}, 
                D = {-1,1, 1};
    REQUIRE(s.fourSumCount(A, B, C , D) ==17);
}

TEST_CASE("test_failure") {
    Solution s;
    REQUIRE(1==1);
}
