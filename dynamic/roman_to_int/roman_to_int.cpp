#include <map>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        
        std::map<char, int> roman={
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000},
        };
        
        int num = 0;
        
        int i = 0, j = 1; 
        
        while (i < s.size() && j <= s.size())
        {
            if(roman[s[i]] < roman[s[j]])
            {
                num += roman[s[j++]] - roman[s[i++]];
                i++;j++;
            }
            else
            {
                num += roman[s[i++]];
                j++;
            }
        }
        return num;
    }
};

int main()
{
    Solution s;
    cout << s.romanToInt("III");
    cout << s.romanToInt("IV");
    return 0;
    
}