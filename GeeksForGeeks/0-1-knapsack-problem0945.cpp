class Solution {
  public:
    int knapsack(int w, vector<int> &val, vector<int> &wt) {
        // code here
        int n=val.size();
        vector<vector<int>>v(n+1,vector<int>(w+1,0));
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<w+1;j++){
                    if(j<wt[i-1])
                        v[i][j]=v[i-1][j];
                    else
                        v[i][j]=max(v[i-1][j],val[i-1]+v[i-1][j-wt[i-1]]);
                }
            }
        
        return v[n][w];
    }
};