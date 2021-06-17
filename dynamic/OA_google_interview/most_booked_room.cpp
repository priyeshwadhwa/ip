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
using namespace std;


class Solution
{
    public:
    string most_booked_room(vector<string> bookings)
    {
        auto book_count = vector<vector<int>>(10, vector<int>(26,0));

        int max_booked_room_count = 0;
        string max_booked_room;

        for(auto b : bookings)
        {
            if(b[0]=='+')
                book_count[b[1]-'0'][b[2]-'A']++;
            if(max_booked_room_count < book_count[b[1]-'0'][b[2]-'A'])
            {
                max_booked_room_count = book_count[b[1]-'0'][b[2]-'A'];
                max_booked_room = b.substr(1);
            }
        }
        return max_booked_room;

    }

};

int main()
{
    Solution s;
    cout << s.most_booked_room({"+1A", "+3E", "-1A", "+4F", "+1A", "-3E"});
    return 0;
}