int longestSubSeg(vector<int> &arr , int n, int k){
    int start=0;
    int maxi=0;
    int zero=0;
    for(int end=0;end<n;end++){
        if(arr[end]==0){
            zero++;
        }
         if(zero>k){
             while(zero>k){
                 if(arr[start]==0){
                     zero--;
                 }
                 start++;
             }
         }
        maxi=max(maxi,end-start+1);
    }
    return maxi;
    // Write your code here.
}
