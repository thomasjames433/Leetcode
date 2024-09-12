

int countConsistentStrings(char * allowed, char ** word, int wordsize){
    char A[26];
    int len=strlen(allowed);
    
    for(int i=0;i<26;i++){
        A[i]='0';
    }
    for(int i=0;i<len;i++){
        A[allowed[i]-'a']='1';
    }
    int x=0;
    for(int i=0;i<wordsize;i++){
        len=strlen(word[i]);
        for(int j=0;j<len;j++){
            if(A[word[i][j]-'a']=='0'){
                x--;
                break;
            }
        }
        x++;
    }
    return x;
}