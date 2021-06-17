#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int findJudge1(const int N, vector<vector<int>>& trust) {
        
        int n = trust.size();
        
        vector<int> trust_level(N + 1 , 0); // +1 as labels start with 1.
        
        int most_trusted_level = -1;
        int most_trusted = -1;
        
        for(auto e : trust)
        {
            trust_level[e[0]]--;
            trust_level[e[1]]++;
            if(most_trusted_level < trust_level[e[1]])
            {
                most_trusted_level = trust_level[e[1]];
                most_trusted = e[1];
            }             
        }
        
        return most_trusted_level == N - 1 ? most_trusted : -1;
    }

    int findJudge(const int N, vector<vector<int>>& trust) {
        
        vector<vector<int>> A(N+1);
        for(int i = 0 ; i < A.size() ; i++)
            A[i] = vector<int>(N+1);
        
        for(int i = 0; i < trust.size();i++)
        {
            int r = trust[i][0];
            int c = trust[i][1];

            A[r][c] = 1;
        }
        
        vector<int> v_cand;
        for(int c = 1; c<=N ; c++)
        {
            v_cand.push_back(c);
            for(int r = 1; r<=N; r++)
            {
                if( (r!=c || A[r][c]==1) && A[r][c] != 1)
                {
                    v_cand.pop_back();
                    break;
                }
            }
        }
        
        for( auto cand = v_cand.begin(); cand != v_cand.end();)
        {
            bool erased = false;
            for (int c=1; c <= N; c++)
            {
                if(A[*cand][c] != 0)
                {
                    erased = true;
                    cand = v_cand.erase(cand);
                    break;
                }
            }
            if(!erased) cand++;

        }

        if(v_cand.size() == 1)
            return v_cand[0];
        else
            return -1;
    }
};


int main()
{
    Solution s;
    vector<vector<int>> v = {{1,3},{2,3},{3,1}};
    cout<< s.findJudge1(3,v) << endl;
    return 0;
}