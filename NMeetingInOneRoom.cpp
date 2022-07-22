#include<bits/stdc++.h>
struct Meeting{
    int s;
    int e;
    int pos;
};
bool comparator(struct Meeting m1,struct Meeting m2)
{
    if(m1.e<m2.e)
    {
        return true;
    }else if(m1.e>m2.e)
    {
        return false;
    }else if(m1.pos<m2.pos)
    {
        return true;
    }else{
        return false;
    }
}
vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    int n = start.size();
    struct Meeting meet[n];
    //Inputting all the input information into data-structure:
    for(int i = 0 ; i < n ; i++)
    {
        meet[i].s = start[i],meet[i].e = end[i],meet[i].pos = i+1;
    }
    //Now sorting the structure according to the ending time:
    sort(meet,meet+n,comparator);
    int limit = meet[0].e;
    //We are going to attend the meeting anyway:
    vector<int> ans;
    ans.push_back(meet[0].pos);
    //Now comparing all the values from 1 to N:
    for(int i = 1 ; i < n ; i++)
    {
        if(limit<meet[i].s)
        {
            limit = meet[i].e;
            ans.push_back(meet[i].pos);
            
        }
    }
    return ans;
    // Write your code here.
}
