
#include <map>
#include <vector>
#include <string>
#include <set>
#include <unordered_set>

#include <numeric>

#include <iostream>

#include <algorithm>

using namespace std;

struct Node{
    int val;
};

//adjacency matrix
vector<vector<int>> adjmatrix;
vector<unordered_set<int>> adjlist;
vector<set<int>> adjlist;

class Graph
{
    vector<int> nodes;
    vector<vector<int>> adj;
    public:
        Graph(int n): nodes(n) {
            
            std::iota(nodes.begin(), nodes.end(), 0);
        }
        void addEdge(int a, int b, int w=0);
};

class GraphAdjList
{
    vector<int> nodes;
    vector<vector<int>> adjList;


    public:
        GraphAdjList(int n):
            nodes(n),
            adjList(n, vector<int>()) 
        {
            std::iota(nodes.begin(), nodes.end(), 0);
        }

        void addEdge(int a, int b, int w=0)
        {
            adjList[a].push_back(b);
        }
};

int main()
{
    Graph g(10);
}