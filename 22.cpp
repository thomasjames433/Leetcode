class Solution {
public:

    void makepar(vector<string>&ret,string curstr,int open, int close){
        if(open==0&&close==0){
            ret.push_back(curstr);
            return;
        }
        if(open>0)
            makepar(ret,curstr+'(',open-1,close);
        if(open<close)
            makepar(ret,curstr+')',open,close-1);
    }

    vector<string> generateParenthesis(int n) {
        vector<string>ret={};
        makepar(ret,"",n,n);
        return ret;
    }
};