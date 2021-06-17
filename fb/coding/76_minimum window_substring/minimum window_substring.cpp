 
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



class Solution {
public:
    string minWindow(string s, string t) {
        struct {int len; int l; int r;} sol{-1,0,0};
        
        unordered_map<char, int> freq; // freq map for t
        for(auto c : t)
            freq[c]++;
        
        int required = freq.size(); // required number of unique chars count.
        int l = 0, r = 0;
        int formed = 0; // unique char count when they meet the freq.
        unordered_map<char,int> window_freq;
        
        while (r < s.length())
        {
            // 1. put the s[r] in window_freq
            char c = s[r];
            window_freq[c]++;
            
            //2 update formed. if we have the c 
            if(freq.count(c) && window_freq[c] == freq[c])
                formed++;
            
            //3 move l if all the 
            while (l <= r && formed == required)
            {
                char c = s[l];
                if(sol.len == -1 || r-l+1 < sol.len)
                {
                    sol.len = r - l + 1;
                    sol.l = l;
                    sol.r = r;
                }
                
                //now remove the char c from the window_freq
                // and update the formed if we fall short on the count
                window_freq[c]--;
                if(freq.count(c) && window_freq[c] < freq[c])
                    formed--;
                
                l++;
            }
            r++;
        }
        return sol.len == -1 ? "" : s.substr(sol.l, sol.r - sol.l + 1 );
    }

    string minWindow2(string s, string t) {
	unordered_map<char, int> m;
	// Statistic for count of char in t
	for (auto c : t) m[c]++;
	// counter represents the number of chars of t to be found in s.
	size_t start = 0, end = 0, counter = t.size(), minStart = 0, minLen = INT_MAX;
	size_t size = s.size();
	
	// Move end to find a valid window.
	while (end < size) {
		// If char in s exists in t, decrease counter
		if (m[s[end]] > 0)
			counter--;
		// Decrease m[s[end]]. If char does not exist in t, m[s[end]] will be negative.
		m[s[end]]--;
		end++;
		// When we found a valid window, move start to find smaller window.
		while (counter == 0) {
			if (end - start < minLen) {
				minStart = start;
				minLen = end - start;
			}
			m[s[start]]++;
			// When char exists in t, increase counter.
			if (m[s[start]] > 0)
				counter++;
			start++;
		}
	}
	if (minLen != INT_MAX)
		return s.substr(minStart, minLen);
	return "";
}
};

TEST_CASE("test_success") {
    Solution s;
    
    //s.minWindow("ADOBECODEBANC","ABC");
    s.minWindow2("ADOBECODEBANC","ABC");

}


TEST_CASE("test_failure") {
    Solution s;
    REQUIRE(1==1);
}
