class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        for (auto it :nums){
            pq.push(it);
            if(pq.size()>k)
                pq.pop();
        }
    }
    
    int add(int val) {

        pq.push(val);
        if(pq.size()<k)
            return INT_MIN;
        if(pq.size()>k)
            pq.pop();
        return pq.top();
    }
private:
    int k;
    priority_queue<int,vector<int>,greater<int>>pq;

};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */