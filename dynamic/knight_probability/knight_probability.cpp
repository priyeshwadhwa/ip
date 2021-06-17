
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;


class SolutionRecursive {
public:
    double knightProbability(int N, int K, int i, int j) {
        if(i<0 || j< 0 || i > N-1 || j > N-1)
            return 0;
        if(K == 0) return 1.0;

        return (knightProbability(N, K-1, i-1, j-2) + knightProbability(N, K-1,i+1,j-2) + //left
                    knightProbability(N, K-1,i-1,j+2) + knightProbability(N, K-1,i+1,j+2) + // right
                    knightProbability(N, K-1,i-2,j+1) + knightProbability(N, K-1,i-2,j-1) + //up
                    knightProbability(N, K-1,i+2,j+1) + knightProbability(N, K-1,i+2,j-1) ) /8; // down
    }
};


class Solution {
public:

    double knightProbability(int N, int K, int i, int j) {
        if(K==0) return 1;

        vector<vector<vector<double>>> dp(N, 
        
            vector<vector<double>>(N, vector<double>(K,0.0))
            );

         knightProbabilityUtil(N,K,i,j,dp);
         return dp[i][j][K-1];
    }
        double knightProbabilityUtil(int N, int K, int i, int j, vector<vector<vector<double>>> & dp){
       
        if(i<0 || j< 0 || i > N-1 || j > N-1)
            return 0;
        if(K == 0) {
            dp[i][j][K] = 1.0;
            return 1.0;
        }
        if(dp[i][j][K-1]) return dp[i][j][K-1];

        dp[i][j][K-1] = (knightProbabilityUtil(N, K-1, i-1, j-2,dp) + knightProbabilityUtil(N, K-1,i+1,j-2,dp) + //left
                    knightProbabilityUtil(N, K-1,i-1,j+2,dp) + knightProbabilityUtil(N, K-1,i+1,j+2,dp) + // right
                    knightProbabilityUtil(N, K-1,i-2,j+1,dp) + knightProbabilityUtil(N, K-1,i-2,j-1,dp) + //up
                    knightProbabilityUtil(N, K-1,i+2,j+1,dp) + knightProbabilityUtil(N, K-1,i+2,j-1,dp) ) /8; // down

        return dp[i][j][K-1];
    }
};

int main()
{
    Solution s;
    cout << s.knightProbability(3, 2, 0, 0) << endl;
}