class Solution {
public:
    bool checkValidString(string s) {
        int low=0;
        int high=0;

        for(int i=0;i<s.size();i++){
            if(s[i]=='*'){
                low--;
                high++;
            }
            if(s[i]=='('){
                high++;
                low++;
            }
            if(s[i]==')'){
                high--;
                low--;
            }
            if(high<0)
                return 0;
            if(low<0)
                low=0;
        }
        return (low==0);

    }
};