#include <bits/stdc++.h> 
int findMajorityElement(int arr[], int n) {
    map<int,int> mp;
    for(int i = 0 ; i < n ; i++)
    {
        mp[arr[i]] += 1;
    }
    int ans = -1;
    for(auto it : mp)
    {
        if(it.second > (floor)(n/2))
        {
            ans = it.first;
        }
    }
    return ans;
}
