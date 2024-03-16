#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
#include<vector>
using namespace std;
/*Breadth First Search Traversal in Graphs*/ 
/*Problem Statement : You are given an undirected and disconnected graph G(V,E) having V vertices number from 0 to V-1 and E edges. Your task is to print its BFS traversal starting from the 0th vertex.*/

void prepareAdjList(unordered_map<int,list<int>> &adjList, vector<pair<int,int>> edges){
    for (int i = 0; i < edges.size(); i++) // Until total number of edges reached.
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].push_back(v);
        adjList[v].push_back(u);  // 'u' to 'v' and 'v' to 'u' i.e undirected graph condition.
    }
}

void bfsImplement(unordered_map<int,list<int>> &adjList, unordered_map<int,bool> &visited, vector<int> &ans,int node){
    queue<int> q;
    q.push(node); // Pushing node to queue.
    visited[node] = 1; // Making visited for that node as 'True(1)'.

    while (!q.empty()){  // As long as queue is not empty.
        int frontNode = q.front(); // Storing front node of queue in a variable.
        q.pop(); // Poping the front node.

        // Storing front Node into ans.
        ans.push_back(frontNode);
        
        // Traverse all neighbours of frontNode in the adjacency list.
        for (auto i : adjList[frontNode])
        {
            if(!visited[i]){ // If neighbour is not visited in adjacency List.
                q.push(i); // Pushing it in queue
                visited[i] = 1; // Making visited as 'True(1)'.
            }
        }
        
    }
}

vector<int> BFS(int vertex, vector<pair<int,int>> edges){
    unordered_map<int,list<int>> adjList; // Empty adjacency List map object.
    vector<int> ans; // Will store the traversed array.
    unordered_map<int,bool> visited; // Will store 'False(0)' for all nodes by default.

    prepareAdjList(adjList, edges); // Preparing adjacency list by adding 'u' and 'v' into the adjacency list.

    // Traverse all components(OR Vertices) of a graph.
    for (int i = 0; i < vertex;i++) // Loop for disconnected graph condition.
    {
        if (!visited[i]){
            bfsImplement(adjList,visited,ans,i);
        }
    }
    return ans;
}

void printAdjList(unordered_map<int,list<int>> &adjList){  // Printing adjacency List.
    for (auto i:adjList){
        cout<<i.first<<"->";
        for (auto j: i.second){
            cout<<j<<",";
        }
        cout<<endl;
    }
}

void display(vector<int> &arr)
{
    for(int i = 0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
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
   
    // Printing BFS traversed Array.
    vector<int> ans = BFS(vertex,edges);
    display(ans);
    return 0;
}
