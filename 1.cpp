class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mpp;
        for (int i=0;i<nums.size();i++){
            if (mpp.find(nums[i]) !=mpp.end())
                return {mpp[nums[i]],i};
            mpp[target- nums[i]]=i;
        }
        return{};
    }
};