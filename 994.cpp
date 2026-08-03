class Solution {

private:
    void rotOrange(queue<pair<int,int>>&q,vector<vector<int>>&grid,int i,int j,int & cur){
        if(i>0){
            if(grid[i-1][j]==1){
                grid[i-1][j]=2;
                cur++;
                q.push({i-1,j});
            }
        }
        if(i<grid.size()-1){
            if(grid[i+1][j]==1){
                grid[i+1][j]=2;
                cur++;
                q.push({i+1,j});
            }
        }
        if(j>0){
            if(grid[i][j-1]==1){
                grid[i][j-1]=2;
                cur++;
                q.push({i,j-1});
            }
        }
        if(j<grid[0].size()-1){
            if(grid[i][j+1]==1){
                grid[i][j+1]=2;
                cur++;
                q.push({i,j+1});
            }
        }
    }

public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int min=-1;
        int cur=0;
        int count=0;
        bool hasfresh=0;
        for(int i=0;i<grid.size();i++){
            for (int j=0;j<grid[0].size();j++){
                if (grid[i][j]==2){
                    q.push({i,j});
                    cur++;
                }
                if (grid[i][j]==1)
                    hasfresh=1;

            }
        }
        if (!hasfresh)
            return 0;
        
        count=cur;
        cur=0;
        while( ! q.empty()){
            auto point=q.front();
            q.pop();
            count --;
            rotOrange(q,grid,point.first,point.second,cur);
            if(count==0){
                min++;
                count=cur;
                cur=0;
            }
        }

        for(int i=0;i<grid.size();i++){
            for (int j=0;j<grid[0].size();j++){
                if (grid[i][j]==1){
                    return -1;
                }
            }
        }
        return min;
    }
};