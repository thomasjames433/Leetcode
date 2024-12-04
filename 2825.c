bool canMakeSubsequence(char* str1, char* str2) {
    int n=strlen(str1);
    int m=strlen(str2);
    int c=0;
    for(int i=0;i<n;i++){
        if(str1[i]==str2[c] || str1[i]+1==str2[c] || (str1[i]=='z' && str2[c]=='a')){
            c++;
            if(c==m)
                return 1;
        }
    }
    return 0;
}