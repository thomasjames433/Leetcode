class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<bool> visited(n,0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        int sum=0;

        while(!pq.empty()){

            auto cur=pq.top().second;
            if(visited[cur]){
                pq.pop();
                continue;
            }
            sum+=pq.top().first;
            

            visited[cur]=1;

            for(int i=0;i<n;i++){
                if(visited[i])
                    continue;
                pq.push({abs(points[cur][0]-points[i][0])+abs(points[cur][1]-points[i][1]),i});
            }
        }
        return sum;
        
    }
};