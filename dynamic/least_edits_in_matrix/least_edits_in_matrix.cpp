
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
#include <list>
#include <tuple>
#include <iostream>

using namespace std;

class Solution
{
    public:
        int least_edits_in_matrix(vector<vector<char>> a)
        {
            int m = a.size();
            int n = a[0].size();

            vector<vector<int>> dist(m,vector<int>(n, numeric_limits<int>::max()));
            dist[0][0] = 0;

            vector<vector<bool>> visited(m, vector<bool>(n, false));
            visited[0][0] = true;

            list<pair<int,int>> q;
            q.push_back({0,0});

            while(!q.empty())
            {
                int i, j;
                tie(i,j) = q.front();
                q.pop_front();
                char c = a[i][j];
                visited[i][j] = true;

                if(i>0)
                {
                    dist[i-1][j] = min(dist[i-1][j], c=='U'?0:1 + dist[i][j] );
                    if(!visited[i-1][j])
                    {
                        if(c=='U') q.push_front({i-1,j});
                        else q.push_back({i-1,j});

                    }
                }
                if(i<m-1)
                {
                    dist[i+1][j] = min(dist[i+1][j], c=='D'?0:1 + dist[i][j] );
                    if(!visited[i+1][j])
                        if(c=='D') q.push_front({i+1,j});
                        else q.push_back({i+1,j});
                }
                
                if(j>0)
                {
                    dist[i][j-1] = min(dist[i][j-1], c=='L'?0:1 + dist[i][j] );
                    if(!visited[i][j-1])
                        if(c=='L') q.push_front({i,j-1});
                        else q.push_back({i,j-1});
                }
                if(j<n-1)
                {
                    dist[i][j+1] = min(dist[i][j+1], c=='R'?0:1 + dist[i][j] );
                    if(!visited[i][j+1])
                        if(c=='R') q.push_front({i,j+1});
                        else q.push_back({i,j+1});
                }
            }

            return dist[m-1][n-1];
        }

};

int main()
{
    Solution s;
    cout<< s.least_edits_in_matrix({{'D','D','U'},{'R','D','U'}});
}