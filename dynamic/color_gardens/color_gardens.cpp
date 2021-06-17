
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


class Solution {
    int getunused(vector<int> used)
    {
        for(int i = 1; i<= 4; i++)
            if(find(used.begin(), used.end(), i) == used.end())
                return i;
        return -1;
    }
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        
        vector<vector<int>> A(N+1);
        for(int i = 0; i < A.size(); i++)
            A[i] = vector<int>(N+1);

        for(int i = 0 ; i< paths.size(); i++)
        {
            A[paths[i][0]][paths[i][1]] = 1;
            A[paths[i][1]][paths[i][0]] = 1;
        }
        vector<int> colour (N);
        for(int i = 1; i<= N; i++)
        {
            vector<int> used;
            for(int j =1 ; j<=N; j++)
            {
                if(i==j) continue;
                if(A[i][j] == 1 && colour[j-1] != -1)
                    used.push_back(colour[j-1]);
            }
            int c = getunused(used);
            colour[i-1] = c;
        }

        return colour;
    }
};


class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        vector<int> colors(N,-1);
        map<int,list<int> > adjlist;
        for(auto i:paths)
        {
            int u = *(i.begin());
            int v = *(i.begin()+1);
            adjlist[u].push_back(v);
            adjlist[v].push_back(u);
        }
        
        for(int i=1;i<=N;i++)
        {
            int node = i;
            bool found=true;
            for(int f=1;f<=4;f++)
            {
                bool found=true;
                for(auto neighbour:adjlist[node])
                {
                    if(colors[neighbour-1]==f)
                    {
                        found=false;
                        break;
                    }
                }
                if(found)
                {
                    colors[node-1]=f;
                    break;
                }
            }
        }
       return colors; 
    }
};

int main()
{
    Solution s;

     
    vector<vector<int>> v = {{1,2},{2,3},{3,4},{1,3},{1,4},{2,4}};
    s.gardenNoAdj(4, v );
    
    return 0;
}