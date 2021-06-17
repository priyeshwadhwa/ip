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
#include <iostream>
#define CATCH_CONFIG_MAIN
#include "..\..\catch\catch.hpp"
using namespace std;

/*
Given two lists A and B, and B is an anagram of A. B is an anagram of A means B is made by randomizing the order of the elements in A.

We want to find an index mapping P, from A to B. A mapping P[i] = j means the ith element in A appears in B at index j.

These lists A and B may contain duplicates. If there are multiple answers, output any of them.

For example, given

A = [12, 28, 46, 32, 50]
B = [50, 12, 32, 46, 28]

We should return

[1, 4, 3, 2, 0]
*/

class Solution{
    public:
    vector<int> find_anagram_mapping(const vector<int> &A, const vector<int>& B)
    {
        if(A.size() != B.size())
            return {};

        vector<int> res(A.size(), 0);
        unordered_map<int, int> m;

        for(auto a: A)
        {
            m[a] = 0;
        }
        for(int i = 0; i < B.size(); ++i)
        {
            m[B[i]] = i;
        }
        for(int i= 0; i < A.size(); ++i)
        {
            res[i] = m[A[i]];
        }
        return move(res);


    }
};

TEST_CASE("find_anagram_mapping_test")
{

    vector<int> A{12,3,4}, B{4,12,3};
    Solution s;
    REQUIRE_THAT(s.find_anagram_mapping(A,B), Catch::Equals(std::vector<int>({1,2,0}) )) ;

}