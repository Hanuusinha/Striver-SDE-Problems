#include <bits/stdc++.h> 
vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	vector<int> ans;
    int i = 0 , j = 0;
    while(i<m && j<n)
    {
        if(arr1[i]<=arr1[j])
        {
            ans.push_back(arr1[i]);
            i++;
        }else{
            ans.push_back(arr2[j]);
            j++;
        }
    }
    while(i<m)
    {
        ans.push_back(arr1[i]);
        i++;
    }
    while(j<n)
    {
        ans.push_back(arr2[j]);
        j++;
    }
    sort(ans.begin(),ans.end());
    return ans;
}
