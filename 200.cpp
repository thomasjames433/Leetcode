class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>visited(m,vector<int>(n,0));
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' && visited[i][j]==0){
                    dfs(grid,visited,i,j,m,n);
                    count++;
                }
            }
        }
        return count;
    }
    void dfs(vector<vector<char>>& grid,vector<vector<int>>& visited,int i, int j, int m, int n){
        visited[i][j]=1;
        if(i>0 && visited[i-1][j]==0 && grid[i-1][j]=='1'){
            dfs(grid,visited,i-1,j,m,n);
        }

        if(i<m-1 && visited[i+1][j]==0 && grid[i+1][j]=='1'){
            dfs(grid,visited,i+1,j,m,n);
        }
        
        if(j>0 && visited[i][j-1]==0 && grid[i][j-1]=='1'){
            dfs(grid,visited,i,j-1,m,n);
        }

        if(j<n-1 && visited[i][j+1]==0 && grid[i][j+1]=='1'){
            dfs(grid,visited,i,j+1,m,n);
        }
    }
};