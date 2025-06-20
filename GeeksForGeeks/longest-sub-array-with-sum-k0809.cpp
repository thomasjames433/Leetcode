class Solution {
  public:
    int longestSubarray(vector<int>& arr, int target) {
        // code here
        map<int,int>mpp;
        arr.insert(arr.begin(),0);
        int n=arr.size();
        for(int i=1;i<n;i++)
            arr[i]+=arr[i-1];
            
            
        for(int i=0;i<n;i++){
            auto it=mpp.find(arr[i]);
            if(it==mpp.end())
                mpp.insert({arr[i],i});
        }
        
        int maxlen=0;
        for(int i=0;i<n;i++){
            auto it=mpp.find(arr[i]-target);
            if(it !=mpp.end() && it->second<i){
                maxlen=max(maxlen,i-it->second);
            }
        }z
        return maxlen;
        
        
        
    }
};
