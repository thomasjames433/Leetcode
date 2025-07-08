class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int>store(nums.size(),-1);
        int x=getnum(nums,nums.size(),0,store);
        int y=getnum(nums,nums.size(),1,store);
        return max(x,y);
    }
    int getnum(vector<int>&nums, int n, int i,vector<int>&store){
        if(i>n-1)
            return 0;
        if(store[i]!=-1)
            return store[i];
        store[i]=nums[i]+max(getnum(nums,n,i+2,store),getnum(nums,n,i+3,store));
        return store[i];
    }
};