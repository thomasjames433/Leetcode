class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());        
        int count=0;
        string x= strs[0];
        string y=strs[strs.size()-1];
        while(count<x.size() && count<y.size() &&x[count]==y[count])
            count++;
        return x.substr(0,count);
    }
};


char* longestCommonPrefix(char** s, int strsize) {
    if(strsize==1)
        return s[0];
    char *str=(char *)malloc(300*sizeof(char));
    int j=0;
    while(1){
        for(int i=0;i<strsize-1;i++){
            if(s[i][j]=='\0' || s[i][j]!=s[i+1][j]){
                str[j]='\0';
                return str;
            }
            if(i==strsize-2){
                str[j]=s[0][j];
                j++;        
            }    
        }
    }
    return str;
}