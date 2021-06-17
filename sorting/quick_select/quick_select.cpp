#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <tuple>

using namespace std;

int partition(vector<int> &a, int s, int e)
{
    int p = a[s];
    int p_i = s;

    while (s <= e)
    {
        if(a[s] > p){
            swap(a[s], a[e]);
            e--;
        }
        else
        {
            s++;
        }
    }
    a[p_i] = a[e];
    a[e] = p;
    return e;

}

int quick_select(vector<int> a, int k)
{
    int n = a.size();
    int s = 0;
    int e = n-1;

    while(true)
    {
        int pos = partition(a, s, e);
        if(pos == k)
            return a[pos];
        else if(pos < k)
        {
            s = pos + 1;
        }
        else
        {
            e = pos -1;
        }
    }
}

void merge(vector<int> & a)
{
    int n = a.size();
    int h = n/2;
    vector<int> t(n);
    for(int i = 0 ;i < h; i+=2)
    {
        t[i] = a[i];
        t[i+1] = a[h+i];
    }
    if(a.size() != t.size())
        t[n-1] = a[n-1];
    a = t;
}

int main()
{
    vector<int> a{9,3,4,1,5,0};
    cout << quick_select(a, 3);
    merge(a);
}