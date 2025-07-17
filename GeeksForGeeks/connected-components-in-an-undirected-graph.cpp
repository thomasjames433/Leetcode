
class Solution {
  public:
    vector<vector<int>> getComponents(int v, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>>ret;
        vector<vector<int>>mpp(v);
        for(auto &it:edges){
            mpp[it[0]].push_back(it[1]);
            mpp[it[1]].push_back(it[0]);
        }
        vector<bool>visited(v,0);
        for(int i=0;i<v;i++){
            if(visited[i]==0){
                visited[i]=1;
                queue<int>q;
                vector<int>temp;
                q.push(i);
                
                while(!q.empty()){
                    
                    int x= q.front();
                    temp.push_back(x);
                    q.pop();
                    for(auto &it:mpp[x]){
                        if(!visited[it]){
                            q.push(it);
                            visited[it]=1;
                            
                        }
                    }
                }
                ret.push_back(temp);
            }
        }
        return ret;
    }
};
