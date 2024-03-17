#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;
/*Graph Code*/

class Graph{
    public:
    unordered_map<int,list<int>> adj;

    void addEdge(int u,int v, bool direction){  // Here u and v are the nodes consisting of an edge between them.
        /*
        Direction = 0 -> Undirected
        Direction = 1 -> Directed
        */
       adj[u].push_back(v); // Create an Edge from u to v.

       if (direction == 0){  // If Undirected.
        adj[v].push_back(u); // Create an Edge from v to u.
       }
    }

    void printAdjList(){  // Printing adjacency List.
        for (auto i:adj){
            cout<<i.first<<"->";
            for (auto j: i.second){
                cout<<j<<",";
            }
            cout<<endl;
        }
    }
};
                    
int main(){
    int n;
    cout<<"Enter the number of nodes :";cin>>n;

    int m;
    cout<<"Enter the number of edges :";cin>>m;     

    Graph g;
    cout<<"Enter Edge :"<<endl;
    for (int i = 0; i < m; i++)
    {
        int u,v;
        cout<<"Edge number "<<i+1<<"-"<<endl;
        cout<<"u :";cin>>u;cout<<"v :";cin>>v; // Node value.
        g.addEdge(u,v,0); // Creating a undirected graph.
    }
    // Printng Graph Adjancency List.
    cout<<"Adjacency List :"<<endl;
    g.printAdjList();
    return 0;
}