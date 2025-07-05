class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>>pq;
        vector<int>ret;
        for(int i=0;i<nums.size();i++){
            pq.push({nums[i],i});

            if(pq.size()>=k){
                auto it =pq.top();
                while(it.second<=i-k){
                    pq.pop();
                    it=pq.top();
                }
                ret.push_back(it.first);
            }
        }
        return ret;
    }
};