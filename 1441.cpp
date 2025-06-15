class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string>s;
        int x=0;
        for(int i=1;i<=n;i++){
            s.push_back("Push");    
            if(target[x]!=i){
                s.push_back("Pop");
            }
            else{
                x++;
            }
            if(x==target.size())
                return s;
        }
        return s;
    }
};