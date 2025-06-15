class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>check(21,0);
        vector<vector<int>>ret;
        vector<int>st;
        int n=nums.size();
        dfs(ret,check,nums,st,n,n);
        return ret;
    }

    void dfs(vector<vector<int>>&ret,vector<int>&check,vector<int>&nums,vector<int>&st,int count,int n){
        if(count==0){
            ret.push_back(st);
            return;
        }
        for(int i=0;i<n;i++){
            
            if(!check[nums[i]+10]){
                check[nums[i]+10]=1;
                st.push_back(nums[i]);
                dfs(ret,check,nums,st,count-1,n);
                check[nums[i]+10]=0;
                st.erase(st.end()-1,st.end());
            }
        }
    }
};