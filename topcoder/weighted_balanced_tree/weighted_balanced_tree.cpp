#include <iostream>
#include <vector>

using namespace std;

#define REP(i, n) for(int i = 0 ; i < n ; ++i) 
#define SIZE(v) v.size()



int main ()
{
    vector<int> v(100,0);
    SIZE(v);
    int n = SIZE(v);
    REP(i,n) cout<<i<<' ';
    cout<<endl;

    REP(i,n) cout<<i*2<<' '; 
}
