#include<bits/stdc++.h>
bool cycleFoundDFS(int node , unordered_map<int,bool> &isVisited, unordered_map<int,bool> &isVisitedDFS,unordered_map<int,list<int>> &adjList)
{
    isVisited[node] = true;
    isVisitedDFS[node] = true;
    for(auto neighbour : adjList[node])
    {
        if(!isVisited[neighbour])
        {
            bool ans = cycleFoundDFS(neighbour,isVisited,isVisitedDFS,adjList);
            if(ans)
            {
                return true;
            }
        }else if(isVisitedDFS[neighbour])
        {
            return true;
        }
    }
    isVisitedDFS[node] = false;
    return false;
}
bool isCyclic(vector<vector<int>>& edges, int v, int e)
{
	//Create adjList:
    unordered_map<int,list<int>> adjList;
    for(int i = 0 ; i < edges.size() ; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adjList[u].push_back(v);
    }
    //2 UnorderedList:
    unordered_map<int,bool> isVisited;
    unordered_map<int,bool> isVisitedDFS;
    for(int i = 0 ; i < v ; i++)
    {
        if(!isVisited[i])
        {
            bool cycleFound = cycleFoundDFS(i,isVisited,isVisitedDFS,adjList);
            if(cycleFound)
            {
                return true;
            }
        }
    }
    return false;
}
