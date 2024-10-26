#include<iostream>
#include<vector>
using namespace std;
void dfs(int node,vector<int>adj[],int visited[],vector<int>&out)
{
    visited[node]=1;
    out.push_back(node);
    for(int it:adj[node])
    {
        if(!visited[it])
        {
            dfs(it,adj,visited,out);
        }
    }
}
vector<int>dfsOfGraph(int nodes,int start,vector<int>adj[])
{
    int visited[nodes+1]={0};
    vector<int>outputList;
    dfs(start,adj,visited,outputList);
    return outputList;
}
int main()
{
    ////////File I/O Setup////////
     /*
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    */
    //////////////////////////////
    int n,m;
    cin>>n>>m;
    vector<int>adj[n+1];
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>list=dfsOfGraph(8,1,adj);
    for(int it:list)cout<<it<<" ";

}
