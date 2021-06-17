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
Given a list of scores of different students, return the average score of each student's top five scores in the order of each student's id.

Each entry items[i] has items[i][0] the student's id, and items[i][1] the student's score. The average score is calculated using integer division.

Example 1:

Input: [[1,91],[1,92],[2,93],[2,97],[1,60],[2,77],[1,65],[1,87],[1,100],[2,100],[2,76]]
Output: [[1,87],[2,88]]
Explanation:
The average of the student with id = 1 is 87.
The average of the student with id = 2 is 88.6. But with integer division their average converts to 88.

Note:

1 <= items.length <= 1000
items[i].length == 2
The IDs of the students is between 1 to 1000

*/

class Solution {
    const int kMaxScores = 5;
public:
    unordered_map<int, double> average_top_five_scores(vector<pair<int, double>> scores)
    {
        unordered_map<int, double> avg;

        unordered_map<int, priority_queue<double> > high_scores;

        for(auto s : scores)
        {
            auto id = s.first;
            auto score = s.second;
            high_scores[id].push(score);
        }

        for(auto e: high_scores)
        {
            double sum = 0;
            int i = 0;
            for(i = 0; i < kMaxScores && !e.second.empty(); ++i)
            {
                sum += e.second.top(); 
                e.second.pop();
            }
            avg[e.first] = sum/i;
        }
        return avg;
    }
};


// class MapMatcher: public Catch::MatcherBase<unordered_map<int, double>>
// {
//     public:
//     bool match( ) const override
//     {

//     }

//     string describe() const override{return "aah";}
// }


TEST_CASE("void") {
    Solution s;

    auto res = s.average_top_five_scores({ {1,3}, {1,5}, {1,1} });
    for(auto s: res)
        std::cout<< s.first << ' ' << s.second<< endl;
}



TEST_CASE("void1") {
    Solution s;

    auto res = s.average_top_five_scores({ {1,3}, {1,5}, {1,10}, {1,3.5}, {1,9.5} , {2,2}});
    for(auto s: res)
        std::cout<< s.first << ' ' << s.second<< endl;
}