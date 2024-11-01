char* makeFancyString(char* s) {
    int n=strlen(s);
    char *ret=(char*)malloc((n+1)*sizeof(char));
    int x=0;int r=0;
    for(int i=0;i<n-1;i++){
        if(x<2){
            ret[r++]=s[i];
        }
        if(s[i]==s[i+1])
            x++;
        else
            x=0;
    }
    if(r>1){
        if(s[n-1]==ret[r-1] && s[n-1]==ret[r-2]){
            ret[r++]='\0';
            return ret;
        }
    }
    ret[r++]=s[n-1];
    ret[r++]='\0';
    return ret;
}