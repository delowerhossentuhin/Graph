#include<iostream>
using namespace std;
int main()
{
    /*
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    */

    int n=5,m=6;
    int adj[6][6];
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<6;j++)
        {
            adj[i][j]=0;
        }
    }
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u][v]=1;
        adj[v][u]=1;
    }
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<6;j++)
        {
            cout<<adj[i][j]<<" ";
        }cout<<endl;
    }
}
