char* compressedString(char* s) {
    int n=strlen(s);
    char *ret=(char*)calloc(2*n+1,sizeof(char));
    if(n==1){
        ret[0]='1';
        ret[1]=s[0];
        ret[2]='\0';
        return ret;
    }
    
    int m=0;int i;
    for(i=0;i<n-1;i++){
        printf("%d ",i);
        int j=1;
        while(i+j<n && s[i+j-1]==s[i+j]){
            j++;
            if(j==9)
                break;   
            
        }

        ret[m++]=j+'0';
        ret[m++]=s[i];
        ret[m]='\0';
        i+=j-1;
    }
    if(i<n && (s[n-2]!=s[n-1] || ret[m-2]=='9')){
        ret[m++]='1';
        ret[m++]=s[n-1];
    }
    ret[m]='\0';
    return ret;
}