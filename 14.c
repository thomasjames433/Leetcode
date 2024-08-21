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