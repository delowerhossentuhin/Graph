#include<iostream>
#include<vector>
#include<stack>
using namespace std;
void topologicalSort(int start,vector<int>adj[],vector<int>&visited,stack<int>&st)
{
    visited[start]=1;
    for(int it:adj[start])
    {
        if(!visited[it])
        {
            topologicalSort(it,adj,visited,st);
        }
    }
    st.push(start);
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
    stack<int>st;
    for(int i=0;i<edges;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    for(int i=0;i<nodes;i++)
    {
        if(!visited[i])
        {
            topologicalSort(i,adj,visited,st);
        }
    }
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }

    

}
