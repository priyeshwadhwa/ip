 
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
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        
        // convert edges to a adj map.. 0 : {f,s}
        unordered_map<int, pair<int, int>> tree;
        for(auto e : edges)
        {
            int from = e[0], to= e[1];
            if(tree.count(from) == 0)
            {
                tree[from] = {to, -1};
            }
            else
                tree[from].second = to;
        }
        return minTimeHelper(0, tree, hasApple);
    }
    
    int minTimeHelper(int node, unordered_map<int, pair<int,int>>& tree, vector<bool>& hasApple)
    {
        if(tree.count(node)==0)
            return 0;
        
        
        int left = minTimeHelper(tree[node].first, tree, hasApple);
        int path = (left != 0) ? (2 + left) : (hasApple[tree[node].first] ? 2 : 0);
        
        if(tree[node].second != -1 )
        {
            int right = minTimeHelper(tree[node].second, tree, hasApple);
            path += (right != 0) ? (2 + right) : (hasApple[tree[node].second] ? 2 : 0);
        }
        return path;
    }
};

TEST_CASE("test_success") {
    Solution s;
    int n = 7;
    vector<vector<int>> e{{0,1},{0,2},{1,4},{1,5},{2,3},{2,6}};
    vector<bool> hasApple{false,false,true,false,true,true,false};
    s.minTime(n, e, hasApple);
    REQUIRE(1==1);
}

TEST_CASE("test_failure") {
    Solution s;
    REQUIRE(1==1);
}
