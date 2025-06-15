class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        
        vector<vector<int>>ret;
        vector<int>st;
        dfs(ret,target,0,candidates,st);
        return ret;

    }

private:

    void dfs(vector<vector<int>>&ret,int target, int i,vector<int>&candidates,vector<int>&st){
        if(target<0)
            return;
        if(target==0){
            ret.push_back(st);
            return;
        }

        for(int j=i;j<candidates.size();j++){

            if(j>i && candidates[j]==candidates[j-1])
                continue;
            st.push_back(candidates[j]);
            dfs(ret,target-candidates[j],j+1,candidates,st);
            st.erase(st.end()-1,st.end());
        }
    }
};


class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ret;
        vector<int>sum={0};
        vector<vector<int>>v={{}};
        int k;
        for(int i=0;i<candidates.size();i++){
            int j=0;

            if(i!=0 && candidates[i]==candidates[i-1])
                j=k;
            k=v.size();

            for(int x=j;x<k;x++){
                if(sum[x]+candidates[i]==target){
                    auto newv=v[x];
                    newv.push_back(candidates[i]);
                    ret.push_back(newv);
                }
                else if(sum[x]+candidates[i]<target){
                    sum.push_back(sum[x]+candidates[i]);
                    auto newv=v[x];
                    newv.push_back(candidates[i]);
                    v.push_back(newv);
                }
            }

        }
        return ret;
    }
};