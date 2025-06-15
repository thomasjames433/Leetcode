class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<int>row(n,0);
        vector<int>column(n,0);
        vector<int>diag1(2*n-1,0);
        vector<int>diag2(2*n-1,0);
        vector<vector<string>> ret;
        vector<string> temp;
        dfs(ret,temp,row,column,diag1,diag2,0,n);
        return ret;

    }

    void dfs(vector<vector<string>> &ret,vector<string>&temp,vector<int>&row,vector<int>&column,vector<int>&diag1,vector<int>&diag2,int rowcount,int n){
        if(rowcount==n){
            ret.push_back(temp);
            return;
        }

        for(int i=0;i<n;i++){
            if(!row[rowcount] && !column[i] && ! diag1[n-1 + i-rowcount] && ! diag2[i+rowcount]){
                row[rowcount]=1;
                column[i]=1;
                diag1[n-1+ i-rowcount]=1;
                diag2[i+rowcount]=1;
                string s(n,'.');
                s[i]='Q';
                temp.push_back(s);
                dfs(ret,temp,row,column,diag1,diag2,rowcount+1,n);
                row[rowcount]=0;
                column[i]=0;
                diag1[n-1+ i-rowcount]=0;
                diag2[i+rowcount]=0;
                temp.erase(temp.end()-1,temp.end());
            }
        }
    }
};