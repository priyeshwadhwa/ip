 
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
    vector<string> getFolderNames(vector<string>& names) {
        
        unordered_map<string, int> m;
        vector<string> res;

        for(auto name : names)
        {
            if(m.count(name) != 0)
            {
                int n = m[name] + 1;
                string rename = name + "(" + to_string(n) + ")";
                while(m.count(rename) != 0)
                {
                    n++;
                    rename = name + "(" + to_string(n) + ")";
                }
                m[name] = n;
                m[rename] = 0;
                res.push_back(rename);
            }
            else
            {
                m[name] = 0;
                res.push_back(name);
            }
        }

        return res;
    }
};
TEST_CASE("test_success") {
    Solution s;
    vector<string> names{"kaido","kaido(1)","kaido","kaido(1)"};
    s.getFolderNames(names);
    REQUIRE(1==1);
}

TEST_CASE("test_failure") {
    Solution s;
    REQUIRE(1==1);
}

