#include <iostream>
#include<cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
using namespace std; 


class Solution {
public:
    bool isHappy(int n) {

        
        set<int> seen;
        vector<int> v;


        while(n != 1 && seen.find(n)==seen.end())
        {
            seen.insert(n);
            v.clear();

            while(n != 0)
            {
                v.push_back(n%10);
                n/=10;
            }

            for_each(v.begin(), v.end(), [&n](int i){
                n += i*i;
            });
        }

        if(n==1)
            return true;
        if(seen.find(n)!=seen.end())
            return false;
    }
};

int main()
{
    Solution s;
    cout << s.isHappy(2);
}