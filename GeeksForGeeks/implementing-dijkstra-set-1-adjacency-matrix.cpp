// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int v, vector<vector<int>> &edges, int src) {
        // Code here
        unordered_map<int,vector<pair<int,int>>>mpp;

        for(auto it:edges){
            mpp[it[0]].push_back({it[1],it[2]});
            mpp[it[1]].push_back({it[0],it[2]});
            
        }
        
        vector<int>dist(v,INT_MAX);
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        dist[src]=0;
        pq.push({0,src});
        while(!pq.empty()){
            auto mpx=pq.top();
            auto mindist=mpx.first;
            auto vertex=mpx.second;
            pq.pop();
            
            if(mindist>dist[vertex])
                continue;
            auto mp=mpp[vertex];
            for(auto it:mp){
                if(dist[it.first]>dist[vertex]+it.second){
                    dist[it.first]=dist[vertex]+it.second;
                    pq.push({dist[it.first],it.first});
                }
            }
        }
        return dist;
    }
};