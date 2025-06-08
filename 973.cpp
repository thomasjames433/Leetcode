class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& nums, int k) {
        
        priority_queue<pair<int,vector<int>>> pq;

        for(auto it:nums){
            int x= it[0]*it[0] + it[1]*it[1];
            pq.push({x,it});
            if(pq.size()>k)
                pq.pop(); 
            
        }
        vector<vector<int>>ret;
        while(!pq.empty()){
            ret.push_back(pq.top().second);
            pq.pop();
        }
        return ret;
    }
};