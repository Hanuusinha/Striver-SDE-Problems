#include<bits/stdc++.h>
struct Job{
    int deadline;
    int profit;
};
bool comparator(struct Job j1 , struct Job j2)
{
    return (j1.profit>j2.profit);
}
int jobScheduling(vector<vector<int>> &jobs)
{
    int n = jobs.size();
    struct Job job[n];
    for(int i = 0 ; i < n ; i++)
    {
        job[i].deadline = jobs[i][0];
        job[i].profit = jobs[i][1];
    }
    sort(job,job+n,comparator);
    //Calculating the maximum deadline:
    int maxDeadline = 0;
    for(int i = 0 ; i < n ; i++)
    {
        maxDeadline = max(maxDeadline,job[i].deadline);
    }
    //Creating an array of maximum deadline:
    vector<int> filled(maxDeadline+1,-1);
    int maxProfit = 0;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = job[i].deadline ; j > 0 ; j--)
        {
            if(filled[j] == -1)
            {
                filled[j] = 0;
                maxProfit += job[i].profit;
                break;
            }
        }
    }
    return maxProfit;
    // Write your code here
}
