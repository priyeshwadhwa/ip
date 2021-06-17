#include <iostream>
#include <vector>
using namespace std;
class CompletelyDifferentStrings
{
    public:
    int count(int S, vector<string> f)
    {
        int chars = 0;
        int n = f.size();
        int L = f[0].size();
        int ans = 1;
        for(int j = 0 ; j < L; ++j)
        {
            chars = 0;
            for(int i = 0 ; i < n; ++i)
            {
                chars |= (1<<(f[i][j]-'a'));
            }
            ans *= (S-oneSetCount(chars));
        }
        return ans;
    }
    int oneSetCount(int n)
	{
        int num = 0;
        while(n!=0){
        	n  = n & (n-1)   ;
            num++;
		}
        return num;
    }
};

int main()
{
    CompletelyDifferentStrings s;
    cout << s.count(3,{"ab"});
}