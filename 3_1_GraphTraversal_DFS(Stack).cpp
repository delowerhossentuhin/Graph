#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector<int>dfsOfGraph(int nodes,int start, vector<int>adj[])
{
    vector<int>visited(nodes,false);
    visited[start]=true;
    stack<int>s;
    s.push(start);
    vector<int>dfs;
    while(!s.empty())
    {
        int node=s.top();
        s.pop();
        dfs.push_back(node);
        for(int it:adj[node])
        {
            if(!visited[it])
            {
                visited[it]=1;
                s.push(it);
            }
        }
    }
    return dfs;
     
}
int main()
{
    ////////File I/O Setup////////
     
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    
    //////////////////////////////
    int n,m;
    cin>>n>>m;
    vector<int>adj[n+1];
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        //adj[v].push_back(u); //for directed graph
    }
    vector<int>list=dfsOfGraph(6,0,adj);
    for(int it:list)cout<<it<<" ";

}
