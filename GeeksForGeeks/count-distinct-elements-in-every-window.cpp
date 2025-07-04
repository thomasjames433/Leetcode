class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        // code here.
        vector<int>ret;
        map<int,int>mpp;
        if(arr.size()<k)
            return {};
        int count=0;
        for(int i=0;i<arr.size();i++){
            auto it=mpp.find(arr[i]);
            if(it==mpp.end()){
                mpp[arr[i]]=1;
                count++;
            }
            else{
                it->second++;
            }
            if(i>=k){
                mpp[arr[i-k]]--;
                if(mpp[arr[i-k]]==0){
                    mpp.erase(arr[i-k]);
                    count--;
                }
            }
            if(i>=k-1)
                ret.push_back(count);
            
        }
        return ret;
    }
};