#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    pair<int,int> get01count(string s)
    {
        pair<int,int> p{0,0};
        for(char c : s)
        {
            if(c == '0') p.first++;
            else p.second++;
        }
        return p;
    }
    int findMaxForm(vector<string> strs, int m, int n) {

        vector<vector<int>> dp(m+1);
        for(int i = 0; i < m+1; ++i)
            dp[i] = vector<int>(n+1,0);

        vector<pair<int,int>> v;
        for(auto s : strs)
        {
             v.emplace_back(get01count(s));
        }

        for(auto p : v)
        {
            int num0 = p.first;
            int num1 = p.second;
            for(int i = m; i >= 0; --i)
            {
                for(int j = n; j >= 0; --j)
                {
                    if(i >= num0 && j >= num1)
                    {
                        dp[i][j] = max (1+ dp[i-num0][j-num1], dp[i][j]);
//                        cout << "dp["<<i<<"]["<<j<<"] = "<< dp[i][j] <<" "<< s << endl;
                    }
                }
            }
        }
        return dp[m][n];       
    }
};

void main()
{
    Solution s;
    cout << s.findMaxForm({"10", "0001", "111001", "1", "0"},5,3);
}