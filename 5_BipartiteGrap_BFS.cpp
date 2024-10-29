#include<iostream>
#include<vector>
#include<queue>
using namespace std;
bool isColor(int start,vector<int>adj[],vector<int>&visited)
{
    visited[start]=1;//initialize as color 1
    queue<int>q;
    q.push(start);
    while (!q.empty())
    {
        int parent=q.front();
        q.pop();
        for(auto it:adj[parent])
        {
            if(visited[it]==-1)
            {
                visited[it]=!visited[parent];
                q.push(it);
            }
            else if(visited[it]==visited[parent])return false;
        }
    }
    return true;
    
}
//for disconnected component
bool isBipartiteGraph(int node,vector<int>adj[],vector<int>&visited)
{
    for(int i=0;i<=node;i++)
    {
        if(visited[i]==-1)
        {
            if(!isColor(i,adj,visited))return false;
        }
    }
    return true;
}
int main()
{
    /*
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    */
    int node,edge;
    cin>>node>>edge;
    vector<int>adj[node+1];
    vector<int>visited(node+1,-1);
    for(int i=0;i<edge;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        //if Undirected Graph
        adj[v].push_back(u);
    }
    if(!isBipartiteGraph(node,adj,visited))
        {
            cout<<"Graph is not Bipartite";
        }
    else cout<<"Graph is Bipartite";

}
