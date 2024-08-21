int strStr(char* haystack, char* needle) {
    int a=strlen(needle);int b=strlen(haystack);
    if(a>b)
        return -1;
    int i=0;
    while(i<=b-a){
        for(int j=0;j<a;j++){
            if(haystack[i+j]!=needle[j])
                break;
            if(j==a-1)
                return i;
        }
        i++;
    }
    return -1;
}