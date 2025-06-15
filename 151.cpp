class Solution {
public:
    string reverseWords(string s) {
        
        string ret;
        int len=s.size();
        int end=len-1;
        for(int i=len;i>=0;i--){
            while(i>-1 && s[i]!=' ')
                i--;
            if(i==end){
                end--;
            }
            else{
                ret+= s.substr(i+1,end-i);
                ret+=' ';
                end=i-1;
            }
        }
        if(ret[ret.size()-1]==' ')
            ret.pop_back();
        return ret;
    }
};

char *reverse(char *a,int x,int y){
    char *new=(char*)malloc((y-x+1)*sizeof(char));
    int i=0;int j=y-1;
    while(x<=j){
        new[i++]=a[j--];
    }
    new[i]='\0';
    return new;
}

char* reverseWords(char* s) {
    int len=strlen(s);
    char *new=(char*)malloc((len+2)*sizeof(char));
    new[0]='\0';
    int i=0;
    while(i<len){
        while(i<len && s[i]==' ')
            i++;
        int j=i;
        if(i==len)
            break;
        while(j<len && s[j]!=' ')
            j++;
        char *a=reverse(s,i,j);
        strcat(new,a);
        strcat(new," ");
        i=j;
    }    
    new[strlen(new)-1]='\0';
    new=reverse(new,0,strlen(new));
    return new;
}