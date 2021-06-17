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

struct Point{int i; int j;};


class Solution{
    public:    
    int maximumMinimumPath(vector<vector<int>> A)
    {
        //pq; visited; res=INT_MAX; min;

        int m = A.size();
        int n = A[0].size();


        auto comp = [](const pair<Point, int>& a, const pair<Point, int>& b) ->bool
        {
            if(a.second< b.second)
                return true;
            return false;
        };
        
        priority_queue<     pair<Point, int>,
                            vector<pair<Point, int>>,
                            decltype(comp)
                        > pq(comp);
        vector<vector<bool>> visited = vector<vector<bool>>(A.size(), vector<bool>(A[0].size(), false));
        vector<pair<int,int>> moves{{0,1},{0,-1},{1,0},{-1,0}};

        pq.push({{0,0},A[0][0]});
        visited[0][0] = true;

        int res = numeric_limits<int>::max();
        while(!pq.empty())
        {
            auto e = pq.top();
            pq.pop();
            res = min(res, e.second);

            if(e.first.i == m-1 && e.first.j == n-1)
                return res;

            for(auto& mo: moves)
            {
                int i = e.first.i + mo.first;
                int j = e.first.j + mo.second;

                if(i>=0 && i < m && j >=0 && j<n && !visited[i][j])
                {
                    visited[i][j] = true;
                    pq.push({{i,j},A[i][j]});
                }
            }
        }
    }    
};

int main()
{
    Solution s;
    //{5,4,5},{1,2,6},{7,4,6}
    cout << s.maximumMinimumPath({{5,4,5},{1,2,6},{7,4,6}}) << endl;

    
    cout << s.maximumMinimumPath({{2,2,1,2,2,2},{1,2,2,2,1,2}}) << endl;

    cout << s.maximumMinimumPath({{3,4,6,3,4},{0,2,1,1,7},{8,8,3,2,7},{3,2,4,9,8},{4,1,2,0,0},{4,6,5,4,3}}) << endl;
}