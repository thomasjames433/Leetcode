BFS Khans

class Solution {
  public:
    vector<int> topoSort(int v, vector<vector<int>>& edges) {
        // code here
        queue<int> q;
        vector<int>ret;
        vector<int>in(v);
        vector<vector<int>>after(v);
        for(auto it:edges){
            in[it[1]]++;
            after[it[0]].push_back(it[1]);
        }
        for(int i=0;i<v;i++){
            if(in[i]==0){
                q.push(i);
            }
            
        }
        while(!q.empty()){
            int x=q.front();
            q.pop();
            ret.push_back(x);
            
            for(auto it:after[x]){
                in[it]--;
                if(in[it]==0)
                    q.push(it);
            }
            
        }
        return ret;
        
    }
};

DFS

class Solution {
  public:
    vector<int> topoSort(int v, vector<vector<int>>& edges) {
        // code here
        vector<int>in(v,0);
        vector<int>ret;
        vector<vector<int>>aft(v);
        for(auto it:edges){
            aft[it[0]].push_back(it[1]);
            in[it[1]]++;
        }
        
        for(int i=0;i<v;i++){
            if(in[i]==0)
                dfs(in,aft,i,ret);
        }
        return ret;
    }
    void dfs(vector<int>&in,vector<vector<int>>&aft,int i,vector<int>&ret){
        in[i]=-1;
        ret.push_back(i);
        for(auto it:aft[i]){
            in[it]--;
            if(in[it]==0)
                dfs(in,aft,it,ret);
        }
    }
};