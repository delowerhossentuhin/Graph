#include<iostream>
using namespace std;
int main()
{
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    

    int n,m;
    cin>>n>>m;
    int adj[n+1][n+1];
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            adj[i][j]=0;
        }
    }
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u][v]=1;
        adj[v][u]=1; //this line is only for undirected graph
    }
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            cout<<adj[i][j]<<" ";
        }cout<<endl;
    }
}


