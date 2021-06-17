

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
#include <string>
#include <regex>
using namespace std;

class TimeDifference
{
    public:
    string calculate(string t1, string t2)
    {
        string sm[2];
        sm[1] = t1.substr(t1.size()-2,2);
        sm[0] = t1.substr(0,t1.size()-3);
        int h1 = stoi(sm[0]);
        int m1 = stoi(sm[1]);


        sm[1] = t2.substr(t2.size()-2,2);
        sm[0] = t2.substr(0,t2.size()-3);
        int h2 = stoi(sm[0]);
        int m2 = stoi(sm[1]);
        int h , m;

        string sign;
        if(h1 > h2)
        {
            sign = '-';
            if(m1<m2)
            {
                //borrow
                m1 += 60; h1--;
            }
        }
        else if(h1 == h2 && m1 > m2)
        {
            sign = '-';
        }
        else if(h1 < h2)
        {
            if(m1>m2)
            {
                m2+=60;
                h2--;
            }
        }
        h=abs(h1-h2);
        m = abs(m1-m2);

        string res;
        res += sign + std::to_string(h) + ':'+ ((m>=0&&m<=9)?"0":"") + std::to_string(m);
        return res;
 
    }
};

int main()
{
    vector<pair<string, string>> tests {
        {"001:55","2:33"},
        {"010:44","10:44"},
        {"100:40","90:40"},
        {"100:40","90:50"},
        {"0:00","000:00"},
        {"0:00","13:23"},
        {"01:00","8:15"},
        {"123:45","543:21"},
        {"111:11","222:12"}

    };
    TimeDifference td;

    for(auto t: tests)
        cout << td.calculate(t.first,t.second) << endl;
}