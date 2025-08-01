class Solution {
public:
    bool checkValidString(string s) {
        int low=0;
        int high=0;
        for(auto it:s){
            if(it=='('){
                low++;
                high++;
            }
            else if(it==')'){
                low=max(low-1,0);
                high--;
                if(high<0)
                    return 0;
            }
            else{
                low=max(low-1,0);
                high++;
            }
        }
        return low==0;
    }
};