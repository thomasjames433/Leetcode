class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1)
            return -1;

        queue<pair<int,int>>q;
        q.push({0,0});
        vector<vector<bool>>visited(n,vector<bool>(n,0));
        visited[0][0]=1;
        int dist=0;
        int count=1;
        while(!q.empty()){
                
            auto it=q.front();
            q.pop();
            int x=it.first;
            int y=it.second;
            if(x==n-1 && y==n-1)
                return dist+1;
            
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    if(isvalid(x+i,y+j,n) && !visited[x+i][y+j] && grid[x+i][y+j]==0){
                        q.push({x+i,y+j});
                        visited[x+i][y+j]=1;
                   
                    }
                }
            }
            count --;

            if(count==0){
                count=q.size();
                dist++;
            }
        }
        return -1;
    }
    bool isvalid(int x,int y, int n){
        if(x>=0 && x<n && y>=0 && y<n)
            return 1;
        return 0;
    }
};