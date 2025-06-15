class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ret;
        vector<string>temp;
        check(ret,0,s,temp);
        return ret;
    }

private:
    void check(vector<vector<string>> &ret, int start, string s,vector<string>&temp){

        if(start==s.length()){
            ret.push_back(temp);
        }

        else{
            for(int end=start;end<s.length();end++){
                if(ispalindrome(s,start,end)){
                    temp.push_back(s.substr(start,end-start+1));
                    check(ret,end+1,s,temp);
                    temp.pop_back();
                }
            }

        }
    }

    bool ispalindrome(string s, int start,int end){
        while(start<end){
            if(s[start++]!=s[end--])
                return false;
        }
        return true;
    }
};