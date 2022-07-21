#include <bits/stdc++.h> 
long getTrappedWater(long *arr, int n){
    long int ans = 0;
    long int leftArray[n] = {0};
    leftArray[0] = arr[0];
    long int rightArray[n] = {0};
    rightArray[n-1] = arr[n-1];
    for(int i = 1 ; i < n ; i++)
    {
        leftArray[i] = max(arr[i],leftArray[i-1]);
    }
    for(int j = n - 2 ; j >= 0 ; j--)
    {
        rightArray[j] = max(arr[j] , rightArray[j+1]);
    }
    for(int i = 1 ; i < n-1 ; i++)
    {
        ans += min(leftArray[i],rightArray[i])-arr[i];
    }
    return ans;
    // Write your code here.
}
//WITHOUT USING EXTRA SPACE METHOD:

#include <bits/stdc++.h> 
long getTrappedWater(long *arr, int n){
    long ans = 0;
    long leftMax = 0 , rightMax = 0;
    long l = 0 , r = n-1;
    while(l<=r)
    {
        if(arr[l] <= arr[r])
        {
            if(arr[l] > leftMax)
            {
                leftMax = arr[l];
                
            }else{
                ans += leftMax-arr[l];
            }
            l++;
        }else{
            if(arr[r] > rightMax)
            {
                rightMax = arr[r];
            }else{
                ans += rightMax - arr[r];
            }
            r--;
        }
    }
    return ans;
    // Write your code here.
}
