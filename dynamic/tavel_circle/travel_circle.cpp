#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

int travel_circle(vector<int> gas, vector<int> miles)
{
    int n = gas.size();
    int startindex = 0;

    while (startindex < n)
    {
        int tank = 0;
        int i = startindex;

        while(tank + gas[i] >= miles[i] )
        {
            tank += (gas[i] - miles[i]);
            i = (i+1) % n;
            if( i == startindex)
                return startindex; 
        }
        startindex = i+1;
    }
    return -1;
}

int main()
{
    cout << travel_circle({2,3,10,11}, {4,7,2,3});
}