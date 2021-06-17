#include <map>
#include <vector>
#include <string>
#include <iostream>

using namespace std;
/** wrong **/
class Solution {
public:
    string intToRoman(int num) {
        std::vector<pair<char, int>> roman={
            {1000,'M'},
            {500,'D'},
            {100,'C'},
            {50,'L'},
            {10,'X'},
            {5,'V'},
            {1,'I'},
        };
        
        string s;
        for(int i = 0; i < roman.size();i++)
        {
            if(num == 0) break;

            int d = num / roman[i].first;
            if(d<=0) continue;
            if(d>3)
            {
                s+=roman[i].second;
                s+=roman[i-1].second;
                num -= roman[i-1].first - roman[i].first;
            }
            else
            {
                for(int k = 0;k<d;k++)
                    s+= roman[i].second;
                num -= roman[i].first*d;
            }
        }
        return s;
    }
};

int main()
{
    Solution s;
    cout<<s.intToRoman(3)<<endl;
    cout<<s.intToRoman(14)<<endl;
    cout<<s.intToRoman(9)<<endl;
}
