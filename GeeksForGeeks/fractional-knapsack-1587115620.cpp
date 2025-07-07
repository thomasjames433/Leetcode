// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        map<double,int,greater<double>>mpp;
        for( int i=0;i<val.size();i++){
            double x=(double)val[i]/(double)wt[i];
            mpp[x]+=wt[i];
        }
        double ret=0;
        for(auto it:mpp){

            if(capacity<0)
                return ret;
            
            ret+=(it.first * it.second) *min(capacity,it.second)/it.second ;

            capacity-=it.second;
        }
        return ret;
        
    }
};
