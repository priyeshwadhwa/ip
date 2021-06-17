
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
class Solution
{
public:
    vector<int> Solution::maxset(vector<int> A);
};
vector<int> Solution::maxset(vector<int> A) {
    
    int s = 0, e = 0, max_s = -1, max_e = -1;
    int64_t max_sum = 0, curr_sum = 0;
    int n = A.size();
    
    while(e < n )
    {
        if(A[e] >= 0)
        {
            curr_sum += A[e++];
            if(curr_sum > max_sum)
            {
                max_sum = curr_sum; 
                max_s = s;
                max_e = e;
            }
            else if (curr_sum == max_sum)
            {
                if(e-s > max_e - max_s)
                {
                    max_s=s;
                    max_e=e;
                }                
            }
        }
        else
        {
            curr_sum = 0;
            s = ++e;
        }
    }
    

    vector<int> res;
    int i = max_s;
    while(i < max_e)
        res.push_back(A[i++]);
    return res;
}

int main()
{
    Solution s;
    for(auto i : s.maxset({1967513926, 1540383426, -1303455736, -521595368}))
        cout << i << ' ';
}