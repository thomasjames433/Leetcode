class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        int m=text1.size();
        int n=text2.size();

        vector<vector<int>>v(n+1,vector<int>(m+1,0));
        for(int i=1;i<n+1;i++){

            for(int j=1;j<m+1;j++){

                if(text1[j-1]==text2[i-1]){
                    v[i][j]=1+v[i-1][j-1];
                }
                else{
                    v[i][j]=max(v[i-1][j],v[i][j-1]);
                }
            }
        }
        return v[n][m];
    }
};