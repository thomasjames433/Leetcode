class Solution {
  public:
    int celebrity(vector<vector<int> >& mat) {
        // code here
        int n=mat.size();
        map<int,int>mpp;
        for(int i=0;i<n;i++){
            if(mat[0][i])
                mpp.insert({i,1});
        }
        for(int i=1;i<n;i++){
            
            for(auto it: mpp){
                if(mat[i][it.first]){
                    it.second++;
                }
                else{
                    mpp.erase(it.first);
                }
            }
        }
        if(mpp.size()>1 || mpp.size()==0)
            return -1;
        auto it =mpp.begin();
        int x= it->first;
        for(int i=0;i<n;i++){
            if(i!=x && mat[x][i])
                return -1;
        }
        return x;
    }
};