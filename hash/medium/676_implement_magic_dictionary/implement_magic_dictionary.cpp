 
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

Implement a magic directory with buildDict, and search methods.

For the method buildDict, you'll be given a list of non-repetitive words to build a dictionary.

For the method search, you'll be given a word, and judge whether if you modify exactly one character into another character in this word, the modified word is in the dictionary you just built.

Example 1:
Input: buildDict(["hello", "leetcode"]), Output: Null
Input: search("hello"), Output: False
Input: search("hhllo"), Output: True
Input: search("hell"), Output: False
Input: search("leetcoded"), Output: False
Note:
You may assume that all the inputs are consist of lowercase letters a-z.
For contest purpose, the test data is rather small by now. You could think about highly efficient algorithm after the contest.
Please remember to RESET your class variables declared in class MagicDictionary, as static/class variables are persisted across multiple test cases. Please see here for more details.

*/


/**************
 * There is an easy implementation using set and map.. 
 * in the set we store all the words
 * in the 
 * /


struct TrieNode
{
    bool isWord;
    shared_ptr<TrieNode> n[26];
    TrieNode() : isWord(false)
    { }
};

class MagicDictionary {
    shared_ptr<TrieNode> root;
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        root = make_shared<TrieNode>();
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for(auto& word : dict)
        {
            auto temp = root;
            for(auto c : word)
            {
                if(temp->n[c-'a'] == nullptr)
                    temp->n[c-'a'] = make_shared<TrieNode>();
                temp = temp->n[c-'a'];
            }
            temp->isWord=true;
        }
    }
    
    bool match(shared_ptr<TrieNode> root, string word)
    {
        auto temp = root;
        for(int i = 0; i < word.size(); ++i)
        {
            char c = word[i];
            if(temp->n[c-'a'] == nullptr)
                return false;
            temp = temp->n[c-'a'];
        }
        return temp->isWord;
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        
        auto temp = root;
        for(int i = 0; i < word.size(); ++i)
        {
            for(int j = 0; j < 26; ++j)
            {
                char c = 'a' + j;
                if(c == word[i]) continue;
                char orig = word[i];
                word[i] = c;
                if(match(root, word))
                    return true;
                word[i] = orig;              
            }
        }
        return false;
    }
};


TEST_CASE("test_success") {
    MagicDictionary s;
    vector<string> test{"hello", "leetcode"};
    s.buildDict(test);
    REQUIRE(s.search("hhllo")== true);
}

TEST_CASE("test_success1") {
    MagicDictionary s;
    vector<string> test{"hello", "hallo", "leetcode"};
    s.buildDict(test);
    REQUIRE(s.search("hello")== true); // true because 'hallo' is the right answer for 'hello', even though 'hello' is present in the dict
}


//["MagicDictionary", "buildDict", "search", "search", "search", "search"]
//[[], [["hello","hallo","leetcode"]], ["hello"], ["hhllo"], ["hell"], ["leetcoded"]]
