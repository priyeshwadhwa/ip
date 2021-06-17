

#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
#include <tuple>

using namespace std;

class Solution
{
public:
    vector<int> bikeAssignment(vector<vector<int>> workers, vector<vector<int>> bikes)
    {
        // comparison for the pq. (dist, w, b) . we want a min heap so implement the greater<> function
        auto comp = [](tuple<int, int, int> a, tuple<int, int, int> b) -> bool {
            int dist_a, w_a, b_a, dist_b, w_b, b_b;
            tie(dist_a, w_a, b_a) = a;
            tie(dist_b, w_b, b_b) = b;

            if (dist_a != dist_b)
                return dist_a > dist_b;
            if (w_a != w_b)
                return w_a > w_b;
            return b_a > b_b;
        };
        priority_queue<
            tuple<int, int, int>,
            vector<tuple<int, int, int>>,
            decltype(comp)>
            pq(comp);

        int W = workers.size();
        int B = bikes.size();

        for (int w = 0; w < W; ++w)
        {
            for (int b = 0; b < B; ++b)
            {
                auto w_entry = workers[w];
                auto b_entry = bikes[b];
                pq.push(make_tuple(abs(w_entry[0] - b_entry[0]) + abs(w_entry[1] - b_entry[1]), w, b));
            }
        }

        vector<int> worker(W, -1);
        vector<int> bike(B, -1);

        while (!pq.empty())
        {
            int dist, w, b;
            tie(dist, w, b) = pq.top();
            pq.pop();

            // if the worker has not yet been assigned a bike, 
            //and the bike is not yet assigned to a worker
            if (worker[w] == -1 && bike[b] == -1)
            {
                worker[w] = b;
                bike[b] = w;
            }
        }
        return worker;
    }
};

int main()
{
    Solution s;
    auto res = s.bikeAssignment({{0, 0}, {1, 1}, {2,0}}, {{1, 0}, {2, 2},{2,1}});
    for(auto& a: res)
        cout<< a<<' ';

}