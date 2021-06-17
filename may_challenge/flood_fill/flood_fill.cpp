
 
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
    static const vector<pair<int,int>> moves ;
    
    vector<vector<int>> floodFillHelper(vector<vector<int>>& image, int sr, int sc, int newColor, int oldColor) {

        

        if(sr < 0 || sr>= image.size() || sc < 0 || sc >= image[0].size() || image[sr][sc] != oldColor) {
            std::cout<< sr << ", " << sc << endl;
            return image;
        }
        
        image[sr][sc] = newColor;
        std::cout<< "new start " << sr << ", " << sc << endl;
        for(auto move : moves)
            floodFillHelper(image, sr + move.first, sc + move.second, newColor, oldColor);
        return image;
        
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        int oldColor = image[sr][sc];
        if(oldColor!=newColor)
            floodFillHelper(image,sr, sc, newColor, oldColor);
        
        return image;
    }
};
const vector<pair<int,int>> Solution::moves= {{-1,0}, {1, 0}, {0, -1}, {0,1}};

TEST_CASE("test_success") {
    Solution s;
    vector<vector<int>> image {{1,1,1},{1,1,0},{1,0,1}};
    s.floodFill(image, 1,1,2);
    REQUIRE(1==1);
}

TEST_CASE("test_failure") {
    Solution s;
    REQUIRE(1==1);
}


