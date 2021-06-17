 
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
Count the number of prime numbers less than a non-negative number, n.

Example:

Input: 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.

*/
class Solution {
    public:
    bool isPrime(int n) {
        if( n == 2) return true;
        if (n%2 == 0) return false;
        for(int i = 3; i <= sqrt(n); i++)
        {
            if(n%i==0) return false;
        }
        return true;
    }
public:
    int countPrimes(int n) {
        int count = 0;
        for(int i = 2; i < n; i++)
        {
            if(isPrime(i))
                count++;
        }
        return count;
    }
};

TEST_CASE("test_") {
    Solution s;

    for (int i = 2; i < 100 ; i++)
    {
        if(s.isPrime(i))
            std::cout<< i << ' ';
    }

    REQUIRE(s.isPrime(9) == false);
    REQUIRE(s.isPrime(7) == true);
    REQUIRE(s.isPrime(17) == true);

    REQUIRE(s.countPrimes(17) == 7);
}

