class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int v, vector<vector<int>> adj[]) {
        // code here
        vector<int>vis(v,0);
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>> >pq;
        for(auto it:adj[0]){
            pq.push({it[1],{0,it[0]}});
        }
        vis[0]=1;
        int span=0;
        int edge=0;
        while(edge!=v-1){
            
            auto x=pq.top();
            pq.pop();
            
            int right=x.second.second;
            
            if(!vis[right]){
                vis[right]=1;
                span+=x.first;
                edge++;
                for(auto it:adj[right]){
                    pq.push({it[1],{right,it[0]}});
                }       
            }
        }
        return span;
    }
};