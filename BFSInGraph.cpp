#include<bits/stdc++.h>
void prepareAdjList(unordered_map<int,set<int>> &adjList, vector<pair<int, int>> &edges)
{
    int n = edges.size();
    for(int i = 0 ; i < n ; i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}
void bfs(unordered_map<int,set<int>> &adjList, unordered_map<int,bool> &isVisited,vector<int> &ans , int node)
{
    queue<int> q;
    q.push(node);
    isVisited[node] = true;
    while(!q.empty())
    {
        int frontNode = q.front();
        q.pop();
        ans.push_back(frontNode);
        for(auto i : adjList[frontNode])
        {
            if(!isVisited[i])
            {
                isVisited[i] = true;
                q.push(i);
            }
        }
    }
}
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    //Creating adjacency list:
    unordered_map<int,set<int>> adjList;
    vector<int> ans;
    unordered_map<int,bool> isVisited;
    prepareAdjList(adjList,edges);
    for(int i = 0 ; i < vertex ; i++)
    {
        if(!isVisited[i])
        {
            bfs(adjList,isVisited,ans,i);
        }
    }
    return ans;
    
    
    
}
