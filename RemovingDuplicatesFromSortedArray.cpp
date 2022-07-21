//USING SET DATA STRUCTURE:

#include<bits/stdc++.h>
int removeDuplicates(vector<int> &arr, int n) {
//     int len = 0;
    set<int> s;
    for(int i = 0 ; i < n ; i++)
    {
        s.insert(arr[i]);
    }
    return s.size();
	// Write your code here.
}

//USING 2 POINTERS APPROACH:

int removeDuplicates(vector<int> &arr, int n) {
    //Using 2 POINTERS approach:
    int ans = 0;
    int i = 0 ;
    for(int j = 1 ; j < n ; j++)
    {
        if(arr[i] != arr[j])
        {
            i++;
        }
        arr[i] = arr[j];
    }
    return i+1;
    
	// Write your code here.
}
