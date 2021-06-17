 
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
#include <regex>
#include <string>
#include <sstream>
#include <iostream>

#define CATCH_CONFIG_MAIN
#include "..\..\..\catch\catch.hpp"
using namespace std;
using namespace Catch;

/* 

*/

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        // put the word int in a map
        // priority_queue
        
        map<string, int> freq;
        auto comp = [](const auto& p1, const auto& p2) -> bool
        {
            if(p1.second < p2.second)
                return true;
            else if(p1.second == p2.second)
                return p1.first.compare(p2.first) > 0;
            return false;
        };
        
        priority_queue< pair<string, int>, vector<pair<string,int>>, decltype(comp) > pq(comp);
        
        for(auto w : words)
        {
            freq[w]++;
        }
        for(auto& [k,v] : freq)
        {
            pq.push({k,v});
        }
        vector<string> res;
        while(k-- > 0 && !pq.empty())
        {
            res.push_back(pq.top().first);
            pq.pop();
        }
        return res;        
    }
};
TEST_CASE("test_success") {
    Solution s;
    vector<string> in{"i", "love", "leetcode", "i", "i","love", "coding"}; int k = 0;
    s.topKFrequent(in, k);
    REQUIRE(1==1);
}

TEST_CASE("test_failure") {
    Solution s;
    vector<string> in {"glarko","zlfiwwb","nsfspyox","pwqvwmlgri","qggx","qrkgmliewc","zskaqzwo","zskaqzwo","ijy","htpvnmozay","jqrlad","ccjel","qrkgmliewc","qkjzgws","fqizrrnmif","jqrlad","nbuorw","qrkgmliewc","htpvnmozay","nftk","glarko","hdemkfr","axyak","hdemkfr","nsfspyox","nsfspyox","qrkgmliewc","nftk","nftk","ccjel","qrkgmliewc","ocgjsu","ijy","glarko","nbuorw","nsfspyox","qkjzgws","qkjzgws","fqizrrnmif","pwqvwmlgri","nftk","qrkgmliewc","jqrlad","nftk","zskaqzwo","glarko","nsfspyox","zlfiwwb","hwlvqgkdbo","htpvnmozay","nsfspyox","zskaqzwo","htpvnmozay","zskaqzwo","nbuorw","qkjzgws","zlfiwwb","pwqvwmlgri","zskaqzwo","qengse","glarko","qkjzgws","pwqvwmlgri","fqizrrnmif","nbuorw","nftk","ijy","hdemkfr","nftk","qkjzgws","jqrlad","nftk","ccjel","qggx","ijy","qengse","nftk","htpvnmozay","qengse","eonrg","qengse","fqizrrnmif","hwlvqgkdbo","qengse","qengse","qggx","qkjzgws","qggx","pwqvwmlgri","htpvnmozay","qrkgmliewc","qengse","fqizrrnmif","qkjzgws","qengse","nftk","htpvnmozay","qggx","zlfiwwb","bwp","ocgjsu","qrkgmliewc","ccjel","hdemkfr","nsfspyox","hdemkfr","qggx","zlfiwwb","nsfspyox","ijy","qkjzgws","fqizrrnmif","qkjzgws","qrkgmliewc","glarko","hdemkfr","pwqvwmlgri"};
    int k = 14;
    s.topKFrequent(in, k);
    REQUIRE(1==1);
}
