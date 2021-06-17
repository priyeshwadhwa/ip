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
Design a logger system that receive stream of messages along with its timestamps, each message should be printed if and only if it is not printed in the last 10 seconds.

Given a message and a timestamp (in seconds granularity), return true if the message should be printed in the given timestamp, otherwise returns false.

It is possible that several messages arrive roughly at the same time.

Logger logger = new Logger();

// logging string "foo" at timestamp 1
logger.shouldPrintMessage(1, "foo"); returns true;

// logging string "bar" at timestamp 2
logger.shouldPrintMessage(2,"bar"); returns true;

// logging string "foo" at timestamp 3
logger.shouldPrintMessage(3,"foo"); returns false;

// logging string "bar" at timestamp 8
logger.shouldPrintMessage(8,"bar"); returns false;

// logging string "foo" at timestamp 10
logger.shouldPrintMessage(10,"foo"); returns false;

// logging string "foo" at timestamp 11
logger.shouldPrintMessage(11,"foo"); returns true;

*/

class Solution {
    map<string, int > m;
    
    public:
    
    bool shouldPrintMessage(int ts, string msg)
    {
        auto entry = m.find(msg);
        

        if(entry != m.end() && ((ts - entry->second) <= 10))
        {
            return false;
        }
        m[msg] = ts;

        
        return true;
    }
        
};
TEST_CASE("description") {
    Solution s;
    REQUIRE(s.shouldPrintMessage(1,"foo")==true);
    REQUIRE(s.shouldPrintMessage(10,"foo")==false);
    REQUIRE(s.shouldPrintMessage(11,"foo")==false);
    REQUIRE(s.shouldPrintMessage(12,"foo")==true);
}