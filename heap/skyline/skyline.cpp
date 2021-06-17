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

struct building{
    int l, h, r;
    building(vector<int> i) :l(i[0]), h(i[1]), r(i[2])
    {}
};

class Solution {
public:
 vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
     //vector of three points;
     
     auto comp = [](vector<int> &a , vector<int> &b) -> bool {
         if(a[0] > b[0]) 
            return true;
        else if(a[0] < b[0])
            return false;

         else if (a[1] < b[1]) 
            return true;
         else if(a[1] > b[1])
            return false;

        return false;
     };
     priority_queue<
            vector<int>, 
            vector<vector<int>>,
            decltype(comp)> pq(comp);

    vector<vector<int>> result;

    for(auto e: buildings)
    {
        pq.push(e);
    }
    building curr(pq.top()); 
    pq.pop();
    result.push_back({curr.l, curr.h });

    while(!pq.empty())
    {
        building top(pq.top()); pq.pop();
        if(top.l <= curr.r) //t.l c.r
        {
            if(top.h <= curr.h) //height
            {
                if(top.r <= curr.r)
                {
                    //covered inside
                }
                else
                {
                    if(curr.r == top.l)
                    {
                        result.push_back({top.l, top.h});
                        curr = top;
                    }
                    else
                    {
                        pq.push({curr.r, top.h, top.r});
                    }
                }
            }
            else
            {
                if(top.r < curr.r)
                {
                    pq.push({top.r, curr.h, curr.r});
                    curr.l = top.r;
                }
                else
                {
                    curr = top;
                }
                result.push_back({top.l, top.h});
            }
        }
        else
        {
            result.push_back({curr.r, 0});
            result.push_back({top.l, top.h});
            curr = top;
        }        
    }
    result.push_back({curr.r,0});

    return result;

 }
};
int main() {
Solution s;
vector<vector<int>> b {{1,11,3},{2,6,7},{3,13,9}, {12, 7, 16},{14, 3, 25},{19, 18, 22},{23, 13, 29},{24, 4, 28}};

for(auto r : s.getSkyline(b))
{
    cout<<r[0] <<' '<<r[1]<<endl;
}
return 0;
}