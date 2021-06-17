#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <tuple>

using namespace std;

void three_color_sort(vector<int> &a)
{
    int n = a.size();
    int i = 0;
    int j = n-1;
    int k = 0;

    while(k < j)
    {
        while (a[i] == 0) i++;
        while( a[j] == 2) j--;

        if(i >= j) break;

        k = i;

        while(a[k] == 1 && k < j)
            k++;

        if(a[k] == 2)
            swap(a[k], a[j]);
        else
            swap(a[k], a[i]);        
    }
}
void three_color_sort2(vector<int> &a)
{
    int i = 0, j = 0;
    for(int k =0 ;k<a.size(); ++k)
    {
        int v = a[k];
        a[k] = 2; // we first assign 2
        if(v < 2) // but if value was less than 2, assign 1 to a[j], if v was 1 we are good.
        {
            a[j++] = 1;
        }
        if(v == 0) // but if v was 0, a[i] =0 will take one 1 and make it 0.
        {
            a[i++] = 0;
        }
    }
}

int main()
{
    vector<int> a{2,1,1,1,2,0,0,1,1}; 
    //three_color_sort(a);
    for(auto i:a)
        cout<< i << ' ';
    three_color_sort2(a);
    for(auto i:a)
        cout<< i << ' ';
}