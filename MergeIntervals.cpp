#include <bits/stdc++.h> 
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    vector<vector<int>> ans;
    sort(intervals.begin(),intervals.end());
       // Take a 1-D array:
    vector<int> temp = intervals[0];
    for(auto it : intervals)
    {
        if(it[0] <= temp[1])
        {
            temp[1] = max(it[1],temp[1]);
        }else{
            ans.push_back(temp);
            temp = it;
        }
    }
    ans.push_back(temp);
    return ans;
}
