#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <tuple>
#include <string>

using namespace std;


class Solution 
{
    public:
    string custom_sort(string S, string T)
    {
        vector<int> order(26,-1);
        int i = 1;
        for(auto c: S) 
            order[c-'a'] = i++;

        auto comp = [&](char a, char b){
            return order[a-'a'] < order[b-'a'];
        };

        sort(T.begin(), T.end(), comp);
        return T;
    }
};

int main()
{
    Solution s;
    cout << s.custom_sort("bcd","rafbcfrdeee");
}