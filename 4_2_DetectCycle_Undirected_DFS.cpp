#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
bool detectCycle(int source, vector<int> adj[], vector<int>& visited)
{
    visited[source]=1;
    stack<pair<int,int>>s;
    s.push({source,-1});
    while(!s.empty())
    {
        int node=s.top().first;
        int parent=s.top().second;
        s.pop();
        for(int it:adj[node])
        {
            if(!visited[it])
            {
                visited[it]=1;
                s.push({it,node});
            }
            else if(it!=parent)
            {
                return true;
            }
        }
    }
    return false;
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
    vector<int> visited(n + 1, 0);
    bool hasCycle = false;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            if (detectCycle(i, adj, visited)) {
                hasCycle = true;
                break;
            }
        }
    }
    if (hasCycle)
        cout << "Cycle detected" << endl;
    else
        cout << "No cycle" << endl;

    return 0;

}
