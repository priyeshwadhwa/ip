
#include <map>
#include <vector>
#include <string>
#include <set>
#include <unordered_map>

#include <numeric>

#include <iostream>

#include <algorithm>


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
                    cout<<G[i.first][j.first]<< ' ';
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
    for(auto d : s.calcEquation({{"a","b"},{"b","c"}},{2.0,3.0},{{"a","c"},{"b","a"},{"a","e"},{"a","a"},{"x","x"}   }))
        ;//cout<<d<<' ';
}