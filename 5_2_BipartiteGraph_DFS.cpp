#include<iostream>
#include<vector>
#include<stack>
#include<typeinfo>
using namespace std;
bool isColor(int node,vector<int>adj[],vector<int>&visited)
{
    visited[node]=1;
    stack<int>s;
    s.push(node);
    while(!s.empty())
    {
        int parent=s.top();
        s.pop();
        for(auto it: adj[parent])
        {
            if(visited[it]==-1)
            {
                visited[it]=!visited[parent];
                s.push(it);
            }
            else if(visited[it]==visited[parent])return false;
        }
    }
    return true;
}
bool isBipartite(int nodes,vector<int>adj[],vector<int>&visited)
{
    for(int i=0;i<nodes;i++)
    {
        if(visited[i]==-1 && !isColor(i,adj,visited))return false;
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

    int nodes, edges;
    cin>>nodes>>edges;
    vector<int>adj[nodes+1];
    vector<int>visited(nodes+1,-1);
    for(int i=0;i<edges;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        //for undirected graph
        adj[v].push_back(u);
    }
    if(isBipartite(nodes,adj,visited))cout<<"Graph is Bipartite";
    else cout<<"Graph is not Bipartite";
    auto x="ty";
    cout<<endl<<endl<<typeid(x).name();

}
