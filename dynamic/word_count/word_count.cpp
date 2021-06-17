#include <iostream>
#include <string>
#include <vector>

using namespace std;


class AnonymousLetter{
  public:
    bool CanWriteAnonymousLetter(const string& L, const string& N)
    {
      vector<int> wc(256,0);
      for(auto &c : N)
      {
        wc[c]++;
      }
      
      for(auto &c: L)
      {
        if(wc[c] == 0)
          return false;
        wc[c]--;
      }
      return true;
    }
    
};

int main()
{
    AnonymousLetter sol;
    cout << sol.CanWriteAnonymousLetter("xxx","dearfriend");
    return 0;

  
}