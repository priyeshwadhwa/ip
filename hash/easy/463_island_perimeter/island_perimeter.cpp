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
    int islandPerimeter(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        vector<pair<int,int>> neighbors{{-1,0}, {1,0}, {0,-1}, {0,1}};
        
        int res = 0;
        
        for(int i = 0; i < m; ++i)
        {
            for(int j=0; j < n ; ++j)
            {
                if(grid[i][j] == 1 )
                {
                    int perimeter = 4;
                    for(auto ne : neighbors)
                    {
                        int x = i + ne.first;
                        int y = j + ne.second;
                        if(x >=0 && x < m && y>=0 && y< n  && grid[x][y]==1)
                            perimeter--;
                    }
                    res+= perimeter;
                }
            }
        }
        return res;
    }
};


TEST_CASE("description") {
    Solution s;
    vector<vector<int>> grid ={ {0,1,0,0},
                                {1,1,1,0},
                                {0,1,0,0},
                                {1,1,0,0}
                            };
    REQUIRE(s.islandPerimeter(grid)==16);
}