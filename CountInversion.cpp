#include <bits/stdc++.h> 
long long int inversion = 0;
void merge(long long arr[] , long long left , long long mid , long long right)
{
    long long n1 = mid-left+1;
    long long n2 = right-mid;
    long long l[n1],r[n2];
    for(auto i = 0 ; i < n1 ; i++)
    {
        l[i] = arr[left+i];
    }
    for(auto i = 0 ; i < n2 ; i++)
    {
        r[i] = arr[mid+i+1];
    }
    int i = 0 , j = 0 , k = left;
    while(i < n1 && j < n2)
    {
        if(l[i]<=r[j])
        {
            arr[k++] = l[i++];
        }else{
            arr[k++] = r[j++];
            inversion += (n1-i);
        }
    }
    while(i < n1)
    {
        arr[k++] = l[i++];
    }
    while(j<n2)
    {
        arr[k++] = r[j++];
    }
}
void mergeSort(long long arr[] , long long left, long long right)
{
    if(left>=right)
    {
        return;
    }
    long long mid = (left+right)/2;
    mergeSort(arr , left , mid);
    mergeSort(arr, mid+1 , right);
    merge(arr,left,mid,right);
}
long long getInversions(long long *arr, int n){
     mergeSort(arr,0,n-1);
    return inversion;
}
