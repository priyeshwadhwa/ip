
#include <iostream>
#include<cstdlib>
#include <algorithm>
#include <vector>
using namespace std; 

/*

Initialize ans=0ans=0
Iterate the array from left to right:
Initialize \text{max\_left}=0max_left=0 and \text{max\_right}=0max_right=0
Iterate from the current element to the beginning of array updating:
\text{max\_left}=\max(\text{max\_left},\text{height}[j])max_left=max(max_left,height[j])
Iterate from the current element to the end of array updating:
\text{max\_right}=\max(\text{max\_right},\text{height}[j])max_right=max(max_right,height[j])
Add \min(\text{max\_left},\text{max\_right}) - \text{height}[i]min(max_left,max_right)−height[i] to \text{ans}ans

*/


// Find maximum height of bar from the left end upto an index i in the array \text{left\_max}left_max.
// Find maximum height of bar from the right end upto an index i in the array \text{right\_max}right_max.
// Iterate over the \text{height}height array and update ans:
// Add \min(\text{max\_left}[i],\text{max\_right}[i]) - \text{height}[i]min(max_left[i],max_right[i])−height[i] to ansans


class Solution {
public:
    int trap(vector<int>& height)
{
	if(height == nullptr)
		return 0;
    int ans = 0;
    int size = height.size();
    vector<int> left_max(size), right_max(size);
    left_max[0] = height[0];

    for (int i = 1; i < size; i++) {
        left_max[i] = max(height[i], left_max[i - 1]);
    }

    right_max[size - 1] = height[size - 1];
    for (int i = size - 2; i >= 0; i--) {
        right_max[i] = max(height[i], right_max[i + 1]);
    }
    
    for (int i = 1; i < size - 1; i++) {
        ans += min(left_max[i], right_max[i]) - height[i];
    }
    return ans;
}
};