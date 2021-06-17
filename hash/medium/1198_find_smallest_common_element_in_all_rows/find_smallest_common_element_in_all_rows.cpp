 
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
LeetCode 1198. Find Smallest Common Element in All Rows 

Given a matrix mat where every row is sorted in increasing order, return the smallest common element in all rows.
If there is no common element, return -1.

Example 1:
Input: mat = {{1,2,3,4,5},{2,4,5,8,10},{3,5,7,9,11},{1,3,5,7,9}}
Output: 5
*/

class Solution {
    public:
        int SmallestInMatrix(vector<vector<int>> &mat)
        {
            int m = mat.size();
            int n = mat[0].size();

            vector<int> index(m,0);

            int max_element = mat[0][0];
            for(int i = 0 ; i < n; i++) //O(n)
            {
                auto val = mat[0][i];
                int count = 1;
                for(int j = 1; j < m; ++j)
                    if(binary_search(mat[j].begin(), mat[j].end(), val))  //(O (mlogn)
                        count++;

                if(count == m)
                    return val;
            }
            return -1;
        }

        // if all the elements are unique in the row. we can get a freq count and find our number.
        int SmallestInMatrix2(vector<vector<int>> &mat){  //O(mn)
            map<int, int> freq_count;

            int m = mat.size();
            int n = mat[0].size();

            for(int i = 0; i < m ; ++i)
            {
                for(int j = 0; j < n; ++j){
                    freq_count[mat[i][j]]++;
                }
            }
            for(auto e : freq_count)
            {
                if(e.second == m)
                    return e.first;
            }
            return -1;
        }
};

TEST_CASE("test_success") {
    Solution s;
    vector<vector<int>> mat= {{1,2,3,4,5},{2,4,5,8,10},{3,5,7,9,11},{1,3,5,7,9}};
    REQUIRE(s.SmallestInMatrix(mat) == 5);
}

TEST_CASE("test_failure") {
    Solution s;
    vector<vector<int>> mat= {{1,2,3,4,50},{2,4,5,8,10},{3,5,7,9,11},{1,3,5,7,9}};
    REQUIRE(s.SmallestInMatrix(mat) == -1);
}

TEST_CASE("test2_success") {
    Solution s;
    vector<vector<int>> mat= {{1,2,3,4,5},{2,4,5,8,10},{3,5,7,9,11},{1,3,5,7,9}};
    REQUIRE(s.SmallestInMatrix2(mat) == 5);
}

TEST_CASE("test2_failure") {
    Solution s;
    vector<vector<int>> mat= {{1,2,3,4,50},{2,4,5,8,10},{3,5,7,9,11},{1,3,5,7,9}};
    REQUIRE(s.SmallestInMatrix2(mat) == -1);
}
