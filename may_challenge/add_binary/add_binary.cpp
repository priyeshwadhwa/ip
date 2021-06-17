 
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
    string addBinary(string a, string b) {
        
        string res;
        int n = a.size(); 
        int m = b.size();
        int carry = 0;
        int sum = 0;

        int i = n-1, j = m -1;

        while( i >=0 || j >= 0|| carry)
        {
            sum = i >= 0 ? a[i--] - '0': 0;
            sum += j >= 0 ? b[j--] - '0': 0;
            sum += carry;
            carry = 0; // reset carry
            if(sum>=2)
            { 
                carry = 1; 
                sum -= 2;
            }
            res = char('0'+ sum) + res;
        }


        return res;
    }
};

TEST_CASE("test_success") {
    Solution s;
    s.addBinary("10","11");
    REQUIRE(1==1);
}

TEST_CASE("test_failure") {
    Solution s;
    REQUIRE(1==1);
}

