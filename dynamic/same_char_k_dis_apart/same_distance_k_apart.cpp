
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
using namespace std;

class solution{

    public:
    

    
    string do_apart(string s, int k)
    {

        unordered_map<char,int> char_count;
        for(auto c : s)
        {
            char_count[c]++;
        }


        auto comp = [] (const pair<char, int> &a, const pair<char,int> &b )
        {
            return a.second < b.second;
        };

        priority_queue< pair<char,int>,vector<pair<char,int>>, decltype(comp)> pq(comp);
        for(auto e: char_count)
        {
            pq.emplace(e.first,e.second);
        }

        string res;
        int len = s.size();
        while(!pq.empty())
        {
            vector<pair<char,int>> t;
            //pop the first k elements and put the string 

            int cnt = min(len, k);
            for(int i = 0; i < cnt ;++i)
            {
                if(pq.empty()) return "";

                auto v = pq.top();
                
                pq.pop();
                res+=v.first;
                if (v.second>1)
                    t.push_back({v.first,v.second-1});
                len--;                
            }
            for(auto e : t)
                pq.emplace(e.first,e.second);
        }
        return res;
    }

};

int main()
{
    solution s;
    cout<< s.do_apart("aaa",1);
}


/*
std::make_heap -- creates a max heap.  default < 
std::push_heap 
std::pop_heap -- 

priority_queue -- top, push, pop  max_heap. default <

*/