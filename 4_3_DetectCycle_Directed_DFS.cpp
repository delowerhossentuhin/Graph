#include<iostream>
#include<vector>
#include<stack>
using namespace std;
bool detectCycle(int start, vector<int>adj[],vector<int>&visited,vector<int>&pathVisited)
{
    visited[start]=1;
    pathVisited[start]=1;
    stack<int>s;
    s.push(start);
    
    while(!s.empty())
    {
        bool child=false;
        int node=s.top();
        for(auto it:adj[node])
        {
            if(!visited[it])
            {
                visited[it]=1;
                pathVisited[it]=1;
                s.push(it);
                child=true;
                break;
            }
            else if(pathVisited[it])return true;
        }
        if(!child)
        {
            s.pop();
            pathVisited[node]=0;
        }
    }
    return false;
    
}
int main()
{
    /*
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    */

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
        //adj[v].push_back(u);
    }
    bool hasCycle=false;
    for(int i=0;i<=nodes;i++)
    {
        if(!visited[i] && detectCycle(i,adj,visited,pathVisited))
        {
            hasCycle=true;
            break;
        }
    }
    if(hasCycle)cout<<"Cycle Detected";
    else cout<<"Cycle is not detected";
}

