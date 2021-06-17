
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

class Solution{
    public:
    vector<int> plusOne(vector<int> &A);

};
vector<int> Solution::plusOne(vector<int> &A) {
    
    int c = 1;
    int s = 0;
    vector<int> res;
    int i;
    for(i = 0 ; i < A.size() && A[i] == 0; ++i)
        ;
    A.erase(A.begin(),A.begin()+i);

    reverse(A.begin(),A.end());
    for(int i = 0; i< A.size(); ++i)
    {
        s = (A[i] + c) % 10;
        c = (A[i] + c) / 10;
        res.push_back(s);
    }
    if(c) res.push_back(c);

    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    Solution s ;
    vector<int> A{0,0,0,3, 0, 6, 4, 0};
    for(auto a : s.plusOne(A))
        cout << a << ' ';
    return 0;
}