/* LC 399  Evaluate Division
Equations are given in the format A / B = k, where A and B are variables represented as strings, and k is a real number (floating point number). Given some queries, return the answers. If the answer does not exist, return -1.0.

Example:
Given a / b = 2.0, b / c = 3.0.
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? .
return [6.0, 0.5, -1.0, 1.0, -1.0 ].

The input is: vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries , where equations.size() == values.size(), and the values are positive. This represents the equations. Return vector<double>.

According to the example above:

equations = [ ["a", "b"], ["b", "c"] ],
values = [2.0, 3.0],
queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ]. 
 

The input is always valid. You may assume that evaluating the queries will result in no division by zero and there is no contradiction.
*/
/*
Lesson: 
*/


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
#include <iostream>

using namespace std;

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>> equations, vector<double> values, vector<vector<string>> queries) {
        
        unordered_map<string, unordered_map<string, double>> G ;
        for(int i = 0;i < equations.size(); ++i )
        {
            auto e = equations[i]; double v = values[i];
            
            string num = e[0], den = e[1];
            
            G[num][num] = G[den][den] = 1;
            G[num][den] = v;
            G[den][num] = 1/v;
        }

        for(auto k : G)
        {
            for(auto i : G)
            {
                for(auto j : G)
                {
                    G[i.first][j.first] =   (G[i.first][k.first] == 0 ? 1 : G[i.first][k.first]) * 
                                            (G[k.first][j.first] == 0 ? 1 : G[k.first][j.first]);
                }
            }
        }
        vector<double> result;
        for(auto q:queries)
        {
            auto num = q[0]; 
            auto den = q[1];
            if(G.find(num)!=G.end() && G.find(den)!=G.end())
                result.push_back(G[q[0]][q[1]]) ;
            else
            {
                result.push_back(-1);
            }
            
        }




        return result;
    }
    
    

};


int main()
{
    Solution s;
    s.calcEquation({ {"a", "b"}, {"b", "c"} },  {2.0, 3.0}, { {"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"} });
}