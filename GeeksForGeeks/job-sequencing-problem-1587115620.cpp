class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // code here
        multimap<int,int,greater<int>>mpp;
        int maxdead=0;
        for(int i=0;i<deadline.size();i++){
            mpp.insert({profit[i],deadline[i]});
            maxdead=max(maxdead,deadline[i]);
        }
        int sum=0;
        int job=0;
        set<int>s;
        for (int i=1;i<=maxdead;i++)
            s.insert(i);
            
        for(auto it:mpp){
            int p=it.first;
            int dead=it.second;
            
            auto lb=s.upper_bound(dead);
            if(lb!=s.begin())
                --lb;
            if(lb!=s.end() && *lb<=dead){
                s.erase(*lb);
                job++;
                sum+=p;
            }
            
        }
        return{job,sum};
        
    }
};