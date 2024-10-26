#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int>bfsOfGraph(int v,int st, vector<int>adj[])
{
    int visited[v]={0};
    visited[st]=1;
    queue<int>q;
    q.push(st);
    vector<int>bfs;
    while (!q.empty())
    {
        int node=q.front();
        q.pop();
        bfs.push_back(node);
        for(int it:adj[node])
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
    ////////File I/O Setup////////
     /*
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    */
    ///////////////////////////////
    int n,m;
    //n is number of nodes and m is number of Edges
    cin>>n>>m;
    vector<int>adj[n+1];

    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    vector<int>bfs=bfsOfGraph(6,0,adj);
    for(int it:bfs)cout<<it<<" ";

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
*/
