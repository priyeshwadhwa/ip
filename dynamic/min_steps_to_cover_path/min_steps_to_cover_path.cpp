
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
    int coverPoints(vector<int> A, vector<int> B) ;
};


int Solution::coverPoints(vector<int> A, vector<int> B) {

    int n = A.size();
    int steps = 0;
    for(int i = 0; i < n-1 ; i++)
    {
        int res = 0;
        int x_dist = abs(A[i+1] - A[i]);
        int y_dist = abs(B[i+1] - B[i]);

        res += min( x_dist, y_dist ); //diagonal

        res += (x_dist - res) + (y_dist - res); // remaining straight path

        steps += res;
    }
    return steps;
}

int main()
{
    Solution s;
    cout << s.coverPoints(  {4, 8, -7, -5, -13, 9, -7, 8}, 
                            {4, -15, -10, -3, -13, 12, 8, -8});
}
