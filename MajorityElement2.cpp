#include <bits/stdc++.h> 
vector<int> majorityElementII(vector<int> &arr)
{
    int n = arr.size(); //Calculating the size of the array
    vector<int> ans;    //Creating answer array:
    int idealTimes = (floor)(n/3);
    map<int,int> mp;    //Creating HashMap to keep the count of every element.
    for(auto it : arr)
    {
        mp[it]++;
    }
    for(auto it : mp)
    {
        if(it.second > idealTimes)
        {
            ans.push_back(it.first);
        }
    }
    return ans;
    

}
