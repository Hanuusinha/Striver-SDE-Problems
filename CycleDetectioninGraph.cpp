#include<bits/stdc++.h>
bool isCyclePresentBFS(int src , unordered_map<int,bool> &visited , unordered_map<int,list<int>> &adjList)
{
    unordered_map<int,int> parent;
    parent[src] = -1;
    visited[src] = 1;
    queue<int> q;
    q.push(src);
    while(!q.empty())
    {
        int front = q.front();
        q.pop();
        for(auto neighbour : adjList[front])
        {
            if(visited[neighbour] == true and neighbour != parent[front])
            {
                return true;
            }else if(!visited[neighbour])
            {
                q.push(neighbour);
                visited[neighbour] = 1;
                parent[neighbour] = front;
            }
        }
    }
    return false;
    
}
bool isCyclePresentDFS(int node,int parent,unordered_map<int,bool> &visited, unordered_map<int,list<int>> &adjList)
{
    visited[node] = 1;
    for(auto neighbour : adjList[node])
    {
        if(!visited[neighbour])
        {
            bool cycleDetected = isCyclePresentDFS(neighbour,node,visited,adjList);
            if(cycleDetected)
            {
                return true;
            }
        }else if(neighbour != parent)
            {
                return true;
            }
    }
    return false;
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    //Create adjList:
    unordered_map<int,list<int>> adjList;
    for(int i = 0 ; i < m ; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adjList[u].push_back(v);
        adjList[v].push_back(u);
        
    }
    unordered_map<int,bool> visited;
    for(int i = 0 ; i < n ; i++)
    {
        if(!visited[i])
        {
            //bool ans = isCyclePresentBFS(i,visited,adjList);
            bool ans = isCyclePresentDFS(i,-1,visited,adjList);
            if(ans == 1)
            {
                return "Yes";
            }
        }
    }
    return "No";
}

