class Solution {
    public:
      int nthRoot(int n, int m) {
          vector<pair<int,int>>v;
          int i=2;
          
          while(i<=m){
              int x=0;
              while(! (m%i)){
                  x++;
                  m/=i;
              }
              if(x)
                  v.push_back({i,x});
              i++;
              
          }
          
          for(auto & it:v){
              
              if (it.second%n)
                  return -1;
              else
                  it.second/=n;
          
              
          }
          int x=1;
          for (auto it:v){
              x*= pow(it.first,it.second);
          }
          return x;
          
      }
  };