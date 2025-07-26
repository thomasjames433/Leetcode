class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        // Code here
        int totmax=arr[0];
        int cursum=arr[0];
        
        for(int i=1;i<arr.size();i++){
            cursum=max(arr[i],cursum+arr[i]);
            totmax=max(totmax,cursum);
        }
        return totmax;
        
    }
};