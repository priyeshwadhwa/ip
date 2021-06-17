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
#include <iostream>
#include <regex>
using namespace std;

class Solution {
public:
    void remove_vowels(string &in)
    {
        regex e ("[AEIOUaeiou]");
        in = regex_replace(in,e,"");
        
    }
};  
int main() {
Solution s;
string in("ABCDE");
s.remove_vowels(in);
cout << in ;

return 0;
}