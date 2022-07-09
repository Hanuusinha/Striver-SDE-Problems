#include <bits/stdc++.h> 
long long maxSubarraySum(int arr[], int n)
{
 long long meh = 0, msf = arr[0];
//     int s = 0;
    for(int i = 0 ; i < n ; i++)
    {
        meh += arr[i];
        if(meh>msf)
        {
            msf = meh;
            
        }
        if(meh<0)
        {
            meh = 0;
        }
    }
    if(msf<0)
    {
        msf = 0;
    }
    return msf;
}
