
 
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

2001:db8:85a3:0:0:8A2E:0370:7334
*/
class Solution {
public:
    string validIPAddress(string IP) {
        smatch sm;
        regex ipv4(R"(([1-9][0-9]{0,2})\.([1-9][0-9]{0,2})\.([1-9][0-9]{0,2})\.([1-9][0-9]{0,2}))");

        regex ipv6(R"(([[:xdigit:]]{1,4}:){7}[[:xdigit:]]{1,4})");
        
        if(regex_match(IP, sm, ipv4) && 
            std::stoi(sm[1].str()) < 256 &&
            std::stoi(sm[2].str()) < 256 &&
            std::stoi(sm[3].str()) < 256 &&
            std::stoi(sm[4].str()) < 256)
        {
            return "IPv4";
        }            
        else if(regex_match(IP, ipv6))
            return "IPv6";
        return "Neither";
        
            
        
    }
};


TEST_CASE("test_success") {
    Solution s;
    //s.validIPAddress("100.00.10.10");
    //std::cout<<s.validIPAddress("2001:db8:85a3:0:0:8A2E:0370:7334");
    REQUIRE(1==1);
}

TEST_CASE("test_ipv4") {
    Solution s;
    s.validIPAddress("256.256.256.256");
    REQUIRE(1==1);
}

