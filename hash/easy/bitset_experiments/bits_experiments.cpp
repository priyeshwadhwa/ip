

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
#include <iostream>
#define CATCH_CONFIG_MAIN
#include "..\..\catch\catch.hpp"
using namespace std;
using namespace Catch;

class Solution {
    public:
        
};
TEST_CASE("description") {
    Solution s;
    REQUIRE(1==1);


    std::cout<< std::hex<< (1 << 8)-1 << endl; // number of bits  0-7 are all 1

    std::cout<< std::hex<< (~0 << 8) << endl; // number of bits 8   0-7 are all 0


    int m = 0b101010;
    int n = 0b11;
    std::cout <<hex<<m << ' ' << n;






}