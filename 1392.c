char* longestPrefix(char* s) {
    int n=strlen(s);
    int *num=(int *)calloc(n,sizeof(int*));
    int mark=0;
    for(int i=1;i<n;i++){
        if(s[i]==s[mark]){
            num[i]=++mark;
        }
        else if(mark>0){
            mark=num[mark-1];
            i--;
        }
        else
            num[i]=0;
    }
    s[mark]='\0';
    return s;
}