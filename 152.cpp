class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int totmax=nums[0];
        int maxwin=nums[0];
        int minwin=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]<0)
                swap(maxwin,minwin);
            maxwin=max({nums[i],maxwin*nums[i]});
            minwin=min({nums[i],minwin*nums[i]});
            totmax=max({totmax,maxwin});
        }
        return totmax;

    }
};