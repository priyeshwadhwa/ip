#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
class Solution {
public:
    int maxArea_brute_force(vector<int> height) {

        int h_max =0, l_max = 0;

        for(int i = 0;i <height.size(); i++)
        {
            for(int j= i+1 ;j < height.size();j++)
            {
                int h = min(height[i],height[j]);
                int l = j - i;
                if(l *h > h_max*l_max)
                {
                    h_max = h; l_max = l;
                }
            }
        }
    return h_max*l_max;
    }
    int maxArea(vector<int> height) {
        int l = 0, r = height.size() -1, maxArea = 0;
        while(l<r)
        {
            maxArea = max(maxArea, (r-l) * min(height[l],height[r]) );
            if(height[l]<height[r])
                l++;
            else
                r--;
        }
    }


};

int main()
{
    Solution s;
    cout <<s.maxArea_brute_force({1,8,6,2,5,4,8,3,7});
}