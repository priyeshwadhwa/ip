#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include<unordered_map>

using namespace std;

class Solution {
    unordered_map<string, vector<string>> m;

    vector<string> combine(string word, vector<string> prev){
        for(int i=0;i<prev.size();++i){
            prev[i]+=" "+word;
        }
        return prev;
    }

public:
    vector<string> wordBreak(string s, vector<string>& dict) {
        if(m.count(s)) return m[s]; //take from memory
        vector<string> result;
        if(find(dict.begin(), dict.end(), s) != dict.end()){ //a whole string is a word
            result.push_back(s);
        }
        for(int i=1;i<s.size();++i){
            
            string word=s.substr(i);
            
            if(find(dict.begin(), dict.end(), word) != dict.end()){// word found in the end.. iceland
                
                string rem=s.substr(0,i);
                vector<string> prev=combine(word,wordBreak(rem,dict)); // iceland -- recurse with remaining string..  and combine the strings
                
                result.insert(result.end(),prev.begin(), prev.end()); // 
            }
        }
        m[s]=result; //memorize
        return result;
    }
};

class Solution
{
public:
    vector<string> wordBreak(string s, vector<string> wordDict)
    {

        int n = s.length();
        
        //array representation of the sting problem... 
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        vector<string> result;

        for (int i = 0; i < n; ++i)
        {
            for (int j = i; j < n; ++j)
            {
                if (find(wordDict.begin(), wordDict.end(), s.substr(i, j - i + 1)) != wordDict.end())
                {
                    dp[i][j] = 1;
                }
            }
        }
        string res;


    // the solution is to go recursive on the array
    // 
        int lastcol = n-1;
        while(lastcol>=0)
        {
            for (int r = 0; r < n; ++r)
            {
                if (dp[r][c] == 1)
                {
                    if (r == 0)
                    {
                        res = s.substr(r, c - r + 1) + res; 
                        result.push_back(res);
                        res.erase();
                    }
                    else
                    {
                        res = " " + s.substr(r, c - r + 1) + res;
                    }
                    c = r - 1;
                }

        }


        int c = n - 1;
        int lastcol = n-1;
        for (int i = 0; i < n; ++i)
        {
            if (dp[i][c] == 1)
            {
                if (i == 0)
                {
                    res = s.substr(i, c - i + 1) + res;
                    result.push_back(res);
                    res.erase();
                }
                else
                {
                    res = " " + s.substr(i, c - i + 1) + res;
                }

                c = i-1;
                while (c >= 0)
                {
                    for (int r = 0; r < n; ++r)
                    {
                        if (dp[r][c] == 1)
                        {
                            if (r == 0)
                            {
                                res = s.substr(r, c - r + 1) + res; 
                                result.push_back(res);
                                res.erase();
                            }
                            else
                            {
                                res = " " + s.substr(r, c - r + 1) + res;
                            }
                            c = r - 1;
                        }
                    }
                }
            }
        }

        return result;
    }
};

int main()
{
    Solution s;
    for(auto s : s.wordBreak("iliveiniceland", {"i","live","in","ice","and","india", "land", "iceland"}))
        cout<<s<<endl;

    for(auto s : s.wordBreak("catsanddog", {"cat","cats","and","sand","dog"}))
        cout<<s<<endl;

}