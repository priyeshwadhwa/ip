#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <tuple>

using namespace std;

class Solution
{
    public:
    vector<int> k_most_frequent_elements(vector<int> nums, int k)
    {
        int n = nums.size();
        unordered_map<int, int> freq_map;
        for (auto a : nums)
        {
            freq_map[a]++;
        }

        vector<vector<int>> bucket(n+1);
        for (auto &f : freq_map)
        {
            bucket[f.second].push_back(f.first);
        }

        vector<int> res;
        for_each(bucket.rbegin(), bucket.rend(), [&](auto &b) {
            for_each(b.begin(), b.end(), [&](auto &e) {
                if (k > 0){
                    res.push_back(e);
                    k--;
                }
            });
        });

        return res;
    }
};

int main()
{
    Solution s;
    auto res = s.k_most_frequent_elements({1, 1, 1, 1 ,2}, 3);
    for (auto r : res)
    {
        cout << r << ' ';
    }
}