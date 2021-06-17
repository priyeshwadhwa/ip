#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <stack>

using namespace std;

class Dict{
    public:
    Dict() 
    {
        words = {"cats", "sand", "cat", "dogs", "and"};
    }
    bool isWord(const string& w) const
    {
        if(words.find(w)!= words.end())
            return true;
        else
        {
            return false;
        }
        
    }
    private:
    set<string> words;

};

vector<string> ValidateText(string text, Dict dict)
{
    map<int/*start index*/, vector<int> /*end indices*/> m;

    for(int i = 0; i < text.size(); i++)
    {
        for (int j = i; j < text.size();){
            if( dict.isWord(text.substr(i, j)) )
            {
                auto it = m.find(i);
                if( it == m.end())
                    m.insert({i,{j}});
                else
                    it->second.push_back(j);
            }
        }
    }

    // Now we have our memoization done for all the words we have found.
    //catsanddogs 0,2  0,3 3,6 4,6 7,11

    // now we have a graph created in the map. we need to dfs for paths that reaches the end of string.

    stack<pair<int,int>> s;
    auto start = m.find(0);
    for_each(start->second.begin(), start->second.end(), [](auto& first_word_boundary) {
        m.find(first_word_boundary);

    });

    s.push(m.find(0));

    while(!s.empty())
    {
        auto it = s.top();


    }

    


    for(int i = 0 ; i < text.size(); )
    {
        auto it = m.find(i);
        if(it != m.end())
        {
            string str;
            for_each(it->second.begin(), it->second.end(), [](){
                str +=  
            });
        }
    }

}


int main()
{
    Dict d;
    auto v = ValidateText("catsanddogs", d);
    for_each(v.begin(), v.end(), [](auto &s){
        cout<<s<<endl;

    })
    return 0;
}