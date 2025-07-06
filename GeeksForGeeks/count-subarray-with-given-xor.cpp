class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        long count=0;

        unordered_map<int,int>mpp;
        mpp[0]=1;
        int xor_sum=0;
        for(int i=0;i<arr.size();i++){
            
            xor_sum^=arr[i];
            int x=xor_sum^k;
            count+=mpp[x];
            mpp[xor_sum]++;
            
        }
        
        return count;
    }
};