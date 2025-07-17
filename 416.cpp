class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto &it:nums)
            sum+=it;
        if(sum%2)
            return 0;
        sum/=2;
        int n=nums.size();
        vector<vector<bool>>matrix(n+1,vector<bool>(sum+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                if(j<nums[i-1])
                    matrix[i][j]=matrix[i-1][j];
                else if(j==nums[i-1])
                    matrix[i][j]=1;
                else{
                    matrix[i][j]=matrix[i-1][j] || matrix[i-1][j-nums[i-1]];
                }
            }
            if(matrix[i][sum]==1)
                return 1;
        }
        return 0;
    }
};