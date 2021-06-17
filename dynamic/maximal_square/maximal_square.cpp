#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;


class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();

        int i=0,j=0,i2=0, j2=0, w=1, maxwsize =0;

        while (i < m-w+1 && j < n-w+1)
        {
            for(i2 = i; i2 < i + w; ++i2)
            {
                for(j2 = j; j2 < j+w; ++j2)
                {
                    if(matrix[i2][j2] != '1')
                    break;
                }
                if(j2 != j+w)
                    break;
            }
            if(i2 == i + w && j2 == j + w)
            {
                maxwsize = max(maxwsize, w);
                w++;
            }
            else
            {
                if(j < n-w) 
                    j++;
                else
                {
                    i++; j = 0;
                }
            }
        }
        return maxwsize*maxwsize;

    }
};

int main()
{
    Solution s;
    vector<vector<char>> test= {{'0','0','0','1'},{'1','1','0','1'},{'1','1','1','1'},{'0','1','1','1'},{'0','1','1','1'}};
    //{ { '1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'} };
    cout << s.maximalSquare(test);
}