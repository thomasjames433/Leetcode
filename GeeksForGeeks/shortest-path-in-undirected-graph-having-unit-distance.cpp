class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // code here
        int n=adj.size();
        vector<int>ret(n,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> >pq;
        pq.push({0,src});
        ret[src]=0;
        while(!pq.empty()){
            auto &x=pq.top();
            int dist=x.first;
            int cur=x.second;
            pq.pop();
            
            if(ret[cur]<dist)
                continue;
            
            // cout<<src<<" ";
            for(auto &it:adj[cur]){
                if(ret[it]>1+dist){
                    // cout<<it<<" ";
                    pq.push({1+dist,it});
                    ret[it]=1+dist;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(ret[i]==INT_MAX)
                ret[i]=-1;
        }
        // cout<<"\n";
        return ret;
        
    }
};
