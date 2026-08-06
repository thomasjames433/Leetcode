class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return 0;
        int farthest=0;
        int jump=0;
        int curr_end=0;
        for(int i=0;i<n;i++){
            farthest=max(farthest,i+nums[i]);
            if(farthest>=n-1)
                return jump+1;
                
            if(i==curr_end){
                jump++;
                curr_end=farthest;
            }
        }
        return jump;
    }
};