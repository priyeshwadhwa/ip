
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
using namespace std;


class Solution
{
public:
    int maxSpecialProduct(vector<int> &A) ;
};


int Solution::maxSpecialProduct(vector<int> &A) {
    int maxProduct = numeric_limits<int>::min();
    int n = A.size();
    stack<int> s;
    vector<vector<int>> lr_max=vector<vector<int>>(n,vector<int>(2,0));

    for(int i = 0; i < n; ++i)
    {
        while(!s.empty()&&A[s.top()] <= A[i])
            s.pop();
            
        if(s.empty())
            lr_max[i][0] = 0;
        else
            lr_max[i][0] = s.top();
        s.push(i);
    }
    s = {};
    for(int i = n-1; i>=0; --i)
    {
        while(!s.empty() && A[s.top()] <= A[i])
            s.pop();
        
        if(s.empty())
            lr_max[i][1] = 0;
        else
            lr_max[i][1] = s.top();
        s.push(i);
    }
    
    for(auto a : lr_max)
        maxProduct = max( (int)( a[0]*a[1]% 1000000007), maxProduct);
    return maxProduct;
}


int main()
{
    Solution s;
    vector<int> A{6, 7, 9, 5, 5, 8};
    cout << s.maxSpecialProduct(A);
}