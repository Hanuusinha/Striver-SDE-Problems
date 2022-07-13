#include <bits/stdc++.h> 
int calculatePath( int l , int r , int m , int n , vector<vector<int>> &dp)
{
    if(l == m-1 and r == n-1)
    {
        return 1;
    }
    if(l>= m or r >= n )
    {
        return 0;
    }
    if(dp[l][r] != -1)
    {
        return dp[l][r];
    }else{
        return dp[l][r] =    calculatePath(l+1,r,m,n,dp)+calculatePath(l,r+1,m,n,dp);    
    }
    
}
int uniquePaths(int m, int n) {
//     int ans = 0;
    vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
    return calculatePath(0,0,m,n,dp);
    
}
