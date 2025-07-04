class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto it:nums){
            pq.push(it);
            if(pq.size()>k)
                pq.pop();
        }
        return pq.top();
    }
};

int findKthLargest(int* num, int numsize, int k) {
    int A[20002];
    for(int i=0;i<20002;i++)
        A[i]=0;
    
    for(int i=0;i<numsize;i++)
        A[num[i]+10000]++;;
    
    int i=0;
    for(i=20001;i>=0;i--){
        if(A[i]!=0)
            k-=A[i];
        if(k<=0)
            break;
    }
    return i-10000;
}