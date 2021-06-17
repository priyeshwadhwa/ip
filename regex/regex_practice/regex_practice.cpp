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

using namespace std;

#define CATCH_CONFIG_MAIN  
#include "..\..\catch\catch.hpp"

/**

Notes:
\d \D \w \W \b \B ^ $ \s \S | [^ ] ?
regex_match --> must match the whole target
regex_search -- > sub matches

groups -- ()
non capturing groups (?:)
reusing the submatch \<int> \1 \2 etc.

Lazy-ungreedy qualifier ?

positive look ahead (?=)  Ex foo(?=bar)  -- match foobar but not foobaz
negative look ahead (?!)  Ex foo(?=bar)  -- match foobaz but not foobar
*/

class LearnMatchResults
{
    public:
        int regex_search_positive_lookahead()
        {
            string str = "ob";

            regex re(R"(o(?=b))");

            smatch sm;
            cout << regex_search(str,sm,re);
            for(auto s: sm)
            {
                cout<<s.str();
            }
            return sm.size();
        }

        int regex_search_negative_lookahead()
        {
            string str = "obok";

            regex re(R"(o(?!b))");

            smatch sm;
            cout << regex_search(str,sm,re);
            cout << "prefix " << sm.prefix()<< '\n';
            cout << "suffix " << sm.suffix()<< '\n';
            for(auto s: sm)
            {
                cout<<s.str();
            }
            return sm.size();
        }

        int recursive_use_of_regex_search()
        {
            string str = "foobarfoobaz fooman foocar";

            regex re("foo");
            smatch sm;

            while( regex_search(str, sm, re) )
            {
                for(auto s:sm)
                {
                    cout<< s.str();
                    cout << s.length();
                    
                }
                str = sm.suffix();
            }
            return sm.size();

        }

        int regex_iterator_use()
        {
            string str = "foobarfoobaz fooman foocar";

            regex re("foo");
            smatch sm;

            sregex_iterator begin(str.begin(), str.end(), re);
            sregex_iterator end;
            for(auto it = begin; it!=end;++it)
            {
                cout<< (*it).str(0);
            }

            return 0;
        }
};



TEST_CASE("Test regex", "vector")
{
    LearnMatchResults l;
    //REQUIRE(l.regex_search_positive_lookahead() == 1);

    //REQUIRE( l.regex_search_negative_lookahead() == 1);

    //REQUIRE( l.recursive_use_of_regex_search() == 0);


    SECTION("test scenario")
    {
        REQUIRE(1==1);
    }
}

SCENARIO("test_scenario")
{
    GIVEN("given a b c")
    {
        //do set up here... // like a fixture.
        WHEN("blah happen")
        {
            //make test specific change. update fixture
            THEN("Foo should die")
            {
                // REQUIRE() // checks for impact
            }
        }

        WHEN("boo calls")
        {
           THEN("foo replies")
            {

            }
        }
    }
}






class Solution {
public:
    string defangIPaddr(string address) {
        regex ip("[.]");

     

        return regex_replace(address, ip, "[$&]");
    }
};

TEST_CASE("ip fannig")
{
    Solution s;

    REQUIRE(s.defangIPaddr("10.4.4.6") == "10[.]4[.]4[.]6");
}


class Solution890 {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        
        vector<string> res;

        for(auto &word: words)
        {
            if(pattern.size() != word.size())
                continue;

            unordered_map<char, char> pm;
            unordered_map<char, char> wm;
            bool match = true;
            for(int i = 0 ; i <word.size(); ++i)
            {
                if(pm.find(pattern[i]) != pm.end())
                {
                    if(pm[pattern[i]] != word[i])
                    {
                        match = false;
                        break;
                    }
                }
                if(wm.find(word[i]) != wm.end() )
                {
                    if(wm[word[i]] != pattern[i])
                    {
                        match = false;
                        break;
                    }
                }
                pm[pattern[i]] = word[i];
                wm[word[i]] = pattern[i];
            }
            if(match)
                res.push_back(word);
        }
        return res;
    }
};


TEST_CASE("pattern_test")
{
    Solution890 s;
    vector<string> test_1{"abc", "mee"};

    auto res_1 = s.findAndReplacePattern(test_1, "abb");

    REQUIRE( res_1[0] == "mee");


    vector<string> test_2{"abc", "me", "dasdfasdf", "lmm"};

    auto res_2 = s.findAndReplacePattern(test_2, "abb");

    REQUIRE( res_2[0] == "lmm");

}

TEST_CASE("empty_string_tests")
{
    Solution890 s;
    vector<string> test{"", "", "dasdfasdf", "lmm"};

    auto res = s.findAndReplacePattern(test, "");

    REQUIRE( res[0] == "");
    REQUIRE( res[1] == "");
}

TEST_CASE("no_match_test")
{
    Solution890 s;
    vector<string> test{"", "", "dasdfasdf", "nnn"};

    auto res = s.findAndReplacePattern(test, "dd3");

    REQUIRE( res.empty());

    REQUIRE(make_pair('a','b') == make_pair('a','b'));

}