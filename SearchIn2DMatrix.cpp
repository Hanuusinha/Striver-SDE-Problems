#include <bits/stdc++.h> 
#include <vector>

bool findTargetInMatrix(vector < vector < int >> & mat, int m, int n, int target) {
    //Using binary search:
    int low = 0 , right = m*n-1;
    while(low<=right)
    {
        int mid = (low + (right-low)/2);
        if(mat[mid/n][mid%n] == target)
        {
            return true;
        }else if(mat[mid/n][mid%n] > target)
        {
            right = mid-1;
        }else{
            low = mid+1;
        }
    }
    return false;
}
