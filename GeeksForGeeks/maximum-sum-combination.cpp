class Solution {
  public:
    vector<int> maxCombinations(int n, int k, vector<int> &a, vector<int> &b) {
        // code here
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        
        vector<int>n1(a.end()-k,a.end());
        vector<int>n2(b.end()-k,b.end());
        
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=k-1;i>-1;i--){
            for(int j=k-1;j>-1;j--){
                if(pq.size()<k || pq.top()<n1[i]+n2[j]){
                    pq.push(n1[i]+n2[j]);
                    if(pq.size()>k)
                        pq.pop();
                }
                else
                    break;
            }
        }
        vector<int>ret(k,0);
        for(int i=k-1;i>=0;i--){
            ret[i]=pq.top();
            pq.pop();
        }
        return ret;
    }
};