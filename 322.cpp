class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0)
            return 0;
        int n=coins.size();
        vector<vector<int>>v(n+1,vector<int>(amount+1,100000));
        for(int i=0;i<=n;i++)
            v[i][0]=0;
        for(int i=1;i<=n;i++){
            
            for(int j=1;j<=amount;j++){
                if(j<coins[i-1])
                    v[i][j]=v[i-1][j];
                else{
                    
                       v[i][j]= min(v[i-1][j],1+v[i][j-coins[i-1]]);
                }

            }
        }
        if (v[n][amount]==100000)
            return -1;
        return v[n][amount];
    }
};