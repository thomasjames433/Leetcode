class Solution {
public:

    void getSum(vector<vector<int>>&ret, vector<int>&curvector,vector<int>&candidates,int target, int i){
        
        if(i>=candidates.size() || target<0)
            return ;
        target-=candidates[i];
        
        curvector.push_back(candidates[i]);
        if(target==0){
            ret.push_back(curvector);
            curvector.pop_back();
            return;
        }
        getSum(ret,curvector,candidates,target,i);
        curvector.pop_back();
        getSum(ret,curvector,candidates,target+candidates[i],i+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        int n=candidates.size();
        vector<vector<int>>ret={};
        vector<int>curvector={};
        getSum(ret,curvector,candidates,target,0);
        return ret;
    }
};