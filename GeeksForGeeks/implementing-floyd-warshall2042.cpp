// User function template for C++


// To see if negative cycles, dist[i][i] would be <0 at the end

// if(dist[i][j]> dist[i][via]+dist[via][j] Alone is not enoguh, since of one of the latter part is a -ve number reduces it to 9999999...

class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        // Code here
        int v=dist.size();
        
        for(int via=0;via<v;via++){
            
            for(int i=0;i<v;i++){
                for(int j=0;j<v;j++){
                    
                    if(dist[i][j]> dist[i][via]+dist[via][j] && dist[i][via]!=100000000 && dist[via][j]!=100000000)
                        dist[i][j]= dist[i][via]+dist[via][j];
                    // if(dist[i][j]> dist[i][via]+dist[via][j] Alone is not enoguh, since of one of the latter part is a -ve number reduces it to 9999999...
                }
            }
        }
        return;
    }
};