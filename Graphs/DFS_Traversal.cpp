#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
using namespace std;
/*Depth First Search Traversal in Graphs*/
/*Problem Statement : Given an undricted graph G(V,E), containing 'V' vertices and 'E' edges. Your task is to print its DFS traversal matrix.*/

void dfs(int node,unordered_map<int,bool> &visited, unordered_map<int,list<int>> &adj,  vector<int> &component){
    component.push_back(node);
    visited[node] = true;

    // Recursive call for every connected node.
    for ( auto i: adj[node] )
    {
        if(!visited[i]){
            dfs(i,visited,adj,component);
        } 
    }
}

vector<vector<int>> DFS(int vertex, vector<pair<int,int>> &edges)
{
    // Preparing Adjacency List
    unordered_map<int,list<int>> adj; // Adjancency list object.
    for (int i = 0; i < vertex; i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u); // 'u' to 'v' and 'v' to 'u' i.e undirected graph condition.
    }

    vector<vector<int>> ans; // Answer matrix of  DFS traversal.
    unordered_map<int,bool> visited;

    for (int i = 0; i < vertex; i++)
    {
        if(!visited[i]){
            vector<int> component; // Component representing a single level in the Graph.
            dfs(i,visited,adj,component);
            ans.push_back(component); // Pushing that that component into 'ans' matrix.
        }
    }
    return ans;
}

void display(vector<vector<int>> &ans){
     for (int i = 0; i < ans.size(); i++)  
    { 
        for (int j = 0; j < ans[i].size(); j++) 
        { 
            cout << ans[i][j] << " "; 
        }     
        cout << endl; 
    } 
}

int main(){
    int vertex;
    cout<<"Enter the number of Vertices in the Graph :"; cin>>vertex;

    int m;
    cout<<"Enter the number of edges :";cin>>m;

    vector<pair<int,int>> edges(m);

    cout<<"Enter Edge :"<<endl;
    for (int i = 0; i < m; i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        cout<<"Edge number "<<i+1<<"-"<<endl;
        cout<<"u :";cin>>u;cout<<"v :";cin>>v; // Node value.
        
    }

    // Printing DFS Traversed answer matrix.
    vector<vector<int>> ans = DFS(vertex,edges);
    display(ans);       
    return 0;
}