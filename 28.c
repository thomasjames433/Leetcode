int max(int a,int b){
    if(a>b)
        return a;
    return b;
}

int strStr(char* haystack, char* needle) {
    int n=strlen(needle);
    int *num=(int *)malloc(125*sizeof(int));
    for(int i=0;i<125;i++)
        num[i]=n;  
    for(int i=0;i<n;i++)
        num[needle[i]]=max(1,n-i-1);
    for(int i=n-1;i<strlen(haystack);i++){
        int j=0;
        while(j<n && haystack[i-j]==needle[n-j-1]){
            j++;
            if(j==n)
                return i-n+1;
        }
        i+=num[haystack[i]]-1;
    }
    return -1;
}