class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>time(n+1,INT_MAX);
        vector<vector<pair<int,int>>>next(n+1);
        for(auto t:times){
            next[t[0]].push_back({t[1],t[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});
        while(!pq.empty()){
            auto cur=pq.top();
            int node=cur.second;
            pq.pop();
            if(time[node]<cur.first)
                continue;
            time[node]=cur.first;
            for(auto it:next[node]){
                if(time[node]+it.second<time[it.first]){
                    time[it.first]=time[node]+it.second;
                    pq.push({time[it.first],it.first});
                }
            }
        }
        int max_time=0;
        for(int i=1;i<n+1;i++)
            max_time=max(max_time,time[i]);
        if(max_time==INT_MAX)
            return -1;
        return max_time;
    }
};