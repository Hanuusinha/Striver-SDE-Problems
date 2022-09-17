#include<unordered_map>
void dfs(int node ,vector<int> &component, unordered_map<int,list<int>> &adjList,unordered_map<int,bool> &isVisited)
{
    component.push_back(node);
    isVisited[node] = true;
    for(auto it : adjList[node])
    {
        if(!isVisited[it])
        {
            dfs(it,component,adjList,isVisited);
        }
    }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    vector<vector<int>> ans;
    vector<int> temp;
    //Creating adjList:
    unordered_map<int,list<int>> adjList;
    for(int i = 0 ; i < E ; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    unordered_map<int,bool> isVisited;
    for(int i = 0 ; i < V ; i++)
    {
        
        if(!isVisited[i])
        {
            vector<int> component;
            dfs(i,component,adjList,isVisited);
            ans.push_back(component);
        }
    }
    return ans;
    
}
