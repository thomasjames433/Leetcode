class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>graph(n);
        for(auto it:flights)
            graph[it[0]].push_back({it[1],it[2]});
        int mincost=-1;
        queue<pair<int,int>>q;
        q.push({src,0});
        int dist=1;
        vector<int>curmins(n,INT_MAX);
        curmins[src]=0;
        while(dist>0 && k>=0){
            
            auto t=q.front();
            q.pop();
            int cur= t.first;
            int cost= t.second;
            
            for(auto it:graph[cur]){
                if(it.first==dst){
                    if(mincost==-1)
                        mincost=cost+it.second;    
                    else
                        mincost=min(mincost,cost+it.second);
                }
                else if(cost+it.second<curmins[it.first]){
                    curmins[it.first]=cost+it.second;
                    q.push({it.first,cost+it.second});    
                }
            }
            dist--;
            if(dist==0){
                k--;
                dist=q.size();
            }          
        }
        return mincost;
    }
};