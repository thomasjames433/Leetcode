class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>>ret;
        for(int i=0;i<n;i++){
            if (nums[i]>0)
                break;
            while(i<n && i>0 &&nums[i]==nums[i-1])
                i++;
            int left=i+1;
            int right=n-1;
            while(left<right){
                int cur=nums[i]+nums[left]+nums[right];
                if(cur==0){
                    ret.push_back({nums[i],nums[left],nums[right]});
                    
                    left++; 
                    while(left<right && nums[left]==nums[left-1])
                        left++;
                    right--;
                    while(left<right && nums[right]==nums[right+1])
                        right--;
                }
                if(cur<0){
                    left++;
                }
                if(cur>0){
                    right--;
                }
            }
        }
        return ret;
    }
};