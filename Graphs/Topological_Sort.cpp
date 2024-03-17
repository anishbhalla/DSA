#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_map>
#include <list>
#include <stack>
#include<utility>
using namespace std;
/*Topological Sort (Using DFS)*/

void topoSort(int node, unordered_map<int, bool> &visited, stack<int> &s, unordered_map<int, list<int>> adj)
{
    visited[node] = 1;

    for (auto neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            topoSort(neighbour, visited, s, adj);
        }
    }
}

vector<int> TopologicalSort(vector<pair<int, int>> &edges, int v, int e)
{
    // Preparing Adjacency List
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < e; i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
    }

    // Call dfs topological sort utility function for all components.
    unordered_map<int, bool> visited;
    stack<int> s;
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            topoSort(i, visited, s, adj);
        }
    }

    vector<int> ans;

    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}

void display(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int vertex;
    cout << "Enter the number of Vertices in the Graph :";
    cin >> vertex;

    int m;
    cout << "Enter the number of edges :";
    cin >> m;

    vector<pair<int, int>> edges(m);

    cout << "Enter Edge :" << endl;
    for (int i = 0; i < m; i++)
    {
        int u;
        int v;
        cout << "Edge number " << i + 1 << "-" << endl;
        cout << "u :";
        cin >> u;
        cout << "v :";
        cin >> v; // Node value.

        pair<int,int> p;
        p = make_pair(u,v);
        edges.push_back(p);
    }

    // Printing topologically Sorted Array.
    vector<int> ans = TopologicalSort(edges, vertex, m);
    cout<<"Topological Sort is :"<<endl;
    display(ans);
    return 0;
} 