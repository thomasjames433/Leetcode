class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        vector<vector<int>>v((n+1),vector<int>(m+1,INT_MAX));
        for(int i=0;i<n+1;i++)
            v[i][0]=i;
        
        for(int i=0;i<m+1;i++)
            v[0][i]=i;
        
        for(int i=1;i<n+1;i++){

            for(int j=1;j<m+1;j++){
                if(word1[j-1]==word2[i-1]){
                    v[i][j]=v[i-1][j-1];
                }
                else{
                    v[i][j]=1+min(v[i-1][j],min(v[i-1][j-1],v[i][j-1]));
                }
            }
        }
        return v[n][m];
    }
};