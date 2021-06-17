#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <tuple>

using namespace std;

void wiggle_sort(vector<int>& a)
{
    for(int i = 0 ; i < a.size() - 1; ++i)
    {
        if(i%2 == 0)
        {
            if(a[i] > a[i+1])
                swap(a[i], a[i+1]);
        }
        else
        {
            if(a[i] < a[i+1])
                swap(a[i], a[i+1]);
        }
    }
}

int main()
{
    vector<int> a{3,5,2,1,7,8,9};
    wiggle_sort(a);
    for(auto i : a)
        cout<<i << ' ';
}