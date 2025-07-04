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