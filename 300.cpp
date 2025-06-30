class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int maxlen=1;
        vector<int>arr(nums.size(),1);

        for(int i=1;i<nums.size();i++){
            for (int j=i-1;j>=0;j--){
                if(nums[i]>nums[j])
                    arr[i]=max(arr[i],arr[j]+1);
            }
        }
        for(auto it:arr)
            maxlen=max(it,maxlen);
        return maxlen;
    }
};