#include<iostream>
#include<vector>
using namespace std;
bool isCycle(int node,vector<int>adj[],vector<int>&visited,vector<int>&pathvisited)
{
    visited[node]=1;
    pathvisited[node]=1;

    for(auto it:adj[node])
    {
        if(!visited[it])
        {
            if(isCycle(it,adj,visited,pathvisited))return true;
        }
        else if(pathvisited[it])
        {
            return true;
        }
    }
    
    pathvisited[node]=0;
    return false;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int nodes,edges;
    cin>>nodes>>edges;

    vector<int>adj[nodes+1];
    vector<int>visited(nodes+1,0);
    vector<int>pathVisited(nodes+1,0);

    for(int i=0;i<edges;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    int hasCycle=false;
    for(int i=0;i<nodes;i++)
    {
        if(!visited[i] && isCycle(i,adj,visited,pathVisited))
        {
            hasCycle=true;
            break;
        }
    }
    if(hasCycle)cout<<"Cycle Detected";
    else cout<<"Cycle is not Detected";

}