
#include <algorithm>
#include <numeric>

#include <vector>
#include <queue>
#include <list>
#include <tuple>
#include <map>
#include <stack>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <iostream>
#include <string>
using namespace std;

class EnlargeTheCave{
    vector<pair<int,int>> moves = {{0,1},{0,-1},{1,0},{-1,0}};
    public:
    void dfs(int i , int j, vector<string> &cave, vector<vector<bool>>& visited, int & area, int m , int n,int D)
    {
        if(visited[i][j] || area >= D) return;

        visited[i][j] = true;
        if(cave[i][j] == '#')
        { 
            cave[i][j] = '.';
            area++;
        }

        for(auto mo: moves)
        {
            int di = i + mo.first;
            int dj = j + mo.second;
            if(di>=0 && di<m && dj>=0 && dj < n && visited[di][dj] == false)
            {
                dfs(di, dj, cave, visited, area, m , n, D);
            }
        }
    }

    vector<string> enlarge(vector<string> cave, int D)
    {
        int m = cave.size();
        int n = cave[0].size();
        int area = 0; 
        auto visited = vector<vector<bool>>(m, vector<bool>(n,false));
        //first mark all the wanted nodes visited.
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0 ; j < n; ++j)
            {
                if(cave[i][j] == 'K')
                {
                    visited[i][j] = true;
                    for(auto mo: moves){
                        int di = i + mo.first;
                        int dj = j + mo.second;
                        if(di >=0 && di<m && dj>=0 && dj<n)
                            visited[di][dj] = true;
                    }
                }
                else if(cave[i][j] == '.')
                    area++;
            }
        }


        for(int i = 0; i < m; ++i)
        {
            for(int j = 0 ; j < n; ++j)
            {
                if(cave[i][j] == '.')
                {
                    
                    dfs(i,j,cave, visited,area, m, n, D);
                    if(area >= D)
                        return cave;
                    return {};
                }
            }
        }
        return {};

    }
};


int main()
{

vector<pair<vector<string>, int>> tests=
{

{    	
{".##",
 "###",
 "###"},
7},

{{"K#."},3},

	
{{"###K########",
 "#.#K########",
 "..#K########",
 "############"}, 10 },

 {{ "#############################################",
    "#############################################",
    "##K###..####K####K###..####K####K###..####K##",
    "######..#############..#############..#######",
    "#############################################",
    "##K#########K####K#########K####K#########K##",
    "#############################################",
    "#############################################",
    "#############################################",
    "#############################################",
    "#############################################",
    "#############################################",
    "#############################################",
    "#############################################",
    "#############################################",
    "#############################################",
    "#############################################",
    "#############################################"},
250},

{	
{"#K#K###..###K#K##"},6},

};


for(auto t: tests){
    EnlargeTheCave e;
    auto sol = e.enlarge(t.first,t.second);
    if(sol.empty()) cout<<"empty";
    for(auto &s : sol )
        {cout<<s<<endl;}
    cout<<endl;
}
}