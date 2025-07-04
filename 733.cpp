#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int initial=image[sr][sc];
        if(initial==color)
            return image;
        int m=image.size();
        int n=image[0].size();
        queue<pair<int,int>>q;
        q.push({sr,sc});
        image[sr][sc]=color;
        while(!q.empty()){
            auto it=q.front();
            int x=it.first;
            int y=it.second;

            q.pop();
            if(x>0 && image[x-1][y]==initial){
                image[x-1][y]=color;
                q.push({x-1,y});
            }
            if(x<m-1 && image[x+1][y]==initial){
                image[x+1][y]=color;
                q.push({x+1,y});
            }
            if(y>0 && image[x][y-1]==initial){
                image[x][y-1]=color;
                q.push({x,y-1});
            }
            if(y<n-1 && image[x][y+1]==initial){
                image[x][y+1]=color;
                q.push({x,y+1});
            }
            
        }
        return image;
    }
};

int main(){
    int m,n;
    cin>> m>>n;
    vector<vector<int>>v(m,vector<int>(n,-1));
    for(int i=0;i<m;i++){
        for (int j=0;j<n;j++)
            cin>>v[i][j];     
    }
    cout<< "5";
    int c;
    cin>>c;
    Solution sol;
    auto newv=sol.floodFill(v,0,0,c);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++){
            cout << newv[i][j] << " ";}
        cout << "\n";  // ✅ Ensures each row is on a new line
    }

    return 0;
}