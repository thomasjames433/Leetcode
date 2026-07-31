class Solution {
public:
    string longestPalindrome(string s) {
        int max=1;
        string ret;
        ret.push_back(s[0]);
        for(int i=0;i<s.length();i++){
            checkfromcenter( s,i, i,ret,max);
            checkfromcenter( s,i, i+1,ret,max);
        }
        return ret;
    }

    void checkfromcenter(const string s,int c1, int c2, string &ret, int &max){
        while(c1>=0 && c2<s.length() && s[c1]==s[c2]){
            c1--;
            c2++;
            true;
        }
        c1++;c2--;
        if(c2-c1+1>max){
            max=c2-c1+1;
            ret=s.substr(c1,c2-c1+1);
        }
        return;
    }
};


// Same Method diff writing

class Solution {
public:
    string longestPalindrome(string s) {
        string maxstr=s.substr(0,1);
        for (int i=0;i<s.size();i++){
            int a =i-1;
            int b= i+1;
            while(a>=0 && b<s.size() && s[a]==s[b]){
                a--;
                b++;
            }
            if(b-a-1>maxstr.size())
                maxstr=s.substr(a+1,b-a-1);
            
            a =i;
            b= i+1;
            while(a>=0 && b<s.size() && s[a]==s[b]){
                a--;
                b++;
            }
            if(b-a-1>maxstr.size())
                maxstr=s.substr(a+1,b-a-1);
        }
        return maxstr;
    }

};