#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main()
{
     /*
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    */
    int n,m;
    cin>>n>>m;
    vector<int>adj[n+1];

    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        //for undirected Graph
        //adj[v].push_back(u);
    }

}

/* input 
9 9
1 2
2 3
2 4
1 6
4 5
5 8
7 8
6 7
6 9



////////////
code
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int>bfsOfGraph(int v,vector<int>adj[])
{
    int visited[v]={0};
    visited[1]=1;
    queue<int>q;
    q.push(1);
    vector<int>bfs;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        bfs.push_back(node);
        for(auto it: adj[node])
        {
            if(!visited[it])
            {
                visited[it]=1;
                q.push(it);
            }
        }
    }
    return bfs;

}
int main()
{
    ////////sublime text////////
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ////////////////////////////
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
    vector<int>bfs=bfsOfGraph(n,adj);
    for(int it:bfs)cout<<it<<" ";

}
*/
