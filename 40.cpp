class Solution {
public:
    void getSum(vector<vector<int>>&ret, vector<int>&candidates,vector<int>&curvector,int target,int i){
        if(i>=candidates.size() || target<0)
            return;
        target-=candidates[i];
        cout<<candidates[i]<<" "<<target<< "\n";
        curvector.push_back(candidates[i]);
        if(target==0){
            ret.push_back(curvector);
            curvector.pop_back();
            return;
        }
        getSum(ret,candidates,curvector,target,i+1);
        curvector.pop_back();
        while(i<candidates.size()-1 &&candidates[i]==candidates[i+1])
            i++;
        getSum(ret,candidates,curvector,target+candidates[i],i+1);
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ret={};
        vector<int>curvector={};
        getSum(ret,candidates,curvector,target,0);
        return ret;
    }
};