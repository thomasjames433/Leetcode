class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ret;
        vector<int> st;
        dfs(ret,0,candidates,target,st);
        return ret;
    }

private:
    void dfs(vector<vector<int>> &ret, int i,vector<int> &candidates, int target,vector<int> &st){

        if(target==0){
            ret.push_back(st);
            return;
        }
        if(target<0){
            return;
        }
        for (int j=i;j<candidates.size();j++){
                st.push_back(candidates[j]);
                dfs(ret,j,candidates,target-candidates[j],st);
                st.erase(st.end()-1,st.end());    
            }
        return;

    }
};

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<vector<int>>ret;
        vector<int>sum={0};
        vector<vector<int>>v={{}};

        for(auto it : candidates){
            int i=0;
            int j=v.size();
            cout <<j <<' ';
            for(int m=1;m<=target/it;m++){
                while(i<j){
                    auto newv=v[i];
                    newv.push_back(it);
                    if(sum[i]+it==target){
                        ret.push_back(newv);
                    }
                    else if(sum[i]+it<target){
                        sum.push_back(sum[i]+it);
                        v.push_back(newv);
                    }
                    i++;
                }
                j=v.size();
            }

        }
        return ret;
        
    }
};