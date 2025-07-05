// User function Template for C++

class Solution {
  public:
    vector<int> bellmanFord(int v, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int>dist(v,100000000);
        dist[src]=0;
        
        for(int i=0;i<v-1;i++){
            
            for(auto it:edges){
                int a=it[0];
                int b=it[1];
                int d=it[2];
                
                if(dist[a]==100000000)
                    continue;
                if(dist[a]+d<dist[b])
                    dist[b]=dist[a]+d;
            }
        }
        for(auto it:edges){
            int a=it[0];
            int b=it[1];
            int d=it[2];
            
            if(dist[a]==100000000)
                continue;
            if(dist[a]+d<dist[b])
                return {-1};
        }
        return dist;
    }
};
