#include<bits/stdc++.h>
bool cmp(pair<int,int> &p , pair<int,int> &q)
{
    return p.second<q.second;
}
int maximumActivities(vector<int> &start, vector<int> &finish) {
    vector<pair<int,int>> mp;
    int n = start.size();
    for(int i = 0 ; i < n ; i++)
    {
        mp.push_back({start[i], finish[i]});
    }
    sort(mp.begin(),mp.end(),cmp);
    int count = 1;
    int endTime = mp[0].second;
    for(int i = 1 ; i < n ; i++)
    {
        if(mp[i].first >= endTime)
        {
            count++;
            endTime = mp[i].second;
        }
    }
    return count;
}
