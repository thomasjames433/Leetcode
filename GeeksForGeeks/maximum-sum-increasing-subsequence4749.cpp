class Solution {
  public:
    int maxSumIS(vector<int>& arr) {
        // Your code goes here
        int n=arr.size();
        vector<int>sums(n,0);
        sums[0]=arr[0];
        for(int i=1;i<n;i++){
            sums[i]=arr[i];
            for(int j=i-1;j>=0;j--){
                if(arr[i]>arr[j]){
                    sums[i]=max(sums[i],arr[i]+sums[j]);
                }
            }
        }
        int maxno=sums[0];
        for(auto it:sums)
            maxno=max(maxno,it);
        return maxno;
    }
};