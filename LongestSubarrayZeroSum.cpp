#include <bits/stdc++.h> 
int LongestSubsetWithZeroSum(vector < int > arr) {
    int maxLength = 0,S = 0;
    unordered_map<int,int>mp;
    for(int i = 0 ; i < arr.size() ; i++)
    {
        S += arr[i];
        if(S == 0)
        {
            maxLength =i+1;
        }else{
            if(mp.find(S) != mp.end())
            {
                maxLength = max(maxLength,i-mp[S]);
            }else{
                mp[S] = i;
            }
        }
    }
    return maxLength;
  // Write your code here

}
